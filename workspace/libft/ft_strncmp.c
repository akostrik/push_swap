/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:15:02 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 17:57:55 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Compares the first (at most) n bytes of s1 and s2
// Returns an integer indicating the result of the comparison:
// • 0, if the s1 and s2 are equal;
// • a negative value if s1 is less than s2;
// • a positive value if s1 is greater than s2.
// The locale is not taken into account
// The comparison is done using unsigned characters
// POSIX: the sign of a nonzero return value shall be determined by the sign of
// the difference between the values of the first pair of bytes (both
// interpreted as type unsigned char) that differ in the strings being compared
// Glibc: return = the last compared byte in s1 - the last compared byte in s2

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)*p1 != (unsigned char)*p2)
			return ((unsigned char)*p1 - (unsigned char)*p2);
		if (*p1 == '\0')
			return (0);
		p1++;
		p2++;
		i++;
	}
	return (0);
}
