/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:15:06 by alorain           #+#    #+#             */
/*   Updated: 2022/01/31 16:16:11 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*last;

	if (!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next)
		return ;
	last = ft_lstlast(*stack_b);
	temp = *stack_b;
	*stack_b = last;
	last->next = temp;
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	last = ft_lstlast(*stack_a);
	temp = *stack_a;
	*stack_a = last;
	last->next = temp;
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	ft_printf("rrr\n");
}
