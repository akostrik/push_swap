/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:46:18 by akostrik          #+#    #+#             */
/*   Updated: 2023/04/06 14:13:01 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_conversion(const char *s)
{
	if (!ft_strncmp(s, "%s", 2))
		return (1);
	else if (!ft_strncmp(s, "%c", 2))
		return (1);
	else if (!ft_strncmp(s, "%p", 2))
		return (1);
	else if (!ft_strncmp(s, "%d", 2) || !ft_strncmp(s, "%i", 2))
		return (1);
	else if (!ft_strncmp(s, "%u", 2))
		return (1);
	else if (!ft_strncmp(s, "%x", 2) || !ft_strncmp(s, "%X", 2))
		return (1);
	else if (!ft_strncmp(s, "%%", 2))
		return (1);
	return (0);
}

static ssize_t	put_conversion(const char *s, va_list	ls_arg, int fd)
{
	if (!ft_strncmp(s, "%s", 2))
		return (ft_putstr_fd(va_arg(ls_arg, char *), fd));
	if (!ft_strncmp(s, "%c", 2))
		return (ft_putchar_fd(va_arg(ls_arg, int), fd));
	if (!ft_strncmp(s, "%p", 2))
		return (ft_put_pointer_fd(va_arg(ls_arg, void *), fd));
	if (!ft_strncmp(s, "%d", 2) || !ft_strncmp(s, "%i", 2))
		return (ft_putnbr_base_10_fd(va_arg(ls_arg, int), fd));
	if (!ft_strncmp(s, "%u", 2))
		return (ft_put_uns_long_fd(va_arg(ls_arg, unsigned int), 10, 1, fd));
	if (!ft_strncmp(s, "%x", 2) || !ft_strncmp(s, "%X", 2))
		return (ft_put_uns_long_fd(va_arg(ls_arg, unsigned int), 16, s[1], fd));
	if (!ft_strncmp(s, "%%", 2))
		return (ft_putchar_fd('%', fd));
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	ssize_t	ret;
	va_list	list_args;
	int		fd;

	fd = 1;
	va_start(list_args, s);
	i = 0;
	ret = 0;
	while (i < ft_strlen((char *)s))
	{
		if (is_conversion(&s[i]) == 1)
		{
			ret += put_conversion(&s[i], list_args, fd);
			i++;
		}
		else
			ret += ft_putchar_fd(s[i], fd);
		i++;
	}
	va_end(list_args);
	return ((int)ret);
}
