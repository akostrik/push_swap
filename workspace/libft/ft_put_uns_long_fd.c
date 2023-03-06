/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uns_long_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:51:51 by akostrik          #+#    #+#             */
/*   Updated: 2023/02/22 10:57:02 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	pow_(unsigned long n, unsigned long k)
{
	unsigned int	i;
	unsigned long	res;

	i = 0;
	res = 1;
	while (i < k)
	{
		res *= n;
		i++;
	}
	return (res);
}

static int	calc_nb_digits(unsigned long n, size_t base)
{
	size_t	i;

	i = 0;
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

ssize_t	ft_put_uns_long_fd(unsigned long n, size_t base, char uppcase, int fd)
{
	unsigned long	auxiliary;
	ssize_t			ret;
	int				digit_as_int_10;
	char			digit_as_char;

	if (n == 0)
		return (ft_putchar_fd('0', fd));
	auxiliary = pow_(base, calc_nb_digits(n, base) - 1);
	ret = 0;
	while (auxiliary > 0)
	{
		digit_as_int_10 = n / auxiliary;
		digit_as_char = digit_as_int_10 % base + '0';
		if (digit_as_int_10 % base >= 10)
			digit_as_char = digit_as_int_10 % base - 10 + 'a';
		if (uppcase == 'X')
			digit_as_char = ft_toupper(digit_as_char);
		ret += ft_putchar_fd(digit_as_char, 1);
		n = n % auxiliary;
		auxiliary = auxiliary / base;
	}
	return (ret);
}
