/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:57:16 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/24 21:40:30 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int static	error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int apply_

int	main(int argc, char **argv)
{
	t_two_stacks	*ab;
	//int			nb_operations_radix;
	int			nb_operations_2_4_8;

	if (argc == 1)
		exit (0);
	ab = (t_two_stacks *)malloc(sizeof(t_two_stacks));
	if (ab == NULL)
		return (error());
	ab->a = (t_stk **)malloc(sizeof(t_stk *));
	if (ab->a == NULL)
		return (error());
	*(ab->a) = NULL;
	ab->b = (t_stk **)malloc(sizeof(t_stk *));
	if (ab->b == NULL || put_args(ab->a, argc, argv) == -1)
		return (error());
	*(ab->b) = NULL;
	ab->a_or_b = 'a';
	ab->inc_or_dec = 'd';
	ab->len = len_(ab->a);
	//radix_sort(ab, 1);
	//nb_operations_radix = radix_sort(ab, 0);
	//printf("nb_operations_radix %d\n", nb_operations_radix);
	//sort_2_4_8(ab, 1);
	nb_operations_2_4_8 = sort_2_4_8(ab, 0);
	printf("nb_operations_2_4_8 %d\n", nb_operations_2_4_8);
	free_stack(&(ab->a));
	free_stack(&(ab->b));
	free(ab);
	return (0);
}
