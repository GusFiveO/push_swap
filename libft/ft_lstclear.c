/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:28:18 by alorain           #+#    #+#             */
/*   Updated: 2022/01/22 13:51:14 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*nxt;

	temp = *lst;
	while (temp)
	{
		nxt = temp->next;
		free(temp);
		temp = nxt;
	}
	*lst = NULL;
}
