/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:47:03 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/31 15:56:28 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_two_stacks *ab)
{
	t_stk	*cur;

	if (ab->len <= 1)
		return (1);
	cur = *(ab->a);
	while (cur->nxt != *(ab->a))
	{
		if (cur->n > cur->nxt->n)
			return (0);
		cur = cur->nxt;
	}
	return (1);
}

void	replace_by_smaller_numbers(t_two_stacks *ab)
{
	unsigned int	i;
	unsigned int	j;
	t_stk	*min;
	t_stk	*cur;

	i = 0;
	while (i < ab->len)
	{
		j = 0;
		cur = *(ab->a);
		while (j < ab->len)
		{
			if (cur->un >= i)
				break;
			j++;
			cur = cur->nxt;
		}
		min = cur;
		while (j < ab->len)
		{
			if (min->un > cur->un && cur->un >= i)
				min = cur;
			j++;
			cur = cur->nxt;
		}
		min->un = i;
		i++;
	}
}
