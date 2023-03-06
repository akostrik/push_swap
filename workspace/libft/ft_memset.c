/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 15:29:18 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fills the first n bytes of the memory pointed to by s with the const. byte c
// Returns a pointer to the memory area s.
// Третий аргумент = колво байт, а не элементов, не учитывая тип данных
// tester ft_memset       : 1.OK 2.OK 

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	if (s == NULL)
		return (NULL);
			i = 0;
	while (i < n)
	{
		*((char *)s + i) = (char)c;
		i++;
	}
	return (s);
}
