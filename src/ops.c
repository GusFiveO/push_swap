/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:21:31 by alorain           #+#    #+#             */
/*   Updated: 2022/01/31 18:27:40 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_op(t_op *op)
{
	op->rra = 0;
	op->ra = 0;
	op->rrb = 0;
	op->rb = 0;
}

void	calculate_b_op(t_list **stack_b, t_list *cheapest, t_op *op)
{
	int	size;
	int	idx;

	idx = ft_lstidx(cheapest->content, stack_b);
	size = ft_lstsize(*stack_b);
	if (idx > size / 2)
		op->rrb = size - idx;
	else
		op->rb = idx;
}

void	calculate_a_op(t_list **stack_a, t_list *cheapest, t_op *op)
{
	t_list	*closest;
	int		size;
	int		idx;

	if (!*stack_a)
		return ;
	closest = find_closest(stack_a, cheapest);
	size = ft_lstsize(*stack_a);
	idx = ft_lstidx(closest->content, stack_a);
	if (idx > size / 2)
		op->rra = size - idx;
	else
		op->ra = idx;
}

void	execute_ops(t_list **stack_a, t_list **stack_b, t_op op)
{
	while (op.rra && op.rrb)
	{
		rrr(stack_a, stack_b);
		op.rra--;
		op.rrb--;
	}
	while (op.ra && op.rb)
	{
		rr(stack_a, stack_b);
		op.ra--;
		op.rb--;
	}
	while (op.rra--)
		rra(stack_a);
	while (op.rrb--)
		rrb(stack_b);
	while (op.ra--)
		ra(stack_a);
	while (op.rb--)
		rb(stack_b);
	pa(stack_a, stack_b);
}

t_op	calculate_op(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	t_op	op;

	init_op(&op);
	calculate_a_op(stack_a, cheapest, &op);
	calculate_b_op(stack_b, cheapest, &op);
	return (op);
}
