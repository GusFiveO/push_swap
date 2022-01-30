/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:18:21 by alorain           #+#    #+#             */
/*   Updated: 2022/01/29 17:39:29 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_op
{
	int	rra;
	int	ra;
	int	rrb;
	int	rb;
}	t_op;

/*-----utils.c-----*/

int		ft_lstidx(int content, t_list **stack);
long	ft_strtol(const char *str);
void	print_stacks(t_list **stack_a, t_list **stack_b);
void	ft_swap(int *a, int *b);
int		define_lowest(t_list **stack_a);
int		define_highest(t_list **stack_a);
int		ft_isin(int *tab, int content, int count);

/*-----parse_args.c-----*/

int		check_args(int argc, char **argv);
int		fill_stack(int argc, char **argv, t_list **stack_a);

/*-----sort.c-----*/

t_list	*find_cheapest(t_list **stack_a, t_list **stack_b);
void	sort_stack(t_list **satck_a, t_list **stack_b);

/*-----cost.c-----*/

int		calculate_cost(t_list **stack_a, t_list **stack_b, t_list *elem);
int		calculate_b_cost(t_list **stack_b, t_list *elem);
t_list	*find_closest(t_list **stack, t_list *elem);

/*-----ops.c-----*/

t_op	calculate_op(t_list **stack_a, t_list **stack_b, t_list *cheapest);

/*-----operation.c-----*/

void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_a);

/*-----operation.c-----*/

void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

/*-----median.c-----*/

int		define_median(t_list **stack_a, int	size);
void	push_med_low(t_list **stack_a, t_list **stack_b);
#endif
