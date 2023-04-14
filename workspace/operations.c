/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:09:38 by akostrik          #+#    #+#             */
/*   Updated: 2023/04/14 17:12:13 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_two_stacks *ab, char a_or_b)
{
	t_stk	*moved;
	t_stk	**from;
	t_stk	**to;

	from = ab->b;
	to = ab->a;
	if (a_or_b == 'b')
	{
		from = ab->a;
		to = ab->b;
	}
	moved = *from;
	if (moved == moved->nxt)
	{
		put_elt(moved, to);
		*from = NULL;
		ft_printf("p%c\n", a_or_b);
		return ;
	}
	moved->nxt->prv = moved->prv;
	moved->prv->nxt = moved->nxt;
	*from = moved->nxt;
	put_elt(moved, to);
	ft_printf("p%c\n", a_or_b);
}

void	swap_a(t_two_stacks *ab)
{
	t_stk	*a1;
	t_stk	*a2;
	t_stk	*a3;
	t_stk	*an;

	if (ab->len <= 1)
		return ;
	a1 = *(ab->a);
	a2 = a1->nxt;
	a3 = a2->nxt;
	an = a1->prv;
	an->nxt = a2;
	a2->nxt = a1;
	a1->nxt = a3;
	a3->prv = a1;
	a1->prv = a2;
	a2->prv = an;
	ft_printf("sa\n");
}

void	rotate_a(t_two_stacks *ab)
{
	if (ab->len <= 1)
		return ;
	*(ab->a) = (*(ab->a))->nxt;
	ft_printf("ra\n");
}

void	reverse_rotate_a(t_two_stacks *ab)
{
	if (ab->len <= 1)
		return ;
	*(ab->a) = (*(ab->a))->prv;
	ft_printf("rra\n");
}
