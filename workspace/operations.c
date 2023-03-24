/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:46:18 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/24 20:26:26 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_operation(char *op, char a_or_b, int print_operations)
{
	if (a_or_b != ' ' && print_operations != 0)
	{
		ft_printf("%s", op);
		if (a_or_b == 'a' || a_or_b == 'b') 
			ft_printf("%c\n", a_or_b);
	}
}

void	swap(t_stk	**a, char a_or_b, int print_operations)
{
	t_stk	*a1;
	t_stk	*a2;
	t_stk	*a3;
	t_stk	*an;

	if (*a == NULL || (*a) == (*a)->nxt)
		return ;
	a1 = *a;
	a2 = a1->nxt;
	a3 = a2->nxt;
	if (a3 == a1)
	{
		*a = a2;
		print_operation("s", a_or_b, print_operations);
		return ;
	}
	an = a1->prv;
	an->nxt = a2;
	a2->prv = an;
	a2->nxt = a1;
	a1->prv = a2;
	a1->nxt = a3;
	a3->prv = a1;
	*a = a2;
	print_operation("s", a_or_b, print_operations);
}

void swap_two(t_two_stacks *ab, int print_operations)
{
	swap(ab->a, ' ', print_operations);
	swap(ab->b, ' ', print_operations);
	print_operation("rr", 0, print_operations);
}

void	push(t_stk **from, t_stk **to, char a_or_b, int print_operations)
{
	t_stk	*moved;

	if (from == NULL || *from == NULL)
		return ;
	moved = *from;
	if (moved == moved->nxt)
	{
		put_elt(moved, to);
		*from = NULL;
		print_operation("p", a_or_b, print_operations);
		return ;
	}
	moved->nxt->prv = moved->prv;
	moved->prv->nxt = moved->nxt;
	*from = moved->nxt;
	put_elt(moved, to);
	print_operation("p", a_or_b, print_operations);
}

void	rotate(t_stk **a, char a_or_b, int print_operations)
{
	if (*a == NULL)
		return ;
	*a = (*a)->nxt;
	print_operation("r", a_or_b, print_operations);
}

void	rotate_two(t_two_stacks *ab, int print_operations)
{
	rotate(ab->a, ' ', print_operations);
	rotate(ab->b, ' ', print_operations);
	print_operation("rr", 0, print_operations);
}

void	reverse_rotate(t_stk **a, char a_or_b, int print_operations)
{
	if (*a == NULL)
		return ;
	*a = (*a)->prv;
	print_operation("rr", a_or_b, print_operations);
}
