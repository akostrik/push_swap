/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 15:30:09 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Copies n bytes from memory area src to memory area dest
// src and dest may overlap:
// the bytes in src are first copied into a tmp array that does not
// overlap src or dest, and the bytes are then copied from the tmp array to dest
// Returns a pointer to dest
//ft_memmove      : 1.OK 2.OK 3.OK 4.OK

#include "libft.h"

static int	src0_inside_dest(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 1;
	while (i < n)
	{
		if ((const void *)dest == src + i)
			return (1);
		i++;
	}
	return (0);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (src0_inside_dest(dest, src, n) == 1)
	{
		i = n - 1;
		while (1)
		{
			*((char *)dest + i) = *((char *)src + i);
			if (i == 0)
				break ;
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			*((char *)dest + i) = *((char *)src + i);
			i++;
		}
	}
	return (dest);
}
