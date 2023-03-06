/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/26 18:23:04 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Concatenate dst + src
// Appends at most n-strlen(dst)-1 bytes
// NUL-terminates the result as long as there is at least 1 byte free in dst
// A byte for the NUL should be included in n
// Takes the full size of the buffer (not just the length)
// src and dst must be NUL-terminated (true “C” strings)
// Returns the total length of the string it tried to create =
// the initial dst-length + src-length (=> truncation detection simple)
// Replacements for strncat (more consistent, and less error prone)
// возвращает суммарную длину строк по адресам src и dst
// Возвращаемое значение не зависит от того, удалось ли скопировать строку
// полностью => определить что буфер назначения мал для копируемой строки

#include "libft.h"

static size_t	nb_chars_without_0(size_t dst_init_len, size_t	src_len, \
size_t n)
{
	if (dst_init_len + src_len + 1 <= n)
		return (src_len);
	if (dst_init_len + 1 < n)
		return (n - dst_init_len - 1);
	return (0);
}

static size_t	return_value(size_t dst_init_len, size_t	src_len, size_t n)
{
	if (dst_init_len <= n)
		return (dst_init_len + src_len);
	return (src_len + n);
}

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	nb_chars_to_append;
	size_t	dst_init_len;

	dst_init_len = ft_strlen(dst);
	nb_chars_to_append = nb_chars_without_0(dst_init_len, ft_strlen(src), n);
	i = 0;
	while (i < nb_chars_to_append)
	{
		dst[dst_init_len + i] = src[i];
		i++;
	}
	dst[dst_init_len + i] = '\0';
	return (return_value(dst_init_len, ft_strlen(src), n));
}
