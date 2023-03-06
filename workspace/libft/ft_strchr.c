/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 17:45:38 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns a pointer to the first occurrence of the character c in the string s
// "character" = "byte"; does not work with wide or multibyte characters
// Returns a pointer to the matched character or NULL if not found
// The terminating null byte is considered part of the string, so that if c 
// is specified as '\0', returns a pointer to the terminator

// tester ft_strchr       : 1.OK 2.OK 3.OK 4.OK 5.KO
// 	/* 5 */ check(ft_strchr(s, 't' + 256) == s); showLeaks();

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (c == '\0')
		return ((char *)&(s[ft_strlen(s)]));
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i++;
	}
	return (NULL);
}
