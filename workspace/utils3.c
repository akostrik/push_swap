/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:47:03 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/24 15:52:51 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stk ***a)
{
	t_stk	*cur;
	int		len;
	int		i;

	if (*a == NULL)
		return ;
	if (**a == NULL)
	{
		free (*a);
		return ;
	}
	len = len_(*a);
	i = 0;
	cur = (**a)->nxt;
	while (i < len - 2)
	{
		free(cur->prv);
		cur = cur->nxt;
		i++;
	}
	free(cur->prv);
	if (len > 1)
		free(cur);
	free(*a);
}

void	print_ints(t_stk	**a) ///////////////////////////////
{
	t_stk	*cur;
	int	i;

	if (a == NULL || *a == NULL)
	{
		printf(" empty\n");
		return ;
	}
	cur = *a;
	printf("\n%11d -> %12u = %s\n", cur->n, cur->un, cur->str2);
	cur = cur->nxt;
	i = 1;
	while (cur != *a)
	{
	printf("%11d -> %12u = %s\n", cur->n, cur->un, cur->str2);
		cur = cur->nxt;
		i++;
	}
	printf("\n");

	// cur = *a;
	// printf("%2d ", cur->place);
	// cur = cur->nxt;
	// i = 1;
	// while (cur != *a)
	// {
	// 	printf("%2d ", cur->place);
	// 	cur = cur->nxt;
	// 	i++;
	// }
	// printf("\n");
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
}
