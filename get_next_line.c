/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:18:17 by ylabrahm          #+#    #+#             */
/*   Updated: 2022/11/10 12:24:07 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*s_line(char *string)
{
	char	*line;
	int		i;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!(line))
		return (0);
	i = 0;
	while (string[i] && string[i] != '\n')
	{
		line[i] = string[i];
		i++;
	}
	if (string[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*s_strnig(char *string)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (string[i] && (string[i] != '\n'))
		i++;
	if (string[i] == '\n')
		i++;
	if (!(string[i]))
	{
		free(string);
		return (0);
	}
	temp = (char *)malloc(ft_strlen(string) - i + 1);
	if (!temp)
		return (0);
	j = 0;
	while (string[i])
		temp[j++] = string[i++];
	temp[j] = '\0';
	free(string);
	return (temp);
}

char	*ft_reader(int fd, char *string)
{
	char	*buffer;
	int		b;

	buffer = NULL;
	b = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	while (b && !(ft_strchr(string, '\n')))
	{
		b = read(fd, buffer, BUFFER_SIZE);
		if (b < 0)
		{
			free(buffer);
			buffer = (NULL);
			free(string);
			string = (NULL);
			return (0);
		}
		buffer[b] = '\0';
		string = ft_strjoin(string, buffer);
	}
	free(buffer);
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*line;

	string = ft_reader(fd, string);
	if (!(string))
	{
		free(string);
		string = (NULL);
		return (0);
	}
	line = s_line(string);
	string = s_strnig(string);
	if (!(line[0]))
	{
		free(line);
		return (NULL);
	}
	return (line);
}
