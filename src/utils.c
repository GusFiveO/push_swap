/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 11:26:43 by alorain           #+#    #+#             */
/*   Updated: 2022/01/29 18:03:32 by alorain          ###   ########.fr       */
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

long	ft_strtol(const char *str)
{
	size_t	i;
	long	ret;
	int		signe;

	i = 0;
	ret = 0;
	signe = 1;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	return (ret * signe);
}

void	print_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*temp_next;
	int		i;

	i = 0;
	temp = *stack_a;
	ft_printf("\n");
	while (temp)
	{
		temp_next = temp->next;
		ft_printf("a[%d] = %3d\n", i++, temp->content);
		temp = temp_next;
	}
	ft_printf("\n");
	i = 0;
	if (!stack_b)
		return ;
	temp = *stack_b;
	while (temp)
	{
		temp_next = temp->next;
		ft_printf("b[%d] = %3d\n", i++, temp->content);
		temp = temp_next;
	}
}

//void	print_stacks(t_list **stack_a, t_list **stack_b)
//{
//	t_list	*temp;
//	t_list	*temp_next;
//	int		i;
//
//	i = 0;
//	temp = *stack_a;
//	ft_printf("\n");
//	while (temp)
//	{
//		temp_next = temp->next;
//		ft_printf("a[%d] = %3d\n", i++, temp->content);
//		free(temp);
//		temp = temp_next;
//	}
//	ft_printf("\n");
//	i = 0;
//	temp = *stack_b;
//	while (temp)
//	{
//		temp_next = temp->next;
//		ft_printf("b[%d] = %3d\n", i++, temp->content);
//		free(temp);
//		temp = temp_next;
//	}
//}

int	ft_lstidx(int content, t_list **stack)
{
	t_list	*temp;
	int		idx;

	idx = 0;
	temp = *stack;
	while (temp->content != content)
	{
		idx++;
		temp = temp->next;
	}
	return (idx);
}

int	define_lowest(t_list **stack_b)
{
	t_list	*temp;
	int		lowest;

	temp = *stack_b;
	lowest = temp->content;
	while (temp)
	{
		if (temp->content < lowest)
			lowest = temp->content;
		temp = temp->next;
	}
	return (lowest);
}

int	define_highest(t_list **stack_b)
{
	t_list	*temp;
	int		highest;

	temp = *stack_b;
	highest = temp->content;
	while (temp)
	{
		if (temp->content > highest)
			highest = temp->content;
		temp = temp->next;
	}
	return (highest);
}

int	ft_isin(int *tab, int content, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (tab[i] == content)
			return (1);
		i++;
	}
	return (0);
}
