/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/18 15:32:00 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// isalpha - макрокоманда, почему?
// определена только если isascii(c) равно true или c = EOF
// доступна в UNIX, поддерживается стандартом ANSI C
// 	return (((unsigned)c | 32) - 'a' < 26);
// tester ft_isalpha      : 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
