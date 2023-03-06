/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_10_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:57:46 by akostrik          #+#    #+#             */
/*   Updated: 2023/02/22 11:02:54 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putnbr_base_10_fd(int n, int fd)
{
	ssize_t	ret;

	if (n == INT_MIN)
		return (ft_putstr_fd("-2147483648", 1));
	ret = 0;
	if (n < 0)
	{
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		n = -n;
		ret ++;
	}
	ret += ft_put_uns_long_fd((unsigned int)n, 10, 'x', fd);
	return (ret);
}
