/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:47:03 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/31 17:17:05 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	//new->str2 = convert_to_binary(new->un);
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
	t_stk				*cur;

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

int	push_all_from_b_to_a(t_two_stacks *ab)
{
	unsigned int	i;
	unsigned int	len_b;

	len_b = len_(ab->b);
	i = 0;
	while (i < len_b)
	{
		push(ab, 'a');
		i++;
	}
	return (i);
}
