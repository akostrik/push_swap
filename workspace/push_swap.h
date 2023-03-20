/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:24:00 by akostrik          #+#    #+#             */
/*   Updated: 2023/03/10 17:45:34 by akostrik         ###   ########.fr       */
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

typedef struct s_stk
{
	int				n;
	struct s_stk	*nxt;
	struct s_stk	*prv;
	int				place;
}	t_stk;

typedef struct s_two_stacks
{
	int		n;
	t_stk	**a;
	t_stk	**b;
	char	a_or_b;
	char	inc_or_dec;
	int		len;
}	t_two_stacks;

int		sort_1st_version(t_two_stacks *ab);
int		sort2(t_two_stacks *ab);
int		sort_5_and_shorter(t_two_stacks *ab);
void	swap(t_stk	**a, char a_or_b);
void	push(t_stk **from, t_stk **to, char a_or_b);
void	rotate(t_stk **a, char a_or_b);
void	reverse_rotate(t_stk **a, char a_or_b);
void	swap_two(t_two_stacks *ab);
int		put_args(t_stk	**a, int argc, char **argv);
int		put_int(int n, t_stk **a);
int		put_elt(t_stk	*new, t_stk **a);
int		len_(t_stk **a);
void	push_all_from_b_to_a(t_two_stacks *ab);
void	inverse_a(t_two_stacks *abs);
void	change_ab(t_two_stacks *ab);
char	change_id(char *c);
char	the_other(char c);
void	free_stack(t_stk ***a);
int		is_sorted(t_stk **a);
void	print_ints(t_stk	**a);
void	print_all_info(t_stk	**a);
//void	bubble_sort(t_stk **a);

#endif
