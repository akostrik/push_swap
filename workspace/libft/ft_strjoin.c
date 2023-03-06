/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:50:57 by akostrik          #+#    #+#             */
/*   Updated: 2023/02/16 16:19:05 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s1: La chaîne de caractères préfixe
// s2: La chaîne de caractères suffixe
// Returns La nouvelle chaîne de caractères, NULL si l’allocation échoue
// fonctions autorisées : malloc
// Alloue (avec malloc(3)) et retourne une nouvelle chaîne, résultat de
// la concaténation de s1 et s2

// 1.OK 2.MOK 3.OK 4.MOK 5.OK 6.MOK 7.OK 8.MOK
// char * s = ft_strjoin("tripouille", "42");
// 1) check(!strcmp(s, "tripouille42"));
// 2) mcheck(s, strlen("tripouille") + strlen("42") + 1); free(s); showLeaks();
// s = ft_strjoin("", "42");
// 3) check(!strcmp(s, "42"));
// 4) mcheck(s, strlen("") + strlen("42") + 1); free(s); showLeaks();
// s = ft_strjoin("42", "");
// 5) check(!strcmp(s, "42"));
// 6) mcheck(s, strlen("42") + strlen("") + 1); free(s); showLeaks();
// s = ft_strjoin("", "");
// 7) check(!strcmp(s, ""));
// 8) mcheck(s, strlen("") + strlen("") + 1); free(s); showLeaks();

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*new_string;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_string = (char *)malloc(s1_len + s2_len + 1);
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		new_string[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		new_string[s1_len + i] = s2[i];
		i++;
	}
	new_string[s1_len + i] = '\0';
	return (new_string);
}
