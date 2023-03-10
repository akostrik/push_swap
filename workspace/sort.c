/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:57:42 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/10 17:27:35 by akostrik         ###   ########.fr       */
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

int	sort_1st_version(t_two_stacks *ab)
{
	int	len_base;
	int	nb_elts_r;
	int	nb_elts_l;

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
/*
int	deep_copy(t_stk **a, t_stk **copy)
{
	int		i;
	int		len;
	t_stk	*cur;

	i = 0;
	len = len_(a);
	cur = (*a)->prv;
	while (i < len)
	{
		if (put_int(cur->n, copy) == -1)
			return (-1);
		cur = cur->prv;
		i++;
	}
	printf("deep_copy:\n");
	print_ints(copy);
	return (0);
}

void delete (int n, t_stk **a)
{
	t_stk	*cur;

	if (a == NULL || *a == NULL)
		return ;
	cur = *a;
	while (cur->n != n)
		cur = cur->nxt;
	if (len_(a) == 1)
	{
		free(*a);
		return ;
	}
	cur->prv->nxt = cur->nxt;
	cur->nxt->prv = cur->prv;
	free(cur);
}

int	median_(t_stk **a)
{
	t_stk	**copy;
	//int	min;
	//int	max;
	//t_stk	*cur;
	//int		i;
	//int		len;

	copy = NULL;
	copy = (t_stk **)malloc(sizeof(t_stk *));
	if (copy == NULL)
		return (-1);
	*copy = NULL;
	deep_copy(a, copy);
	printf("f median:\n");
	print_ints(copy);
//	while (len_(copy) > 2)
	{
		i = 0;
		printf("i=0\n");
		len = len_(copy);
		printf("len = %d\n",len);
		min = (*copy)->n;
		max = (*copy)->n;
		cur = *copy;
		printf("*** \n");
		while (i < len)
		{
			if (min > cur->n)
				min = cur->n;
			if (max < cur->n)
				max = cur->n;
			i++;
			cur = cur->nxt;
		}
		printf("max = %d, min = %d\n", max,min);
		delete (min, copy);
		delete (max, copy);
	}
	free_stack(&copy);
	return ((*copy)->n);
	return (5);
}*/

int	*merge_sort(int *up, int *down, unsigned int left, unsigned int right)
{
	if (left == right)
	{
		down[left] = up[left];
		return down;
	}

	unsigned int middle = left + (right - left) / 2;

	// разделяй и сортируй
	int *l_buff = merge_sort(up, down, left, middle);
	int *r_buff = merge_sort(up, down, middle + 1, right);

	// слияние двух отсортированных половин
	int *target = l_buff == up ? down : up;

	unsigned int l_cur = left, r_cur = middle + 1;
	for (unsigned int i = left; i <= right; i++)
	{
		if (l_cur <= middle && r_cur <= right)
		{
			if (l_buff[l_cur] < r_buff[r_cur])
			{
				target[i] = l_buff[l_cur];
				l_cur++;
			}
			else
			{
				target[i] = r_buff[r_cur];
				r_cur++;
			}
		}
		else if (l_cur <= middle)
		{
			target[i] = l_buff[l_cur];
			l_cur++;
		}
		else
		{
			target[i] = r_buff[r_cur];
			r_cur++;
		}
	}
	return target;
}

void put_places(t_stk **a, int *sorted_ints, int len)
{
	int		i;
	int		j;
	t_stk	*cur;

	i = 0;
	while (i < len)
	{
		j = 0;
		cur = *a;
		while (j < len)
		{
			if (sorted_ints[i] == cur->n)
			{
				cur->place = i; 
				break ;
			}
			cur = cur->nxt;
			j++;
		}
		i++;
	}
}

int	sort2(t_two_stacks *ab)
{
	// int	len_base;
	// int	nb_elts_r;
	// int	nb_elts_l;
	int	*up;
	int	*down;
	int	*sorted_ints;
	int i;
	t_stk	*cur;

	if (ab->len <= 5)
		return (sort_5_and_shorter(ab));
	up = (int *)malloc((ab->len)*sizeof(int));
	if (up == NULL)
		return (-1);
	down = (int *)malloc((ab->len)*sizeof(int));
	if (down == NULL)
		return (-1);
	i = 0;
	cur = *(ab->a);
	while (i < ab->len)
	{
		up[i] = cur->n;
		i++;
		cur = cur->nxt;
	}
	sorted_ints = merge_sort(up, down, 0, ab->len - 1);
	put_places(ab->a, sorted_ints, ab->len);
	
	i = 0;
	while (i < ab->len)
	{
		if ((*(ab->a))->place >= ab->len / 2)
			push(ab->a, ab->b, 'b');
		rotate(ab->a, 'a');
		i++;
	}
	print_ints(ab->a);
	print_ints(ab->b);
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
