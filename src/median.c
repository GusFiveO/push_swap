/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <augustinlorain@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:09:02 by augustinlor       #+#    #+#             */
/*   Updated: 2022/01/30 15:09:05 by augustinlor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	define_median(t_list **stack_a, int	size)
{
	t_list	*temp;
	int		tab[size];
	int		lower;
	int		i;

	i = 0;
	while (i < size)
		tab[i++] = INT_MAX;
	i = 0;
	while (i < size)
	{
		lower = tab[i];
		temp = *stack_a;
		while (temp)
		{
			if (temp->content < lower && !ft_isin(tab, temp->content, size))
				lower = temp->content;
			temp = temp->next;
		}
		tab[i++] = lower;
	}
	return (tab[size / 2]);
}

t_list	*define_cheapest_med(t_list **stack_a, int m)
{
	t_list	*temp;
	t_list	*cheapest;
	int		cost;

	temp = *stack_a;
	cheapest = NULL;
	while (temp)
	{
		cost = calculate_b_cost(stack_a, temp);
		if ((!cheapest && temp->content < m ) ||
				(temp->content < m && calculate_b_cost(stack_a, cheapest) > cost))
			cheapest = temp;
		temp = temp->next;
	}
	return (cheapest);
}

int	med_lower_free(t_list **stack_a, int m)
{
	t_list	*temp;

	temp = *stack_a;
	while (temp)
	{
		if (temp->content < m)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	push_med_low(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;
	int		median;
	int		size;

	size = ft_lstsize(*stack_a);
	median = define_median(stack_a, size);
	cheapest = define_cheapest_med(stack_a, median);
	while (!med_lower_free(stack_a, median))
	{
		cheapest = define_cheapest_med(stack_a, median);
		size = ft_lstsize(*stack_a);
		while (*stack_a != cheapest)
		{
			if (ft_lstidx(cheapest->content, stack_a) > size / 2)
				rra(stack_a);
			else
				ra(stack_a);
		}
		pb(stack_a, stack_b);
	}
}			
