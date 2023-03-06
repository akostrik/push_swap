/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:42:08 by akostrik          #+#    #+#             */
/*   Updated: 2023/02/16 16:32:40 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ssize_t	b  position of the first char
// ssize_t	e  position of the last char
// ssize_t	nl position of the first newline character

#include "libft.h"

void	*free_l_and_return_null(t_buf ***l)
{
	t_buf	*b;
	t_buf	*next;

	b = **l;
	while (b != NULL)
	{
		next = b -> nxt;
		free(b->s);
		free(b);
		b = next;
	}
	free(*l);
	*l = NULL;
	return (NULL);
}

void	fill_buf_and_add_to_l(t_buf *new, t_buf **l, ssize_t nb_bts)
{
	new->b = 0;
	new->e = nb_bts - 1;
	new->nl = new->b;
	while (new->nl <= new->e && new->s[new->nl] != '\n')
		(new->nl)++;
	if (nb_bts < BUFFER_SIZE)
	{
		new->e ++;
		new->s[nb_bts] = EOF;
	}
	new->prv = NULL;
	if (*l == NULL)
		new->nxt = NULL;
	else
	{
		new->nxt = *l;
		if (*l != NULL)
			(*l)->prv = new;
	}
	*l = new;
}

ssize_t	read_buf_and_add_to_l(int fd, t_buf **l)
{
	ssize_t	nb_bts;
	t_buf	*new;

	new = (t_buf *)malloc(sizeof(t_buf));
	if (new == NULL)
		return (-1);
	new->s = (char *)malloc(BUFFER_SIZE);
	if (new->s == NULL)
	{
		free(new);
		return (-1);
	}
	nb_bts = read(fd, new->s, BUFFER_SIZE);
	if (nb_bts == -1)
	{
		free(new->s);
		free(new);
		return (-1);
	}
	fill_buf_and_add_to_l(new, l, nb_bts);
	return (nb_bts);
}

void	concat_update(t_buf **l, t_buf	*b, char *s, size_t *i_s)
{
	t_buf	*del;
	ssize_t	i;

	while (b != NULL)
	{
		i = b->b;
		while (i <= b->nl && i <= b->e)
			s[(*i_s)++] = b->s[i++];
		b->b = b->nl + 1;
		b->nl = b->b;
		while (b->nl <= b->e && b->s[b->nl] != '\n')
			b->nl++;
		if (i <= b->e)
			break ;
		del = b;
		b = b->prv;
		*l = del->prv;
		free(del->s);
		free(del);
		if (b == NULL)
			break ;
		b->nxt = NULL;
	}
}

char	*concat_buffers_and_update_lst(t_buf **l)
{
	t_buf	*b;
	ssize_t	i;
	char	*s;
	size_t	i_s;

	if ((*l)->b == (*l)->e && (*l)->s[(*l)->e] == EOF && (*l)->nxt == NULL)
		return (NULL);
	i = 0;
	b = *l;
	while (b != NULL && b -> nxt != NULL)
	{
		i += b -> nl - b -> b;
		b = b -> nxt;
	}
	s = (char *)malloc(i + b -> nl - b -> b + 2);
	if (s == NULL)
		return (NULL);
	i_s = 0;
	concat_update(l, b, s, &i_s);
	if (i_s == 0)
		return (NULL);
	s[i_s] = '\0';
	if (s[i_s - 1] == EOF)
		s[i_s - 1] = '\0';
	return (s);
}
