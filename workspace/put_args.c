/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:02:44 by akostrik          #+#    #+#             */
/*   Updated: 2023/04/06 16:01:46 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	convert_one_number(const char *s, int *n)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
		if (!ft_isdigit(s[i]))
			return (-1);
	}
	while (s[i] == '0')
		i++;
	*n = 0;
	while (s[i] != '\0' && ft_iswhitespace(s[i]) != 1)
	{
		if (!ft_isdigit(s[i]) || (INT_MAX - s[i] + '0') / 10 < *n)
			return (-1);
		*n = *n * 10 + s[i++] - '0';
	}
	(*n) *= sign;
	return (i);
}

static int	convert_beginning_str_to_int(const char *s, int *n)
{
	size_t	i;
	ssize_t	slide;

	i = 0;
	while (ft_iswhitespace(s[i]) == 1)
		i++;
	if (s[i] == '\0')
		return (-2);
	if (ft_strncmp(&s[i], "-2147483648", 11) == 0)
	{
		*n = -2147483648;
		return ((int)i + 11);
	}
	slide = convert_one_number(&s[i], n);
	if (slide == -1)
		return (-1);
	i += slide;
	return ((int)i);
}

static int	parse_string(const char *s, t_two_stacks *ab)
{
	int	i;
	int	n;
	int	slide;

	i = 0;
	while (1)
	{
		slide = convert_beginning_str_to_int(&s[i], &n);
		if (slide == -1)
			return (-1);
		if (slide == -2)
			break ;
		if (put_int(n, ab->a) == -1)
			return (-1);
		*(ab->a) = (*(ab->a))->nxt;
		i += slide;
	}
	return (0);
}

static int	double_argumets(t_two_stacks *ab)
{
	t_stk	*cur1;
	t_stk	*cur2;

	if (ab->len <= 1)
		return (0);
	cur1 = *(ab->a);
	while (cur1 != (*(ab->a))->prv)
	{
		cur2 = cur1->nxt;
		while (cur2 != *(ab->a))
		{
			if (cur1->n == cur2->n && cur1 != cur2)
				return (1);
			cur2 = cur2->nxt;
		}
		cur1 = cur1->nxt;
	}
	return (0);
}

int	put_args(t_two_stacks *ab, int argc, char **argv)
{
	int	n;
	int	return_of_convert;

	if (argc == 2 && parse_string(argv[1], ab) == -1)
		return (-1);
	if (argc-- > 2)
	{
		while (argc > 0)
		{
			return_of_convert = convert_beginning_str_to_int(argv[argc--], &n);
			if (return_of_convert == -1)
				return (-1);
			else if (return_of_convert == -2)
				continue ;
			if (put_int(n, ab->a) == -1)
				return (-1);
		}
	}
	ab->len = len_(ab->a);
	if (double_argumets(ab) == 1)
		return (-1);
	return (0);
}
