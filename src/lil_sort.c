/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:02:16 by alorain           #+#    #+#             */
/*   Updated: 2022/01/31 15:19:05 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack_a)
{
	int		highest;
	int		lowest;

	highest = define_highest(stack_a);
	lowest = define_lowest(stack_a);
	if (ft_lstidx(lowest, stack_a) == 1 && ft_lstidx(highest, stack_a) == 2)
		sa(stack_a);
	if (ft_lstidx(lowest, stack_a) == 2 && ft_lstidx(highest, stack_a) == 0)
	{
		sa(stack_a);
		rra(stack_a);
	}
	if (ft_lstidx(lowest, stack_a) == 1 && ft_lstidx(highest, stack_a) == 0)
		ra(stack_a);
	if (ft_lstidx(lowest, stack_a) == 0 && ft_lstidx(highest, stack_a) == 1)
	{
		sa(stack_a);
		ra(stack_a);
	}
	if (ft_lstidx(lowest, stack_a) == 2 && ft_lstidx(highest, stack_a) == 1)
		rra(stack_a);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_3(stack_a);
}

int	is_sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	if (ft_lstsize(*stack) <= 1)
		return (1);
	while (temp->next)
	{
		if (temp->next->content < temp->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	lil_sort(t_list **stack_a, t_list **stack_b, int argc)
{
	if (argc == 4)
		sort_3(stack_a);
	else if (argc == 6)
		sort_5(stack_a, stack_b);
}
