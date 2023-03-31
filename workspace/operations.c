/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:46:18 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/31 19:53:41 by akostrik         ###   ########.fr       */
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

void	rotate_a(t_two_stacks *ab)
{
	if (ab->a == NULL || *(ab->a) == NULL) // delete
		return ;
	if (ab->len <= 1)
		return ;
	*(ab->a) = (*(ab->a))->nxt;
	ft_printf("ra\n");
}
