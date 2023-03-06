/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 15:33:00 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  l'ensemble des caractères ASCII, exceptés les caractères de contrôles 
// 0–8		control codes (NUL, etc.)
// 9		\t
// 10–13	whitespaces \n \v \f \r
// 14–31	control codes
// 127		backspace character (DEL)
// ft_isprint      : 1.OK 2.OK 3.OK 4.OK 

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
