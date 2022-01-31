/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:49:46 by alorain           #+#    #+#             */
/*   Updated: 2022/01/31 16:16:28 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*temp;
	t_list	*first;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	first = *stack_a;
	while (temp->next)
		temp = temp->next;
	*stack_a = first->next;
	first->next = NULL;
	temp->next = first;
	ft_printf("ra\n");
}

void	rb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*first;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	first = *stack_b;
	while (temp->next)
		temp = temp->next;
	*stack_b = first->next;
	first->next = NULL;
	temp->next = first;
	ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*first;

	if (!*stack_b || !(*stack_b)->next || !*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_b;
	first = *stack_b;
	while (temp->next)
		temp = temp->next;
	*stack_b = first->next;
	first->next = NULL;
	temp->next = first;
	temp = *stack_a;
	first = *stack_a;
	while (temp->next)
		temp = temp->next;
	*stack_a = first->next;
	first->next = NULL;
	temp->next = first;
	ft_printf("rr\n");
}

void	rra(t_list **stack_a)
{
	t_list	*temp;
	t_list	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last = ft_lstlast(*stack_a);
	temp = *stack_a;
	*stack_a = last;
	last->next = temp;
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	ft_printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last = ft_lstlast(*stack_b);
	temp = *stack_b;
	*stack_b = last;
	last->next = temp;
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	ft_printf("rrb\n");
}
