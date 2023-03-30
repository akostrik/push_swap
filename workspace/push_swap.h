/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:24:00 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/30 18:26:17 by akostrik         ###   ########.fr       */
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
	char					*str2;
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
	char							a_or_b;
	char							inc_or_dec;
	unsigned int			len;
}	t_two_stacks;

int		sort_5_and_shorter(t_two_stacks *ab, int print_operations);
void	radix_sort(t_two_stacks *ab, int print_operations);
void	swap(t_stk	**a, t_two_stacks *ab, char a_or_b, int print_operations);
void	push(t_stk **from, t_stk **to, t_two_stacks *ab, char a_or_b, int print_operations);
void	rotate(t_stk **a, t_two_stacks *ab, char a_or_b, int print_operations);
void	reverse_rotate(t_stk **a, t_two_stacks *ab, char a_or_b, int print_operations);
void	swap_two(t_two_stacks *ab, int print_operations);
int		put_args(t_stk	**a, int argc, char **argv);
int		put_int(int n, t_stk **a);
int		put_elt(t_stk	*new, t_stk **a);
unsigned int		len_(t_stk **a);
char	*convert_to_binary(unsigned int	un);
int		push_all_from_b_to_a2(t_two_stacks *ab, int print_operations);
int		inverse_a(t_two_stacks *abs, int print_operations);
void	change_ab(t_two_stacks *ab);
char	change_id(char *c);
char	the_other(char c);
void	free_stack(t_stk ***a);
int	is_sorted(t_two_stacks *ab);
void	print_ints(t_stk	**a);
void	print_all_info(t_stk	**a);

#endif
