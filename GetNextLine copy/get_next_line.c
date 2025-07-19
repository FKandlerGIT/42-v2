/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:54:01 by fkandler          #+#    #+#             */
/*   Updated: 2025/07/19 16:08:31 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct get_next_line
{
	char	*buffer2;
	int		fd;
	size_t	size;
	size_t	count;
	size_t	bytes_read;
	size_t	len_buffer;
	size_t	len_buffer2;
	size_t	len_temp;
	size_t	len_temp2;

	char	*buffer;
	char	*buffer_a;
	char	*output;
	char	*newline_ptr;
	char	*temp2;
}			t_gnl;

char	*resize(char *origin, char *buffer_a)
{
	char	*buffer;

	buffer = ft_calloc(ft_strlen(origin) + 1, 1);
	ft_strlcpy(buffer, origin, ft_strlen(origin) + 1);
	free(origin);
	origin = ft_calloc(ft_strlen(buffer) + ft_strlen(buffer_a) + 1, 1);
	ft_strlcpy(origin, buffer, ft_strlen(buffer) + 1);
	ft_strlcat(origin, buffer_a, ft_strlen(buffer) + ft_strlen(buffer_a) + 1);
	free(buffer);
	return (origin);
}
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
char	*get_next_line(int fd)
{
	t_gnl		data;
	static char	*temp;

	data.temp2 = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!temp)
		temp = ft_calloc(1, 1);
	data.buffer2 = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (temp && !ft_strchr(temp, '\n'))
	{
		data.bytes_read = read(fd, data.buffer2, BUFFER_SIZE);
		data.buffer2[data.bytes_read] = '\0';
		if (data.bytes_read <= 0)
			break ;
		data.newline_ptr = ft_strchr(data.buffer2, '\n');
		if (!ft_strchr(data.buffer2, '\n'))
			temp = resize(temp, data.buffer2);
		else
		{
			free(data.temp2);
			data.temp2 = ft_calloc((data.newline_ptr - data.buffer2) + 1,
					sizeof(char));
			ft_strlcpy(data.temp2, data.buffer2, (data.newline_ptr
					- data.buffer2 + 1));
			data.output = ft_calloc(ft_strlen(temp) + 1, sizeof(char));
			ft_strlcpy(data.output, temp, ft_strlen(temp) + 1);
			data.output = resize(data.output, data.temp2);
			free(temp);
			temp = ft_calloc(ft_strlen(data.newline_ptr + 1) + 1, sizeof(char));
			ft_strlcpy(temp, data.newline_ptr + 1, ft_strlen(data.newline_ptr
					+ 1) + 1);
			if (!temp)
				return (NULL);
			break ;
		}
	}
	free(data.buffer2);
	if (!data.output && temp && *temp != '\0')
	{
		data.output = temp;
		temp = NULL;
	}
	return (data.output);
}
