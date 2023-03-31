void	push_max_from_a_to_b(t_two_stacks *ab, int print_operations)
{
	int		max;
	int		i;
	t_stk	*cur;

	max = (*(ab->a))->n;
	i = 0;
	cur = *(ab->a);
	while (i < len_(ab->a))
	{
		if (max < cur->n)
			max = cur->n;
		i++;
		cur = cur-> nxt;
	}
	while (1)
	{
		if ((*(ab->a))->n == max)
		{
			push(ab->a, ab->b, ab, 'b', print_operations);
			break ;
		}
		rotate(ab->a, ab, 'a', print_operations);
	}
}

static void	sort_three(t_stk	**a, char a_or_b, int print_operations)
{
	t_stk	*a2;
	t_stk	*a3;

	a2 = (*a)->nxt;
	a3 = a2->nxt;
	if (is_sorted(a))
		;
	else if (a3->n < a2->n && a3->n < (*a)->n)
	{
		if ((*a)->n > a2->n)
			swap(a, NULL, a_or_b, print_operations);
		reverse_rotate(a, NULL, a_or_b, print_operations);
	}
	else if (a2->n < (*a)->n && a2->n < a3->n)
	{
		if ((*a)->n < a3->n)
			swap(a, NULL, a_or_b, print_operations);
		else
			rotate(a, NULL, a_or_b,print_operations);
	}
	else
	{
		swap(a, NULL, a_or_b, print_operations);
		rotate(a, NULL, a_or_b, print_operations);
	}
}

static void	sort_four(t_two_stacks *ab, int print_operations)
{
	push_max_from_a_to_b(ab, print_operations);
	sort_three(ab->a, 'a', print_operations);
	push(ab->b, ab->a, ab, 'a', print_operations);
	rotate(ab->a, ab, 'a', print_operations);
}

static void	sort_five(t_two_stacks *ab, int print_operations)
{
	push_max_from_a_to_b(ab, print_operations);
	push_max_from_a_to_b(ab, print_operations);
	sort_three(ab->a, 'a', print_operations);
	push(ab->b, ab->a, ab, 'a', print_operations);
	rotate(ab->a, ab, 'a', print_operations);
	push(ab->b, ab->a, ab, 'a', print_operations);
	rotate(ab->a, ab, 'a', print_operations);
}

int	sort_5_and_shorter(t_two_stacks *ab, int print_operations)
{
	if (is_sorted(ab->a))
		;
	else if (len_(ab->a) == 2)
		swap(ab->a, ab, 'a', print_operations);
	else if (ab->len == 3)
		sort_three(ab->a, 'a',print_operations);
	else if (ab->len == 4)
		sort_four(ab, print_operations);
	else if (ab->len == 5)
		sort_five(ab, print_operations);
	return (0);
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

int	inverse_a(t_two_stacks *ab, int print_operations)
{
	unsigned int	i;

	i = 0;
	while (i < ab->len)
	{
		reverse_rotate(ab->a, ab, 'a', print_operations);
		push(ab->a, ab->b, ab, 'b', print_operations);
		i++;
	}
	*(ab->a) = *(ab->b);
	*(ab->b) = NULL;
	i = 0;
	while (i < ab->len)
	{
		push(ab->a, ab->b, ab, 'a', print_operations);
		i++;
	}
	*(ab->a) = *(ab->b);
	*(ab->b) = NULL;
	return (3 * ab->len);
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
	unsigned int	len_base;
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
		len_base *= 2;
	}
	if (ab->a_or_b == 'b') 
		nb_operations += push_all_from_b_to_a(ab, print_operations);
	if (ab->a_or_b == 'a' && ab->inc_or_dec == 'i') // 8 .. 15, 32 .. 63, 128 .. 255, 512 ..
		nb_operations += inverse_a(ab, print_operations);
	return (nb_operations);
}

int	nb_operation_radix_sort(t_two_stacks *ab)
{
	int						p;
	unsigned int	i;
	int						nb_ops;
	int						nb_zeros;
	t_stk					*cur;

	p = 0;
	nb_ops = 0;
	while (p < 32)
	{
		if (only_zeros_at_bite_p_(ab, p) == 1 || already_sorted_by_bite_p(ab, p))
		{
			p++;
			continue ;
		}
		i = 0;
		nb_zeros = 0;
		cur = *(ab->a);
		while (i < ab->len)
		{
			if (what_is_at_bite_p(cur->un, p) == 0)
				nb_zeros++;
			i++;
			cur = cur->nxt;
		}
		nb_ops += ab->len + nb_zeros;
		p++;
	}
	return (nb_ops);
}