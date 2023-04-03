/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:57:42 by akostrik          #+#    #+#             */
/*   Updated: 2023/04/03 17:12:56 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_sorted_by_bite_p(t_two_stacks *ab, int p)
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

static void	move_those_who_has_0_at_bite_p(t_two_stacks *ab, int p)
{
	unsigned int	i;

	i = 0;
	while (i < ab->len)
	{
		if (what_is_at_bite_p((*(ab->a))->un, p) == 0)
			push(ab, 'b');
		else
			rotate_a(ab);
		i++;
	}
}

static int	push_all_from_b_to_a(t_two_stacks *ab) // void ?
{
	unsigned int	i;
	unsigned int	len_b;

	len_b = len_(ab->b);
	i = 0;
	while (i++ < len_b)
		push(ab, 'a');
	return (i - 1);
}

// 1084 = 3 points, 6784 = 4 points
void	radix_sort(t_two_stacks *ab)
{
	int	p;

	p = 0;
	while (p < 32)
	{
		if (is_sorted(ab) == 1)
			return ;
		if (is_sorted_by_bite_p(ab, p))
		{
			p++;
			continue ;
		}
		move_those_who_has_0_at_bite_p(ab, p);
		//printf("p = %d, %d operations\n",p,ab->len+push_all_from_b_to_a(ab));
		push_all_from_b_to_a(ab);
		p++;
	}
}
