/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 15:31:00 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Compares the first n bytes (each interpreted as unsigned char) 
// of the areas s1 and s2
// Returns an integer less than, equal to, or greater than zero if the first 
// n bytes of s1 is found to be less than, to match, or be greater than the 
// first n bytes of s2
// For a nonzero return value, the sign is determined by the sign of the 
// difference between the first pair of bytes (interpreted as unsigned char)
// that differ in s1 and s2
// If n=0, returns 0
// Do not use memcmp() to compare security critical data, such as cryptographic 
// secrets, because the required CPU time depends on the number of equal bytes
// Instead, a function that performs comparisons in constant time is required
// tester ft_memcmp       : 1.OK 2.OK 3.OK 4.OK 5.OK 

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (1)
	{
		if (i >= n)
			return (0);
		if ((unsigned char)*p1 != (unsigned char)*p2)
			return ((unsigned char)*p1 - (unsigned char)*p2);
		p1++;
		p2++;
		i++;
	}
}
