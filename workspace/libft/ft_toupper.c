/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:40:46 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 15:33:19 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// If c is a lowercase letter, returns its uppercase equivalent, if an 
// uppercase representation exists in the current locale, otherwise, returns c
// If c is neither an unsigned char value nor EOF, the behavior is undefined.
// The standards require that the argument c for these functions is either EOF 
// or a value that is representable in unsigned char
// If the argument c is char, it must be cast to unsigned char:
// char c;
// res = toupper((unsigned char) c);
// because char may be the equivalent signed char, in which case a byte where 
// the top bit is set would be sign exended when converting to int, yielding 
// a value that is outside the range of unsigned char.
// The details of what constitutes an uppercase or lowercase letter depend on 
// the locale. For example, the default C locale does not know about umlauts, 
// so no conversion is done for them
// tester ft_toupper      : 1.OK 2.OK 3.OK 4.OK 

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c + 'A' - 'a');
	return (c);
}
