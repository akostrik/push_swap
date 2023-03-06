/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:45:44 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 18:27:09 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// n: L’entier à écrire.
// fd: Le descripteur de fichier sur lequel écrire
// fonctions autoirisées : write
// Écrit l’entier ’n’ sur le descripteur de fichier donné

// ft_putnbr_fd    : 1.OK 2.OK 3.OK 4.OK 5.OK 

#include "libft.h"

static void	ft_put_positiv_nbr_fd(int n, int fd)
{
	char	c;

	if (n == 0)
		return ;
	ft_put_positiv_nbr_fd(n / 10, fd);
	c = n - (n / 10) * 10 + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	ft_put_positiv_nbr_fd(n, fd);
}
