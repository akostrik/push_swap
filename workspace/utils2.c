/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:47:03 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/20 15:19:58 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_stk	**a)
{
	int		max;
	int		i;
	int		len;
	t_stk	*cur;

	max = (*a)->n;
	len = len_(a);
	i = 0;
	cur = *a;
	while (i < len)
	{
		if (max < cur->n)
			max = cur->n;
		i++;
		cur = cur-> nxt;
	}
	return (max);
}

int	is_sorted(t_stk **a)
{
	t_stk	*cur;
	int		len_tot;

	len_tot = len_(a);
	if (len_tot <= 1)
		return (1);
	cur = *a;
	while (cur->nxt != *a)
	{
		if (cur->n > cur->nxt->n)
			return (0);
		cur = cur->nxt;
	}
	return (1);
}

void	change_ab(t_two_stacks *ab)
{
	t_stk	*tmp;

	tmp = *(ab->a);
	*(ab->a) = *(ab->b);
	*(ab->b) = tmp;
	if (ab->a_or_b == 'a')
		ab->a_or_b = 'b';
	else if (ab->a_or_b == 'b')
		ab->a_or_b = 'a';
}

char	change_id(char *id)
{
	if (*id == 'i')
	{
		*id = 'd';
		return ('d');
	}
	if (*id == 'd')
	{
		*id = 'i';
		return ('i');
	}
	return (0);
}

char	the_other(char ab)
{
	if (ab == 'a')
		return ('b');
	return ('a');
}
