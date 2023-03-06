/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:04:02 by akostrik          #+#    #+#             */
/*   Updated: 2023/02/16 16:36:24 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_put_pointer_fd(void *p, int fd)
{
	ssize_t	ret1;
	ssize_t	ret2;

	if (p == NULL)
		return (ft_putstr_fd("(nil)", fd));
	ret1 = ft_putstr_fd("0x", fd);
	if (ret1 == -1)
		return (-1);
	ret2 = ft_put_uns_long_fd((unsigned long)(p), 16, 'x', fd);
	if (ret2 == -1)
		return (-1);
	return (ret1 + ret2);
}
