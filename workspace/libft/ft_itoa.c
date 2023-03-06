/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:51:51 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 18:23:48 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// n: l’entier à convertir
// Retournr la chaîne de caractères représentant l’entier
// Retourne NULL si l’allocation échoue
// fonctions authorisées : malloc
// Alloue (avec malloc(3)) et retourne une chaîne de caractères représentant
// l’entier ’n’ reçu en argument
// Les nombres négatifs doivent être gérés

#include "libft.h"

static size_t	calculate_nb_bytes_with_0(int n)
{
	size_t	i;

	if (n == INT_MIN)
		return (12);
	if (n == 0)
		return (2);
	i = 0;
	if (n < 0)
	{
		i = 1;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

static char	*str_0(char *str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*str_int_min(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	size_t	nb_bytes;

	nb_bytes = calculate_nb_bytes_with_0(n);
	str = (char *)malloc(nb_bytes * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		return (str_0(str));
	if (n == INT_MIN)
		return (str_int_min(str));
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	i = nb_bytes - 2;
	while (n > 0)
	{
		str[i--] = n % 10 + '0';
		n = n / 10;
	}
	str[nb_bytes - 1] = '\0';
	return (str);
}
