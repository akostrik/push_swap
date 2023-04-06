/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:57:16 by akostrik          #+#    #+#             */
/*   Updated: 2023/04/06 14:08:43 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
0:   0
1:   0
2:   0
3:   5
4:   6
6:   20
7:   33
8:   0
12:  76
13:  82
14:  87
15:  92
16:  96
17:  137
18:  145
31:  235
32:  240
33:  315
48:  448
64:  576
99:  1074
100: 1084
101: 1095
500: 6784
501: 6761
*/

#include "push_swap.h"

int static	error(t_two_stacks **ab)
{
	free_memory(ab);
	write(2, "Error\n", ft_strlen("Error\n"));
	return (0);
}

int	main(int argc, char **argv)
{
	t_two_stacks	*ab;

	if (argc == 1)
		exit (0);
	ab = (t_two_stacks *)malloc(sizeof(t_two_stacks));
	if (ab == NULL)
		return (error(&ab));
	ab->a = (t_stk **)malloc(sizeof(t_stk *));
	if (ab->a == NULL)
		return (error(&ab));
	*(ab->a) = NULL;
	ab->b = (t_stk **)malloc(sizeof(t_stk *));
	if (ab->b == NULL)
		return (error(&ab));
	*(ab->b) = NULL;
	if (put_args(ab, argc, argv) == -1)
		return (error(&ab));
	radix_sort(ab);
	free_memory(&ab);
	return (0);
}
