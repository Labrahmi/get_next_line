/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:22:38 by ylabrahm          #+#    #+#             */
/*   Updated: 2022/11/10 12:25:33 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *array)
{
	int	i;

	i = 0;
	if (!(array))
		return (0);
	while (array[i])
		i++;
	return (i);
}

int	ft_strchr(char *string, int c)
{
	int	i;

	i = 0;
	if (string)
		while (string[i])
			if (string[i++] == (char)c)
				return (1);
	return (0);
}

char	*ft_strjoin(char *string, char *buffer)
{
	char	*temp;
	int		i;
	int		j;

	if (!(string) && !(buffer))
		return (0);
	if (!(string))
	{
		string = (char *)malloc(1 * sizeof(char));
		if (!string)
			return (0);
		string[0] = '\0';
	}
	temp = (char *)malloc(ft_strlen(string) + ft_strlen(buffer) + 1);
	if (!(temp))
		return (0);
	i = -1;
	j = 0;
	while (string[++i])
		temp[i] = string[i];
	while (buffer[j])
		temp[i++] = buffer[j++];
	temp[i] = '\0';
	free(string);
	return (temp);
}
