/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   understand_arguments.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:02:44 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/06 16:06:19 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	convert_one_number(const char *s, int *n)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
		if (!ft_isdigit(s[i]))
			return (-1);
	}
	if (s[i] == '+')
		i++;
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

static int	parse_string(const char *s, t_stk	**a)
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
		if (put_int(n, a) == -1)
			return (-1);
		rotate(a, ' ');
		i += slide;
	}
	return (0);
}

static int	double_argumets(t_stk **a)
{
	t_stk	*cur1;
	t_stk	*cur2;

	if (a == NULL || *a == NULL)
		return (0);
	if (*a == (*a)->nxt)
		return (0);
	cur1 = *a;
	while (cur1 != (*a)->prv)
	{
		cur2 = cur1->nxt;
		while (cur2 != *a)
		{
			if (cur1->n == cur2->n && cur1 != cur2)
				return (1);
			cur2 = cur2->nxt;
		}
		cur1 = cur1->nxt;
	}
	return (0);
}

int	put_args(t_stk	**a, int argc, char **argv)
{
	int	n;

	if (argc == 2)
	{
		if (parse_string(argv[1], a) == -1)
			return (-1);
	}
	else
	{
		argc--;
		while (argc > 0)
		{
			if (convert_beginning_str_to_int(argv[argc--], &n) == -1)
				return (-1);
			if (put_int(n, a) == -1)
				return (-1);
		}
	}
	if (double_argumets(a) == 1)
		return (-1);
	return (0);
}
