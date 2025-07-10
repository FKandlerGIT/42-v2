/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:54:01 by fkandler          #+#    #+#             */
/*   Updated: 2025/07/10 17:45:06 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct get_next_line
{
	char	*buffer2;
	int		fd;
	size_t	size;
	size_t	count;
	size_t	i;
	size_t	len_buffer2;
	size_t	len_temp;
	size_t	len_temp2;
	size_t	len_buffer;

	char	*str_start;
	char	*output;
	char	*newline_ptr;
	char	*temp;
	char	*temp2;
}			t_gnl;

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*p;
	size_t			sum;
	size_t			i;

	i = 0;
	sum = count * size;
	if (count != 0 && size > ((size_t)-1) / count)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	p = ptr;
	while (i < sum)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}

void	ft_putstr_fd(const char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
char	*get_next_line(int fd)
{
	t_gnl		data;
	static char	*buffer;

	data.count = 0;
	data.i = 0;
	data.temp = ft_calloc(1, 1);
	data.temp2 = ft_calloc(1, 1);
	data.buffer2 = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	data.len_buffer2 = ft_strlen(data.buffer2);
	data.len_temp = ft_strlen(data.temp);
	data.len_temp2 = ft_strlen(data.temp2);
	data.len_buffer = ft_strlen(buffer);
	data.output = 0;
	//
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// else if (buffer != NULL)
	//	buffer = ft_calloc(data.len_buffer + data.len_temp + data.len_buffer2
	//			+ 1, 1);
	//
	//
	//
	//
	while (buffer == NULL && data.buffer2 == NULL)
	{
		read(fd, data.buffer2, BUFFER_SIZE);
		if (buffer == NULL && ft_strchr(data.buffer2, '\n'))
			buffer = ft_calloc(data.len_temp + data.len_buffer2 + 1, 1);
		//
		//
		while (data.buffer2 != NULL)
		{
			data.i = 0;
			if (!ft_strchr(data.buffer2, '\n'))
				buffer = ft_strjoin(data.temp, data.buffer2);
			if (data.newline_ptr = ft_strchr(data.buffer2, '\n'))
			{
				ft_strlcpy(data.temp2, data.buffer2, (data.newline_ptr
						- data.buffer2 + 1));
				ft_strlcpy(data.temp, data.newline_ptr + 1,
					ft_strlen(data.newline_ptr + 1) + 1);
			}
			buffer = ft_calloc(data.len_buffer + data.len_temp2 + data.len_buffer2 + 1, 1)
			
		}
		free(data.buffer2);
		free(data.temp);
	}
	//
	//
	return (buffer);
	free(buffer);
}

// char	*get_next_line(int fd)
//{
//	static char	*temp_leftovers;
//	char		*line;

//	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) == -1)
//	{
//		if (temp_leftovers)
//			free(temp_leftovers);
//		temp_leftovers = NULL;
//		return (NULL);
//	}
//	temp_leftovers = read_file(temp_leftovers, fd);
//	if (!temp_leftovers)
//		return (NULL);
//	line = get_nline(temp_leftovers);
//	temp_leftovers = get_leftovers(temp_leftovers);
//	return (line);
//}

// char	*get_nline(const char *buffer)
//{
//	int		i;
//	int		j;
//	char	*result;

//	i = 0;
//	j = 0;
//	if (buffer[i] == '\0')
//		return (NULL);
//	while (buffer[i] != '\n' && buffer[i] != '\0')
//		i++;
//	if (buffer[i] == '\n')
//		result = (char *)malloc(i + 2 );
//	else
//		result = (char *)malloc(i + 1 );
//	if (!result)
//		return (NULL);
//	while (j < i)
//	{
//		result[j] = buffer[j];
//		j++;
//	}
//	if (buffer[i] == '\n')
//		result[j++] = buffer[i];
//	result[j] = '\0';
//	return (result);
//}

// char	*get_leftovers(char *buffer)
//{
//	int		i;
//	int		j;
//	char	*result;

//	i = 0;
//	while (buffer[i] != '\n' && buffer[i] != '\0')
//		i++;
//	if (buffer[i] == '\0')
//		return (free(buffer), NULL);
//	result = (char *)malloc((ft_strlen(buffer) - i + 1));
//	if (result == NULL)
//		return (NULL);
//	i++;
//	j = 0;
//	while (buffer[i])
//	{
//		result[j++] = buffer[i++];
//	}
//	free(buffer);
//	return (result);
//}

// char	*read_file(char *leftovers, int fd)
//{
//	char	*buffer;
//	ssize_t	bytesread;
//	char	*temp;

//	if (!leftovers)
//		leftovers = malloc(1);
//	buffer = malloc(BUFFER_SIZE + 1);
//	if (!buffer)
//		return (NULL);
//	while (!ft_strchr(leftovers, '\n'))
//	{
//		bytesread = read(fd, buffer, BUFFER_SIZE);
//		if (bytesread < 0)
//			return (free(leftovers), free(buffer), NULL);
//		if (bytesread == 0)
//			break ;
//		buffer[bytesread] = '\0';
//		temp = ft_strjoin(leftovers, buffer);
//		free(leftovers);
//		leftovers = temp;
//		if (!leftovers)
//			return (free(buffer), NULL);
//	}
//	return (free(buffer), leftovers);
//}