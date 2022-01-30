/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:21:31 by alorain           #+#    #+#             */
/*   Updated: 2022/01/29 18:22:11 by alorain          ###   ########.fr       */
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

t_op	calculate_op(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	t_op	op;
//	t_list	*temp;

	init_op(&op);
//	temp = *stack_b;
//	(void)cheapest;
//	while (temp)
//	{	
//		init_op(&op);
//		calculate_a_op(stack_a, temp, &op);
//		calculate_b_op(stack_b, temp, &op);
//		ft_printf("current %3d: rra %3d, ra %3d, rrb %3d, rb %3d\n",temp->content, op.rra, op.ra, op.rrb, op.rb);	
//		temp = temp->next;
//	}
	calculate_a_op(stack_a, cheapest, &op);
	calculate_b_op(stack_b, cheapest, &op);
	//ft_printf("rra %3d, ra %3d, rrb %3d, rb %3d\n", op.rra, op.ra, op.rrb, op.rb);	
	return (op);
}

