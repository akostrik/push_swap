/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:09:54 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/21 16:12:09 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Locates the first occurrence of the null-terminated little in big
// Not more than n characters are searched
// Characters after ‘\0’ are not searched
// Is a FreeBSD specific API => should only be used when portability is not 
// a concern
// Returns a pointer to the first char of the first occurrence of little
// Returns NULL if little occurs nowhere in big
// Returns big if little is empty

#include "libft.h"

static int	little_is_here(const char *big, const char *little, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (little[i] == '\0')
			return (1);
		if (little[i] != big[i])
			return (0);
		i++;
	}
	if (little[i] == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < n)
	{
		if (ft_strlen(&big[i]) < ft_strlen(little))
			return (NULL);
		if (little_is_here(&big[i], little, n - i) == 1)
			return ((char *)(&big[i]));
		i++;
	}
	return (NULL);
}
