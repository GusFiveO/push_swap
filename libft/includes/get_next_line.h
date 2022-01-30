/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:16:19 by alorain           #+#    #+#             */
/*   Updated: 2022/01/12 12:47:10 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# define GNL_BUFFER_SIZE 64

char	*get_next_line(int fd);
	/* get_next_line_utils.c */

char	*ft_strdup2(char *str);
char	*ft_strjoin2(char *s1, char *s2);
int		ft_isin2(char *str, char c);
size_t	optilen(char *str);

#endif
