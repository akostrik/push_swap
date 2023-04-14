/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:47:03 by akostrik          #+#    #+#             */
/*   Updated: 2023/04/14 17:18:44 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	replace_by_bigger_numbers(t_two_stacks *ab)
{
	unsigned int	j;
	unsigned int	nb;
	t_stk			*max;
	t_stk			*cur;

	nb = UINT_MAX;
	while (nb > UINT_MAX - ab->len)
	{
		max = *(ab->a);
		j = 0;
		while (j < ab->len && max->u > nb)
		{
			j++;
			max = max->nxt;
		}
		cur = max;
		while (j++ < ab->len)
		{
			if (max->u < cur->u && cur->u <= nb)
				max = cur;
			cur = cur->nxt;
		}
		max->u = nb--;
	}
}

int	what_is_at_bite_p(unsigned int u, int p)
{
	return ((int)((u >> p) & 00000000000000000000000000000001));
}

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

void	free_stack_a(t_two_stacks *ab)
{
	t_stk			*cur;
	unsigned int	i;
	unsigned int	len;

	len = len_(ab->a);
	if (ab->a == NULL)
		return ;
	if (*(ab->a) == NULL || len == 1)
	{
		free (*(ab->a));
		return ;
	}
	i = 0;
	cur = (*(ab->a))->nxt;
	while (i++ < len - 2)
	{
		free(cur->prv);
		cur = cur->nxt;
	}
	free(cur->prv);
	free(cur);
}

void	free_memory(t_two_stacks **ab)
{
	if (ab == NULL)
		return ;
	if (*ab == NULL)
	{
		free(*ab);
		return ;
	}
	free_stack_a(*ab);
	if ((*ab)->a != NULL)
		free((*ab)->a);
	if ((*ab)->b != NULL)
		free((*ab)->b);
	free(*ab);
}

/*
char	*convert_to_binary(unsigned int	un) // tmp
{
	char *str;
	int		i;
	int		p;

	str = (char*)malloc(33); // free
	str[32] = '\0';	
	i = 31;
	p = 0;
	while (i >= 0)
	{
		str[i] = '0' + (int)((un >> p) & 00000000000000000000000000000001);
		i--;
		p++;
	}
	return (str);
}

void	print_ints(t_stk	**a)
{
	t_stk	*cur;
	int	i;

	if (a == NULL || *a == NULL)
	{
		printf(" empty\n");
		return ;
	}
	cur = *a;
	printf("\n%11d -> %12u\n", cur->n, cur->un);
	cur = cur->nxt;
	i = 1;
	while (cur != *a)
	{
		printf("%11d -> %12u\n", cur->n, cur->un);
		cur = cur->nxt;
		i++;
	}
	printf("\n");

}

void	print_all_info(t_stk	**a)
{
	t_stk	*cur;

	if (a == NULL || *a == NULL)
	{
		printf(" empty\n");
		return ;
	}
	printf("list %p -> %p %d :\n",a,*a,(*a)->n);
	cur = *a;
	printf("%8p <- %p %s -> %8p\n", cur->prv, cur, cur->str2, cur->nxt);
	cur = cur->nxt;
	while (cur != *a)
	{
		if (cur == NULL) 
		{ 
			printf("NULL "); 
			continue;
		}
		printf("%8p <- %p %s -> %8p\n", cur->prv, cur, cur->str2, cur->nxt);
		cur = cur->nxt;
	}
	printf("\n");
}*/
