/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_and_shorter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:57:42 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/28 16:09:43 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_max_from_a_to_b(t_two_stacks *ab, int print_operations)
{
	int		max;
	int		i;
	t_stk	*cur;

	max = (*(ab->a))->n;
	i = 0;
	cur = *(ab->a);
	while (i < len_(ab->a))
	{
		if (max < cur->n)
			max = cur->n;
		i++;
		cur = cur-> nxt;
	}
	while (1)
	{
		if ((*(ab->a))->n == max)
		{
			push(ab->a, ab->b, ab, 'b', print_operations);
			break ;
		}
		rotate(ab->a, ab, 'a', print_operations);
	}
}

static void	sort_three(t_stk	**a, char a_or_b, int print_operations)
{
	t_stk	*a2;
	t_stk	*a3;

	a2 = (*a)->nxt;
	a3 = a2->nxt;
	if (is_sorted(a))
		;
	else if (a3->n < a2->n && a3->n < (*a)->n)
	{
		if ((*a)->n > a2->n)
			swap(a, NULL, a_or_b, print_operations);
		reverse_rotate(a, NULL, a_or_b, print_operations);
	}
	else if (a2->n < (*a)->n && a2->n < a3->n)
	{
		if ((*a)->n < a3->n)
			swap(a, NULL, a_or_b, print_operations);
		else
			rotate(a, NULL, a_or_b,print_operations);
	}
	else
	{
		swap(a, NULL, a_or_b, print_operations);
		rotate(a, NULL, a_or_b, print_operations);
	}
}

static void	sort_four(t_two_stacks *ab, int print_operations)
{
	push_max_from_a_to_b(ab, print_operations);
	sort_three(ab->a, 'a', print_operations);
	push(ab->b, ab->a, ab, 'a', print_operations);
	rotate(ab->a, ab, 'a', print_operations);
}

static void	sort_five(t_two_stacks *ab, int print_operations)
{
	push_max_from_a_to_b(ab, print_operations);
	push_max_from_a_to_b(ab, print_operations);
	sort_three(ab->a, 'a', print_operations);
	push(ab->b, ab->a, ab, 'a', print_operations);
	rotate(ab->a, ab, 'a', print_operations);
	push(ab->b, ab->a, ab, 'a', print_operations);
	rotate(ab->a, ab, 'a', print_operations);
}

int	sort_5_and_shorter(t_two_stacks *ab, int print_operations)
{
	if (is_sorted(ab->a))
		;
	else if (len_(ab->a) == 2)
		swap(ab->a, ab, 'a', print_operations);
	else if (ab->len == 3)
		sort_three(ab->a, 'a',print_operations);
	else if (ab->len == 4)
		sort_four(ab, print_operations);
	else if (ab->len == 5)
		sort_five(ab, print_operations);
	return (0);
}
