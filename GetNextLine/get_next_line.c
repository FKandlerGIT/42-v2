/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:54:01 by fkandler          #+#    #+#             */
/*   Updated: 2025/06/26 13:05:33 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*temp_leftovers;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) == -1)
	{
		if (temp_leftovers)
			free(temp_leftovers);
		temp_leftovers = NULL;
		return (NULL);
	}
	temp_leftovers = read_file(temp_leftovers, fd);
	if (!temp_leftovers)
		return (NULL);
	line = get_nline(temp_leftovers);
	temp_leftovers = get_leftovers(temp_leftovers);
	return (line);
}

char	*get_nline(const char *buffer)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		result = (char *)malloc(i + 2 );
	else
		result = (char *)malloc(i + 1 );
	if (!result)
		return (NULL);
	while (j < i)
	{
		result[j] = buffer[j];
		j++;
	}
	if (buffer[i] == '\n')
		result[j++] = buffer[i];
	result[j] = '\0';
	return (result);
}

char	*get_leftovers(char *buffer)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	result = (char *)malloc((ft_strlen(buffer) - i + 1));
	if (result == NULL)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
	{
		result[j++] = buffer[i++];
	}
	free(buffer);
	return (result);
}

char	*read_file(char *leftovers, int fd)
{
	char	*buffer;
	ssize_t	bytesread;
	char	*temp;

	if (!leftovers)
		leftovers = malloc(1);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(leftovers, '\n'))
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (free(leftovers), free(buffer), NULL);
		if (bytesread == 0)
			break ;
		buffer[bytesread] = '\0';
		temp = ft_strjoin(leftovers, buffer);
		free(leftovers);
		leftovers = temp;
		if (!leftovers)
			return (free(buffer), NULL);
	}
	return (free(buffer), leftovers);
}