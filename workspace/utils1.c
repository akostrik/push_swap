/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:47:03 by akostrik          #+#    #+#             */
/*   Updated: 2023/04/06 14:32:13 by akostrik         ###   ########.fr       */
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
	if (ab->len <= 1)
		return ;
	*(ab->a) = (*(ab->a))->nxt;
	ft_printf("ra\n");
}

//new->str2 = convert_to_binary(new->un);
int	put_int(int n, t_stk **a)
{
	t_stk	*new;

	new = (t_stk *)malloc(sizeof(t_stk));
	if (new == NULL)
		return (-1);
	new->n = n;
	new->un = (unsigned int)((long)n + (long)INT_MIN);
	new->nxt = NULL;
	new->prv = NULL;
	put_elt(new, a);
	return (1);
}

int	put_elt(t_stk	*new, t_stk **a)
{
	if (*a == NULL)
	{
		new->nxt = new;
		new->prv = new;
	}
	else
	{
		new->nxt = *a;
		new->prv = (*a)->prv;
		((*a)->prv)->nxt = new;
		(*a)->prv = new;
	}
	*a = new;
	return (1);
}

unsigned int	len_(t_stk **a)
{
	unsigned int	i;
	t_stk			*cur;

	if (a == NULL || *a == NULL)
		return (0);
	if (*a == (*a)->nxt)
		return (1);
	cur = *a;
	if (cur == cur->nxt)
		return (1);
	i = 1;
	cur = cur->nxt;
	while (cur != *a)
	{
		i++;
		cur = cur->nxt;
	}
	return (i);
}
