/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:54:01 by fkandler          #+#    #+#             */
/*   Updated: 2025/07/11 20:02:46 by fekandle         ###   ########.fr       */
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
	char	*str_start;
	char	*output;
	char	*newline_ptr;
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
char	*get_next_line(int fd)
{
	t_gnl		data;
	static char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!temp)
		temp = ft_calloc(1, 1);
	data.buffer = ft_calloc(1, 1);
	data.temp2 = ft_calloc(1, 1);
	data.buffer2 = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (temp && !ft_strchr(temp, '\n'))
	{
		data.bytes_read = read(fd, data.buffer2, BUFFER_SIZE);
		if (data.bytes_read <= 0)
			break ;
		if (!ft_strchr(data.buffer2, '\n'))
			ft_strlcat(temp, data.buffer2, data.len_buffer2 + data.len_temp);
		else if (data.newline_ptr = ft_strchr(data.buffer2, '\n'))
		{
			ft_strlcpy(data.temp2, data.buffer2, (data.newline_ptr
					- data.buffer2 + 1));
			data.len_temp2 = ft_strlen(data.temp2);
			data.len_temp = ft_strlen(temp);
			data.output = ft_calloc(data.len_temp, 1);
			ft_strlcpy(data.output, temp, data.len_temp);
			ft_strlcat(data.output, data.temp2, data.len_temp + data.len_temp2);
			free(temp);
			temp = ft_calloc(ft_strlen(data.newline_ptr + 1) + 1, sizeof(char));
			ft_strlcpy(temp, data.newline_ptr + 1, ft_strlen(data.newline_ptr
					+ 1) + 1);
		}
		data.len_buffer2 = ft_strlen(data.buffer2);
	}
	free(data.buffer2);
	free(data.buffer);
	free(data.temp2);
	if (!data.output && temp && *temp != '\0')
	{
		data.output = temp;
		temp = NULL;
	}
	return (data.output);
}
