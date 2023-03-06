/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:12:27 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/21 18:50:37 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s1: La chaîne de caractères à trimmer
// set: Le set de référence de caractères à trimmer
// Retourns La chaîne de caractères trimmée, NULL si l’allocation échoue
// fonc. authorisées : malloc
// Alloue (avec malloc(3)) et retourne une copie de la chaîne ’s1’, sans les
// caractères spécifiés
// dans ’set’ au début et à la fin de la chaîne de caractères

#include "libft.h"

static size_t	to_trim(char c, char const *set)
{
	size_t	i;

	if (c == '\0')
		return (1);
	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	calc_new_str_start(char const *s1, char const *set)
{
	size_t	new_str_start;

	if (ft_strlen(set) == 0)
		return (0);
	new_str_start = 0;
	while (s1[new_str_start] != '\0' && to_trim(s1[new_str_start], set) == 1)
		new_str_start++;
	return (new_str_start);
}

static size_t	calc_new_str_end(char const *s1, char const *set)
{
	size_t	new_str_end;

	if (ft_strlen(set) == 0)
		return (ft_strlen(s1) - 1);
	new_str_end = ft_strlen(s1);
	while (new_str_end > 0 && to_trim(s1[new_str_end], set) == 1)
		new_str_end--;
	return (new_str_end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*new_str;
	size_t	new_str_start;
	size_t	new_str_end;
	size_t	new_str_len_with_0;

	new_str_start = calc_new_str_start(s1, set);
	new_str_end = calc_new_str_end(s1, set);
	new_str_len_with_0 = new_str_end - new_str_start + 2;
	if (new_str_start > new_str_end)
		new_str_len_with_0 = 1;
	if (new_str_start == 0 && new_str_end == 0)
		new_str_len_with_0 = 1;
	new_str = (char *)malloc(new_str_len_with_0);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < new_str_len_with_0 - 1)
	{
		new_str[i] = s1[new_str_start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
