/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:24:00 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/31 19:37:52 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
//# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stddef.h>
# include "libft/libft.h"

typedef struct	s_stk
{
	int						n;
	unsigned int	un;
	struct s_stk	*nxt;
	struct s_stk	*prv;
}	t_stk;

typedef struct	s_list_ops
{
	char							*op;
	struct s_list_ops	*nxt;
}	t_list_ops;

// increasing or decreasing
typedef struct s_two_stacks
{
	t_stk							**a;
	t_stk							**b;
	unsigned int			len;
}	t_two_stacks;

int		put_args(t_two_stacks *ab, int argc, char **argv);
int		put_int(int n, t_stk **a);
int		put_elt(t_stk	*new, t_stk **a);
void	replace_by_smaller_numbers(t_two_stacks *ab);

void	radix_sort(t_two_stacks *ab);
int		push_all_from_b_to_a(t_two_stacks *ab);
int		is_sorted(t_two_stacks *ab);

void	push(t_two_stacks *ab, char a_or_b);
void	rotate_a(t_two_stacks *ab);

unsigned int		len_(t_stk **a);
void	free_memory(t_two_stacks **ab);
//void	print_ints(t_stk	**a);
//void	print_all_info(t_stk	**a);

#endif
