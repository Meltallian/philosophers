/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:05:08 by jbidaux           #+#    #+#             */
/*   Updated: 2023/11/14 15:06:35 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*rem_read(int fd, char *left, char *buffer)
{
	char	*tmp;
	ssize_t	bytes;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (left);
			return (0);
		}
		else if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		if (!left)
			left = ft_strdup("");
		tmp = left;
		left = ft_strjoin(tmp, buffer);
		free (tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left);
}

char	*cut(char *str)
{
	char	*cut_str;
	ssize_t	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0' || str[0] == 0)
		return (NULL);
	cut_str = ft_substr(str, i + 1, ft_strlen(str) - i);
	if (!*cut_str)
	{
		free (cut_str);
		cut_str = 0;
	}
	str[i + 1] = '\0';
	return (cut_str);
}

char	*get_next_line(int fd)
{
	static char	*left[FOPEN_MAX];
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		free (buffer);
		if (fd > 0)
		{
			free(left[fd]);
			left[fd] = NULL;
		}
		buffer = NULL;
		return (0);
	}
	line = rem_read(fd, left[fd], buffer);
	free (buffer);
	buffer = 0;
	if (!line)
		return (0);
	left[fd] = cut(line);
	return (line);
}
