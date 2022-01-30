/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:40:51 by alorain           #+#    #+#             */
/*   Updated: 2021/12/04 12:06:07 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	sub_len(char *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (s[start + i])
		i++;
	if (i < len)
		return (i);
	return (len);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (sub_len(s, start, len) + 1));
	if (!str)
		return (NULL);
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*parse(char **excess)
{
	char	*line;
	char	*temp;
	size_t	excess_len;
	size_t	line_len;

	excess_len = 0;
	line_len = 0;
	if (!*excess)
		return (NULL);
	excess_len = ft_strlen(*excess);
	while ((*excess)[line_len] && (*excess)[line_len] != '\n')
		line_len++;
	if ((*excess)[line_len] == '\n')
		line_len++;
	line = ft_substr(*excess, 0, line_len);
	temp = *excess;
	*excess = ft_substr(*excess, line_len, excess_len - line_len);
	free(temp);
	if ((*excess)[0] == '\0')
	{
		free(*excess);
		*excess = NULL;
	}
	return (line);
}

char	*read_file(int fd, char **excess)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE && !ft_isin(*excess, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = *excess;
		*excess = ft_strjoin(*excess, buffer);
		free(temp);
	}
	free(buffer);
	return (*excess);
}

char	*get_next_line(int fd)
{
	static char	*excess[4096];
	char		*line;
	char		buffer[1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) == -1)
		return (NULL);
	if (!excess[fd])
	{
		excess[fd] = malloc(sizeof(char));
		if (!excess[fd])
			return (NULL);
		excess[fd][0] = '\0';
	}
	excess[fd] = read_file(fd, &excess[fd]);
	line = parse(&excess[fd]);
	if (!line || ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
