/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:57:42 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/30 17:58:13 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int what_is_at_bite_p(unsigned int un, int p)
{
	return ((int)((un>>p) & 00000000000000000000000000000001));
}

static int only_zeros_at_bite_p_(t_two_stacks *ab, int p)
{
	unsigned int	i;
	t_stk					*cur;

	cur = *(ab->a);
	i = 0;
	while (i < ab->len)
	{
		if (what_is_at_bite_p(cur->un, p) == 1)
			return (0);
		cur = cur->nxt;
		i++;
	}
	return (1);
}

static void	move_those_who_has_0_at_place_p(t_two_stacks *ab, int p, int print_operations)
{
	unsigned int	i;

	i = 0;
	while (i < ab->len)
	{
		if (what_is_at_bite_p((*(ab->a))->un, p) == 0)
			push(ab->a, ab->b, ab, 'b', print_operations);
		else
			rotate(ab->a, ab, 'a', print_operations);
		i++;
	}
}

static int already_sorted_by_bite_p(t_two_stacks *ab, int p)
{
	t_stk					*cur;
	unsigned int	i;

	cur = (*(ab->a))->nxt;
	i = 1;
	while (i < ab->len)
	{
		if (what_is_at_bite_p(cur->prv->un, p) > what_is_at_bite_p(cur->un, p))
			return (0);
		i++;
		cur = cur->nxt;
	}
	return (1);
}

static void	replace_by_smaller_numbers(t_two_stacks *ab)
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

// 100 1084 = 3 points, 500 6784 = 4 points
void	radix_sort(t_two_stacks *ab, int print_operations)
{
	int	p;

	if (is_sorted(ab) == 1)
		return ;
	replace_by_smaller_numbers(ab);
	p = 0;
	while (p < 32)
	{
		if (only_zeros_at_bite_p_(ab, p) == 1 || already_sorted_by_bite_p(ab, p))
		{
			p++;
			continue ;
		}
		move_those_who_has_0_at_place_p(ab, p, print_operations);
		push_all_from_b_to_a2(ab, print_operations);
		p++;
	}
}

