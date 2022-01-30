/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 14:50:04 by alorain           #+#    #+#             */
/*   Updated: 2022/01/29 18:53:25 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_closest(t_list **stack, t_list *elem)
{
	t_list	*temp;
	t_list	*closest;
	int		value;
	int		highest;
	int		lowest;

	highest = define_highest(stack);
	lowest = define_lowest(stack);
	closest = *stack;
	if (elem->content > highest || elem->content < lowest)
	{
		while (closest->content != lowest)
			closest = closest->next;
		return (closest);
	}
	temp = *stack;

	while (closest->content - elem->content < 0)
		closest = closest->next;
	while (temp)
	{
		value = temp->content - elem->content;
		if (value > 0 && value < closest->content - elem->content)
			closest = temp;
		temp = temp->next;
	}
	return (closest);
}

int	calculate_b_cost(t_list **stack_b, t_list *elem)
{
	int	size;
	int	idx;
	int	op;

	if (!stack_b)
		return (0);
	op = 0;
	idx= ft_lstidx(elem->content, stack_b);
	size = ft_lstsize(*stack_b);
	if (idx > size / 2)
		op = size - idx;
	else
		op = idx;
	return (op);
}

int	calculate_a_cost(t_list **stack_a, t_list *elem)
{
	t_list	*closest;
	int		size;
	int		idx;
	int		op;

	if (!*stack_a)
		return (0);
	closest = find_closest(stack_a, elem);
	size = ft_lstsize(*stack_a);
	idx = ft_lstidx(closest->content, stack_a);
	if (idx > size / 2)
		op = size - idx;
	else
		op = idx;
	return (op);
}


int	calculate_cost(t_list **stack_a, t_list **stack_b, t_list *elem)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (!*stack_a || ft_lstsize(*stack_a) == 1)
		a = 0;
	else
		a = calculate_a_cost(stack_a, elem);
	b = calculate_b_cost(stack_b, elem);
	return (a + b + 1);
}
