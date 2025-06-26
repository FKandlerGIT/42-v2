/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkandler <fkandler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:54:01 by fkandler          #+#    #+#             */
/*   Updated: 2024/02/02 16:37:46 by fkandler         ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	length;

	length = ft_strlen(s) + 1;
	new_str = (char *)malloc(length);
	if (new_str == NULL)
		return (NULL);
	ft_strcpy(new_str, s);
	return (new_str);
}

char	*ft_strchr(const char *str, char letter)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)letter)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (str[i] == (char)letter)
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}

// int main()
// {
// 	char *line;
// 	int fd;

// 	fd = open("test.txt", 0);
//	while(*line == '\0')
//	{
//		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
//	}

// 	close(fd);
// 	return (0);
// }