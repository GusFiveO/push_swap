/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:23:23 by alorain           #+#    #+#             */
/*   Updated: 2022/01/19 12:52:16 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		signe;
	int		ret;

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

size_t	ft_atoi2(const char *str)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	while (ft_isdigit(str[i]))
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}	
	return (ret);
}
