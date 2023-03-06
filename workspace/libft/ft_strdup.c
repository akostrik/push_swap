/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/25 15:25:16 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Returns a pointer to a new string which is a duplicate of the string s
Memory for the new string is obtained with malloc(3), can be freed with free(3)
On success, returns a pointer to the duplicated string
Returns NULL if insufficient memory was available, errno = the cause of the error
ERRORS : ENOMEM Insufficient memory available to allocate duplicate string.

Le standard Unix98 réclame que malloc() remplisse errno = ENOMEM en cas d'échec
La glibc suppose qu'il en est ainsi. 
Si vous utilisez une implémentation personnelle de malloc() qui ne définit 
pas errno, certaines routines de bibliothèques peuvent échouer sans donner 
de raison dans errno.*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*res_str;

	res_str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (res_str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res_str[i] = s[i];
		i++;
	}
	res_str[i] = '\0';
	return (res_str);
}
