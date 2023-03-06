/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 17:45:33 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns a pointer to the last occurrence of the character c in the string s
// or NULL if c is not found
// character = byte; the function doesn't work with wide / multibyte characters

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*to_return;

	if (c == '\0')
		return ((char *)&(s[ft_strlen(s)]));
	i = 0;
	to_return = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			to_return = ((char *)(&s[i]));
		i++;
	}
	return (to_return);
}
