/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:19:11 by alorain           #+#    #+#             */
/*   Updated: 2022/01/29 12:49:09 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;

	temp_a = *stack_a;
	if (!*stack_a)
		return ;
	ft_printf("pb\n");
	if (!(*stack_a)->next)
		*stack_a = NULL;
	*stack_a = temp_a->next;
	temp_a->next = *stack_b;
	*stack_b = temp_a;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_b;

	temp_b = *stack_b;
	if (!*stack_b)
		return ;
	ft_printf("pa\n");
	if (!(*stack_b)->next)
		*stack_b = NULL;
	*stack_b = temp_b->next;
	temp_b->next = *stack_a;
	*stack_a = temp_b;
}

void	sa(t_list **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		ft_printf("sa\n");
		ft_swap(&(*stack_a)->content, &(*stack_a)->next->content);
	}
}

void	sb(t_list **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		ft_printf("sb\n");
		ft_swap(&(*stack_b)->content, &(*stack_b)->next->content);
	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		ft_printf("ss\n");
		ft_swap(&(*stack_a)->content, &(*stack_a)->next->content);
		ft_swap(&(*stack_b)->content, &(*stack_b)->next->content);
	}
}
