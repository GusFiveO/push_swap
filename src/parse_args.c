/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 11:53:24 by alorain           #+#    #+#             */
/*   Updated: 2022/01/29 12:02:58 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_stack(int argc, char **argv, t_list **stack_a)
{
	t_list	*new;
	int		i;

	i = 1;
	while (i < argc)
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		if (!new)
		{
			ft_lstclear(stack_a);
			return (0);
		}
		ft_lstadd_back(stack_a, new);
		i++;
	}
	return (-1);
}

int	check_is_numeric(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_int_overflow(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 11)
			return (0);
		if (ft_strtol(argv[i]) > INT_MAX || ft_strtol(argv[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	cheack_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	if (!check_is_numeric(argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!check_int_overflow(argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!cheack_duplicate(argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}
