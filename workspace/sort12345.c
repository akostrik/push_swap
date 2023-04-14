/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort12345.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:23:53 by akostrik          #+#    #+#             */
/*   Updated: 2023/04/14 17:25:32 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	push_min_from_a_to_b(t_two_stacks *ab)
{
	unsigned int		min;
	unsigned int		i;
	t_stk				*cur;

	min = (*(ab->a))->u;
	i = 0;
	cur = *(ab->a);
	while (i < len_(ab->a))
	{
		if (min > cur->u)
			min = cur->u;
		i++;
		cur = cur-> nxt;
	}
	while ((*(ab->a))->u != min)
	{
		if (i < (ab->len) / 2)
			rotate_a(ab);
		else
			reverse_rotate_a(ab);
	}
	push(ab, 'b');
}

static void	sort3(t_two_stacks *ab)
{
	t_stk	*a1;
	t_stk	*a2;
	t_stk	*a3;

	a1 = *(ab->a);
	a2 = a1->nxt;
	a3 = a2->nxt;
	if (a1->u == UINT_MAX -2 && a2->u == UINT_MAX -1 && a3->u == UINT_MAX)
		;
	else if (a1->u == UINT_MAX -2 && a2->u == UINT_MAX && a3->u == UINT_MAX -1)
	{
		swap_a(ab);
		rotate_a(ab);
	}
	else if (a1->u == UINT_MAX -1 && a2->u == UINT_MAX && a3->u == UINT_MAX -2)
		reverse_rotate_a(ab);
	else if (a1->u == UINT_MAX -1 && a2->u == UINT_MAX -2 && a3->u == UINT_MAX)
		swap_a(ab);
	else if (a1->u == UINT_MAX && a2->u == UINT_MAX -2 && a3->u == UINT_MAX -1)
		rotate_a(ab);
	else if (a1->u == UINT_MAX && a2->u == UINT_MAX -1 && a3->u == UINT_MAX -2)
	{
		swap_a(ab);
		reverse_rotate_a(ab);
	}
}

static void	sort4(t_two_stacks *ab)
{
	if (!(is_sorted(ab)))
	{
		push_min_from_a_to_b(ab);
		sort3(ab);
		push(ab, 'a');
	}
}

static void	sort5(t_two_stacks *ab)
{
	if (!(is_sorted(ab)))
	{
		push_min_from_a_to_b(ab);
		push_min_from_a_to_b(ab);
		sort3(ab);
		push(ab, 'a');
		push(ab, 'a');
	}
}

void	sort12345(t_two_stacks *ab)
{
	if (is_sorted(ab))
		;
	else if (ab->len == 2)
		swap_a(ab);
	else if (ab->len == 3)
		sort3(ab);
	else if (ab->len == 4)
		sort4(ab);
	else if (ab->len == 5)
		sort5(ab);
}
