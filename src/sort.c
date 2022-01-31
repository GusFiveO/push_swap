/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:08:59 by alorain           #+#    #+#             */
/*   Updated: 2022/01/31 18:27:45 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_cheapest(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*cheapest;
	int		cost;

	temp = *stack_b;
	cheapest = temp;
	while (temp)
	{
		cost = calculate_cost(stack_a, stack_b, temp);
		if (cost < calculate_cost(stack_a, stack_b, cheapest))
			cheapest = temp;
		temp = temp->next;
	}
	return (cheapest);
}

void	push_back(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;
	t_op	op;

	cheapest = find_cheapest(stack_a, stack_b);
	op = calculate_op(stack_a, stack_b, cheapest);
	execute_ops(stack_a, stack_b, op);
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	while (!is_sorted(stack_a))
		pb(stack_a, stack_b);
}

void	sort_stack(t_list **stack_a, t_list **stack_b, int argc)
{
	int	lowest;

	lowest = define_lowest(stack_a);
	if (argc <= 6)
		lil_sort(stack_a, stack_b, argc);
	else
	{
		if (argc > 101)
			push_med_low(stack_a, stack_b);
		push_to_b(stack_a, stack_b);
	}
	while (*stack_b)
		push_back(stack_a, stack_b);
	while ((*stack_a)->content != lowest)
	{
		if (ft_lstidx(lowest, stack_a) < ft_lstsize(*stack_a) / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
}
