/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:47:03 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/31 16:51:15 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//////////////////////////////////
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
