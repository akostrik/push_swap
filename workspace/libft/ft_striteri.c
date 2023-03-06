/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:43:27 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 18:27:35 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s: La chaîne de caractères sur laquelle itérer
// f: La fonction à appliquer à chaque caractère
// Aucune fonctions externe
// Applique f à chaque caractère de s et en passant son index comme 1er arg
// Chaque caractère est transmis par adresse à ’f’ afin d’être modifié si 
// nécessaire

// 1.OK 2.OK 3.OK 

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		f((unsigned int)i, s + i);
		i++;
	}
}
