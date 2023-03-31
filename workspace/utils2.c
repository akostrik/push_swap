/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:47:03 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/31 15:03:32 by akostrik         ###   ########.fr       */
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
