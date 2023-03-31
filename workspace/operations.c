/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:46:18 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/31 16:34:00 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_operation(char op, char a_or_b, int print_operations)
{
	if (print_operations != 0)
	{
		ft_printf("%c", op);
		if (a_or_b == 'a' || a_or_b == 'b') 
			ft_printf("%c\n", a_or_b);
	}
}

void	push(t_two_stacks *ab, char a_or_b, int print_operations)
{
	t_stk	*moved;
	t_stk **from;
	t_stk **to;

	if (a_or_b == 'a')
	{
		from = ab->b;
		to = ab->a;
	}
	else
	{
		from = ab->a;
		to = ab->b;
	}
	if (from == NULL || *from == NULL)
		return ;
	moved = *from;
	if (moved == moved->nxt)
	{
		put_elt(moved, to);
		*from = NULL;
		print_operation('p', a_or_b, print_operations);
		return ;
	}
	moved->nxt->prv = moved->prv;
	moved->prv->nxt = moved->nxt;
	*from = moved->nxt;
	put_elt(moved, to);
	print_operation('p', a_or_b, print_operations);
}

void	rotate_a(t_two_stacks *ab, int print_operations)
{
	if (ab->a == NULL || *(ab->a) == NULL)
		return ;
	if (ab->len <= 1)
		return ;
	*(ab->a) = (*(ab->a))->nxt;
	print_operation('r', 'a', print_operations);
}
