/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:54:41 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 18:26:00 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s: La chaîne de caractères sur laquelle itérer
// f: La fonction à appliquer à chaque caractère
// Retourne la chaîne de caractères résultant des applications successives de f
// Retourne NULL si l’allocation échoue
// fonctions autorisées : malloc
// Applique la fonction ’f’ à chaque caractère de la chaîne de caractères 
// passée en argument pour créer
// une nouvelle chaîne de caractères (avec malloc(3)) résultant des applications
// successives de ’f’
// the second argument of f ???

// 1.OK 2.MOK 3.OK 4.MOK 
// char * s = ft_strmapi("1234", addOne);
// 1) !strcmp(s, "1357")
// 2) mcheck(s, strlen("1357") + 1); free(s);
// s = ft_strmapi("", addOne);
// 3) check(!strcmp(s, ""));
// 4) mcheck(s, strlen("") + 1); free(s); showLeaks();

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_string;
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	new_string = (char *)malloc(i + 1);
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
