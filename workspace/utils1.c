/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:47:03 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/21 17:06:11 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	put_int(int n, t_stk **a)
{
	t_stk	*new;
	int		i;
	int		p;

	new = (t_stk *)malloc(sizeof(t_stk));
	if (new == NULL)
		return (-1);
	new->n = n;
	new->un = (unsigned int)((long)n + (long)INT_MIN);
	new->nxt = NULL;	
	new->prv = NULL;
	new->str2 = (char*)malloc(33); // free
	new->str2[32] = '\0';	
	i = 31;
	p = 0;
	while (i >= 0)
	{
		new->str2[i] = '0' + ((int)((new->un >> p) & 00000000000000000000000000000001));
		i--;
		p++;
	}
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

int	len_(t_stk **a)
{
	int		i;
	t_stk	*cur;

	if (a == NULL || *a == NULL)
		return (0);
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

void	push_all_from_b_to_a(t_two_stacks *ab)
{
	int	i;

	i = 0;
	while (i < ab->len)
	{
		if (ab->inc_or_dec == 'd')
			reverse_rotate(ab->a, 'b');
		push(ab->a, ab->b, 'a');
		i++;
	}
	*(ab->a) = *(ab->b);
	*(ab->b) = NULL;
}

void	inverse_a(t_two_stacks *ab)
{
	int	i;

	i = 0;
	while (i < ab->len)
	{
		reverse_rotate(ab->a, 'a');
		push(ab->a, ab->b, 'b');
		i++;
	}
	*(ab->a) = *(ab->b);
	*(ab->b) = NULL;
	i = 0;
	while (i < ab->len)
	{
		push(ab->a, ab->b, 'a');
		i++;
	}
	*(ab->a) = *(ab->b);
	*(ab->b) = NULL;
}
