/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:57:16 by akostrik          #+#    #+#             */
/*   Updated: 2023/04/03 17:10:09 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	replace_by_smaller_numbers(ab);
	radix_sort(ab);
	free_memory(&ab);
	return (0);
}
