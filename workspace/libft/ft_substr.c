/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:08:08 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/21 18:35:24 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s: La chaîne de laquelle extraire la nouvelle chaîne
// start: L’index de début de la nouvelle chaîne dans la chaîne s
// len: La taille maximale de la nouvelle chaîne
// Retourne la nouvelle chaîne de caractères, NULL si l’allocation échoue
// Fonctions autorisées : malloc
// Alloue (avec malloc(3)) et retourne une chaîne de caractères issue de’s’
// La nouvelle chaîne commence à l’index ’start’ et a pour taille maximale ’len’

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (start >= ft_strlen(s))
	{
		substr = (char *)malloc(1);
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = (char *)malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
