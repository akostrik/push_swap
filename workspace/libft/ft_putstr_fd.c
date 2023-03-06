/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:10:20 by akostrik          #+#    #+#             */
/*   Updated: 2023/02/22 10:52:24 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s: La chaîne de caractères à écrire.
// fd: Le descripteur de fichier sur lequel écrire.
// fonctions autorisées : write
// Écrit la chaîne de caractères ’s’ sur le descripteur de fichier donné.

//tester ft_putstr_fd    : 1.OK 

#include "libft.h"

ssize_t	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return (write(fd, "(null)", ft_strlen("(null)")));
	return (write(fd, s, ft_strlen(s)));
}
