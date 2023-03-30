/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:57:42 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/30 15:03:28 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	merge(t_two_stacks *ab, int lenl, int lenr, int print_operations)
{
	int	l;
	int	r;
	int	nb_operations;

	nb_operations = 0;
	change_id(&(ab->inc_or_dec));
	l = 0;
	r = 0;
	while (l < lenl && r < lenr)
	{
		if ((ab->inc_or_dec == 'i' && (*(ab->a))->n > (*(ab->a))->prv->n) \
		|| (ab->inc_or_dec == 'd' && (*(ab->a))->n < (*ab->a)->prv->n))
		{
			reverse_rotate(ab->a, ab, ab->a_or_b, print_operations);
			nb_operations++;
			r++;
		}
		else
			l++;
		push(ab->a, ab->b, ab, the_other(ab->a_or_b), print_operations);
		nb_operations++;
	}
	while (l++ < lenl)
	{
		push(ab->a, ab->b, ab, the_other(ab->a_or_b), print_operations);
		nb_operations++;
	}
	while (r++ < lenr)
	{
		reverse_rotate(ab->a, ab, ab->a_or_b, print_operations);
		push(ab->a, ab->b, ab, the_other(ab->a_or_b), print_operations);
		nb_operations += 2;
	}
	return (nb_operations);
}

static int	merge_main_loop(t_two_stacks *ab, int len_base, int print_operations)
{
	int		nb_elts_to_treat;
	int	nb_operations;

	nb_operations = 0;
	ab->inc_or_dec = 'i';
	nb_elts_to_treat = ab->len - nb_elts_before_main_loop(ab->len, len_base);
	while (nb_elts_to_treat > 0)
	{
		nb_operations += merge(ab, len_base, len_base, print_operations);
		nb_elts_to_treat -= 2 * len_base;
	}
	return (nb_operations);
}

int	sort_2_4_8(t_two_stacks *ab, int print_operations) // 100 : 1124 = 2 points, 500 : 7170 = 3 points
{
	int	len_base;
	int	nb_elts_r;
	int	nb_elts_l;
	int	nb_operations;

	if (ab->len <= 5)
		return (sort_5_and_shorter(ab, print_operations)); //////
	// if (to_change_id(ab->len))
	// 	;
	len_base = 1;
	nb_elts_r = 0;
	nb_operations = 0;
	while (len_base < ab->len) 
	{
		if (is_sorted(ab->a) && ab->a_or_b == 'a' && len_(ab->a) == ab->len)
			return (nb_operations);
		nb_elts_l = nb_elts_before_main_loop(ab->len, len_base);
		if (nb_elts_l > 0)
			nb_operations += merge(ab, nb_elts_l - nb_elts_r, nb_elts_r, print_operations);
		nb_elts_r = nb_elts_l;
		nb_operations += merge_main_loop(ab, len_base, print_operations);
		change_ab(ab);
		//printf("len_base = %d, sur %c : ",len_base,ab->a_or_b);
		//print_ints(ab->a);
		len_base *= 2;
	}
	if (ab->a_or_b == 'b') 
		nb_operations += push_all_from_b_to_a(ab, print_operations);
	if (ab->a_or_b == 'a' && ab->inc_or_dec == 'i') // 8 .. 15, 32 .. 63, 128 .. 255, 512 ..
		nb_operations += inverse_a(ab, print_operations);
	return (nb_operations);
}

static int what_is_at_bite_p(unsigned int un, int p)
{
	//printf("what_is in %u at_bite %d ? %d\n",un,p, (int)((un>>p) & 00000000000000000000000000000001));
	return ((int)((un>>p) & 00000000000000000000000000000001));
}

static int only_zeros_at_bite_p_(t_two_stacks *ab, int p)
{
	int		i;
	t_stk	*cur;

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

/*
static void	remember_op(t_two_stacks *ab, char *op)
{
	t_list_ops	*new_op;
	t_list_ops	*last_op;

	new_op = (t_list_ops *)malloc(sizeof(t_list_ops));
	new_op->op = op;
	new_op->nxt = NULL;
	last_op = ab->radix_operations;
	while (last_op->nxt != NULL) // нерационально
		last_op = last_op->nxt;
	last_op->nxt = new_op;
}
*/
static void	move_those_who_has_0_at_place_p(t_two_stacks *ab, int p, int print_operations)
{
	int	i;

	//if (only_zeros_at_bite_p_(ab, p) == 1)
		//return ;
	i = 0;
	while (i < ab->len)
	{
		if (what_is_at_bite_p((*(ab->a))->un, p) == 0)
			push(ab->a, ab->b, ab, 'b', print_operations);
			//remember_op(ab, "pb\n");
		else
			rotate(ab->a, ab, 'a', print_operations);
			//remember_op(ab, "ra\n");
		i++;
	}
}

// 100 radix sort 1181 operations
// 500 radix sort 8221 operations

static int	bite_p_double_another_bite(t_two_stacks *ab, int p)
{
	t_stk	*cur;
	int		i;
	int		q;
	int smth_new_in_bite_q;

	if (p == 0)
		return (0);
	q = 0;
	while (q < p)
	{
		smth_new_in_bite_q = 0;
		cur = *(ab->a);
		i = 0;
		while (i < ab->len)
		{
			if (what_is_at_bite_p(cur->un, p) != what_is_at_bite_p(cur->un, q))
			{
				smth_new_in_bite_q = 1;
				break;
			}
			i++;
			cur = cur->nxt;
		}
		if (smth_new_in_bite_q == 0)
		{
			printf ("bite %d double bite %d (%d!=%d) \n",p,q,what_is_at_bite_p(cur->un, p),what_is_at_bite_p(cur->un, q));
			return (1);
		}
		q++;
	}
	return (0);
}

void	radix_sort(t_two_stacks *ab, int print_operations) // 100 : 1181 = 2 points, 500 : 8221 = 3 points
{
	int	p;

	p = 0;
	while (p < 32)
	{
		if (only_zeros_at_bite_p_(ab, p) == 1 || bite_p_double_another_bite(ab, p) == 1)
		{
			p++;
			continue ;
		}
		move_those_who_has_0_at_place_p(ab, p, print_operations);
		push_all_from_b_to_a2(ab, print_operations);
		p++;
	}
}

int	nb_operation_radix_sort(t_two_stacks *ab)
{
	int	p;
	int	j;
	int	nb_ops;
	int	nb_zeros;
	t_stk	*cur;

	p = 0;
	nb_ops = 0;
	while (p < 32)
	{
		if (only_zeros_at_bite_p_(ab, p) == 1 || bite_p_double_another_bite(ab, p) == 1)
		{
			p++;
			continue ;
		}
		j = 0;
		nb_zeros = 0;
		cur = *(ab->a);
		while (j < ab->len)
		{
			if (what_is_at_bite_p(cur->un, p) == 0)
				nb_zeros++;
			j++;
			cur = cur->nxt;
		}
		nb_ops += ab->len + nb_zeros;
		p++;
	}
	return (nb_ops);
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
/*
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

void	sort_two_stacks(t_two_stacks *ab)
{
	int	a_is_sorted;
	int	b_is_sorted;
	
	a_is_sorted = 0;
	b_is_sorted = 0;
	while (!a_is_sorted || !b_is_sorted)
	{
		if ((*(ab->a))->n < ((*(ab->a))->nxt)->n && (*(ab->b))->n > ((*(ab->b))->nxt)->n)
			swap_two(ab);
		else if ((*(ab->a))->n < ((*(ab->a))->nxt)->n)
			swap(ab->a, 'a');
		else if ((*(ab->b))->n > ((*(ab->b))->nxt)->n)
			swap(ab->b, 'b');
		a_is_sorted = is_sorted(ab->a);
		a_is_sorted = is_sorted(ab->b);
		
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
	printf("***\n");
	sort_two_stacks(ab);
	print_ints(ab->a);
	print_ints(ab->b);
	return (0);
}
*/
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
