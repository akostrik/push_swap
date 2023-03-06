/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:24:00 by akostrik          #+#    #+#             */
/*   Updated: 2023/02/22 10:58:01 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

typedef struct s_buf
{
	ssize_t			b;
	ssize_t			e;
	ssize_t			nl;
	char			*s;
	struct s_buf	*nxt;
	struct s_buf	*prv;
}	t_buf;

void	*free_l_and_return_null(t_buf ***l);
void	fill_buf_and_add_to_l(t_buf *new, t_buf **l, ssize_t nb_bts);
ssize_t	read_buf_and_add_to_l(int fd, t_buf **l);
void	concat_update(t_buf **l, t_buf	*b, char *s, size_t *i_s);
char	*concat_buffers_and_update_lst(t_buf **l);

#endif
