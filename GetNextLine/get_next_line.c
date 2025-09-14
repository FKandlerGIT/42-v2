/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:54:01 by fkandler          #+#    #+#             */
/*   Updated: 2025/07/30 15:13:42 by fekandle         ###   ########.fr       */
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
	temp_leftovers = read_line(fd, temp_leftovers);
	if (!temp_leftovers)
		return (NULL);
	line = extract_til_n(temp_leftovers);
	temp_leftovers = extract_after_n(temp_leftovers);
	return (line);
}

char	*read_line(int fd, char *leftover)
{
	char	*temp;
	char	*temp1;
	ssize_t	bytesread;

	if (!leftover)
		leftover = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	while (!ft_strchr(leftover, '\n'))
	{
		bytesread = read(fd, temp, BUFFER_SIZE);
		if (bytesread < 0)
			return (free(leftover), free(temp), NULL);
		if (bytesread == 0)
			break ;
		temp[bytesread] = '\0';
		temp1 = resize(leftover, temp);
		leftover = temp1;
		if (!leftover)
			return (free(temp), NULL);
	}
	return (free(temp), leftover);
}

char	*extract_til_n(const char *buffer)
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
		result = (char *)ft_calloc(i + 2, sizeof(char));
	else
		result = (char *)ft_calloc(i + 1, sizeof(char));
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

char	*extract_after_n(char *buffer)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	result = (char *)ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
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

char	*resize(char *origin, char *buffer_a)
{
	char	*new_origin;

	new_origin = NULL;
	if (!origin && !buffer_a)
		return (ft_calloc(1, 1));
	if (origin == NULL)
	{
		new_origin = ft_calloc(ft_strlen(buffer_a) + 1, 1);
		ft_strlcpy(new_origin, buffer_a, ft_strlen(buffer_a) + 1);
	}
	else if (buffer_a == NULL)
	{
		new_origin = ft_calloc(ft_strlen(origin) + 1, 1);
		ft_strlcpy(new_origin, origin, ft_strlen(origin) + 1);
	}
	else
	{
		new_origin = ft_calloc(ft_strlen(origin) + ft_strlen(buffer_a) + 1, 1);
		ft_strlcpy(new_origin, origin, ft_strlen(origin) + 1);
		ft_strlcat(new_origin, buffer_a, ft_strlen(origin) + ft_strlen(buffer_a)
			+ 1);
	}
	if (origin)
		free(origin);
	return (new_origin);
}
