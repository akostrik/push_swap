/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:57:42 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/03 19:53:49 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// i_or_d = increasing or decreasing

#include "push_swap.h"

static int	nb_elts_before_main_loop(int total_len, int len_base)
{
	int	len;

	len = 0;
	while (1)
	{
		if (len <= total_len && total_len < len + 2 * len_base)
			return (total_len - len);
		len += 2 * len_base;
	}
	return (0);
}

static void	merge(t_two_stacks *ab, int lenl, int lenr)
{
	int	l;
	int	r;

	change_id(&(ab->inc_or_dec));
	l = 0;
	r = 0;
	while (l < lenl && r < lenr)
	{
		if ((ab->inc_or_dec == 'i' && (*(ab->a))->n > (*(ab->a))->prv->n) \
		|| (ab->inc_or_dec == 'd' && (*(ab->a))->n < (*ab->a)->prv->n))
		{
			reverse_rotate(ab->a, ab->a_or_b);
			r++;
		}
		else
			l++;
		push(ab->a, ab->b, the_other(ab->a_or_b));
	}
	while (l++ < lenl)
		push(ab->a, ab->b, the_other(ab->a_or_b));
	while (r++ < lenr)
	{
		reverse_rotate(ab->a, ab->a_or_b);
		push(ab->a, ab->b, the_other(ab->a_or_b));
	}
}

static void	merge_main_loop(t_two_stacks *ab, int len_base)
{
	int		nb_elts_to_treat;

	ab->inc_or_dec = 'i';
	nb_elts_to_treat = ab->len - nb_elts_before_main_loop(ab->len, len_base);
	while (nb_elts_to_treat > 0)
	{
		merge(ab, len_base, len_base);
		nb_elts_to_treat -= 2 * len_base;
	}
}

int	sort(t_two_stacks *ab)
{
	int		len_base;
	int		nb_elts_r;
	int		nb_elts_l;

	if (ab->len <= 5)
		return (sort_5_and_shorter(ab));
	len_base = 1;
	nb_elts_r = 0;
	while (len_base <= ab->len)
	{
		if (is_sorted(ab->a) && ab->a_or_b == 'a' && len_(ab->a) == ab->len)
			return (0);
		nb_elts_l = nb_elts_before_main_loop(ab->len, len_base);
		if (nb_elts_l > 0)
			merge(ab, nb_elts_l - nb_elts_r, nb_elts_r);
		nb_elts_r = nb_elts_l;
		merge_main_loop(ab, len_base);
		change_ab(ab);
		len_base *= 2;
	}
	if (ab->a_or_b == 'b')
		push_all_from_b_to_a(ab);
	if (ab->a_or_b == 'a' && ab->inc_or_dec == 'i')
		inverse_a(ab);
	return (0);
}

/*void	bubble_sort(t_stk **a) // O(n*n)
{
	int	len;
	int	swap_was_done;
	int i;

	len = len_(a);
	if (len <= 1)
		return ;
	swap_was_done = 1;
	while (swap_was_done == 1)
	{
		swap_was_done = 0;
		i = 0;
		while (i < len - 1)
		{
			if ((*a)->n > (*a)->nxt->n)
			{
				swap(a,'a');
				swap_was_done = 1;
			}
			rotate(a,'a');
			i++;
		}
		rotate(a,'a');
		if (is_sorted(a))
			break ;
	}
} */
