/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 11:02:19 by alorain           #+#    #+#             */
/*   Updated: 2022/01/29 18:22:20 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		if (!check_args(argc, argv))
			return (-1);
		if (!fill_stack(argc, argv, &stack_a))
			return (-1);
		//ft_printf("median %d\n", define_median(&stack_a, ft_lstsize(stack_a))); 
		sort_stack(&stack_a, &stack_b);
		//print_stacks(&stack_a, &stack_b);
		ft_lstclear(&stack_a); 
		return (0);
	}
	ft_printf("\n");
	return (-1);
}