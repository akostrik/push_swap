/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:47:03 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/31 19:47:39 by akostrik         ###   ########.fr       */
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
	t_stk					*min;
	t_stk					*cur;

	i = 0;
	while (i < ab->len)
	{
		j = 0;
		min = *(ab->a);
		while (j < ab->len && min->un < i)
		{
			j++;
			min = min->nxt;
		}
		cur = min;
		while (j++ < ab->len)
		{
			if (min->un > cur->un && cur->un >= i)
				min = cur;
			cur = cur->nxt;
		}
		min->un = i++;
	}
}

static void	free_stack_a(t_two_stacks *ab)
{
	t_stk					*cur;
	unsigned int	i;

	if (ab->a == NULL)
		return ;
	if (*(ab->a) == NULL)
	{
		free (*(ab->a));
		return ;
	}
	if (ab->len == 1)
	{
		free(*(ab->a));
		free(ab->a);
		return ;
	}
	i = 0;
	cur = (*(ab->a))->nxt;
	while (i < ab->len - 2)
	{
		free(cur->prv);
		cur = cur->nxt;
		i++;
	}
	free(cur->prv);
	free(cur);
	free(ab->a);
}

void free_memory(t_two_stacks **ab)
{
	if (ab == NULL)
		return ;
	free_stack_a(*ab);
	if ((*ab)->b != NULL)
		free((*ab)->b);
	free(*ab);
}
