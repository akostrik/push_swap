/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_and_shorter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:57:42 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/03 19:36:10 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_max_from_a_to_b(t_two_stacks *ab)
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
			push(ab->a, ab->b, 'b');
			break ;
		}
		rotate(ab->a, 'a');
	}
}

static void	sort_three(t_stk	**a, char a_or_b)
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
			swap(a, a_or_b);
		reverse_rotate(a, a_or_b);
	}
	else if (a2->n < (*a)->n && a2->n < a3->n)
	{
		if ((*a)->n < a3->n)
			swap(a, a_or_b);
		else
			rotate(a, a_or_b);
	}
	else
	{
		swap(a, a_or_b);
		rotate(a, a_or_b);
	}
}

static void	sort_four(t_two_stacks *ab)
{
	push_max_from_a_to_b(ab);
	sort_three(ab->a, 'a');
	push(ab->b, ab->a, 'a');
	rotate(ab->a, 'a');
}

static void	sort_five(t_two_stacks *ab)
{
	push_max_from_a_to_b(ab);
	push_max_from_a_to_b(ab);
	sort_three(ab->a, 'a');
	push(ab->b, ab->a, 'a');
	rotate(ab->a, 'a');
	push(ab->b, ab->a, 'a');
	rotate(ab->a, 'a');
}

int	sort_5_and_shorter(t_two_stacks *ab)
{
	if (is_sorted(ab->a))
		;
	else if (len_(ab->a) == 2)
		swap(ab->a, 'a');
	else if (ab->len == 3)
		sort_three(ab->a, 'a');
	else if (ab->len == 4)
		sort_four(ab);
	else if (ab->len == 5)
		sort_five(ab);
	return (0);
}
