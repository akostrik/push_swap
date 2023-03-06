/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:46:18 by akostrik          #+#    #+#             */
/*   Updated: 2023/02/16 16:32:22 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Repeated calls to get_next_line() let the text file fd, one line at a time
// Returns the line read / NULL nothing to read / NULL error
// A new line -> return the current line
// get_next_line() reads as little as possible each time 
// compiler -D BUFFER_SIZE=n, macro définie à l’invocation du compilateur

#include "libft.h"

char	*ft_get_next_line(int fd)
{
	static t_buf	**l = NULL;
	char			*s;

	if (BUFFER_SIZE < 1)
		return (NULL);
	if (fd < 0)
		return (NULL);
	if (l == NULL)
	{
		l = (t_buf **)malloc(sizeof(t_buf *));
		if (l == NULL)
			return (NULL);
		*l = NULL;
	}
	while (*l == NULL || ((*l)->nl > (*l)->e && (*l)->s[(*l)->e] != EOF))
		if (read_buf_and_add_to_l(fd, l) == -1)
			return (free_l_and_return_null(&l));
	s = concat_buffers_and_update_lst(l);
	if (s == NULL)
		return (free_l_and_return_null(&l));
	if (*l != NULL && (*l)->b == (*l)->e && (*l)->s[(*l)->e] == EOF)
		free_l_and_return_null(&l);
	return (s);
}
