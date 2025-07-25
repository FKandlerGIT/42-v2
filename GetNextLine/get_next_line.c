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
	ssize_t	bytes_read;

	char	*buffer;
	char	*buffer_a;
	char	*output;
	char	*newline_ptr;
	char	*temp2;
}			t_gnl;

char	*resize(char *origin, char *buffer_a)
{
	char	*new_origin;
	if (!origin && !buffer_a)
	return (NULL);
	if(origin == NULL)
	{
		new_origin = ft_calloc(ft_strlen(buffer_a) + 1,1);
		ft_strlcpy(new_origin, buffer_a, ft_strlen(buffer_a) + 1);
	}
	else if (buffer_a == NULL)
	{
		new_origin = ft_calloc(ft_strlen(origin) + 1,1);
		ft_strlcpy(new_origin, origin, ft_strlen(origin) + 1);
	}
	else
	{
		new_origin = ft_calloc(ft_strlen(origin) + ft_strlen(buffer_a) + 1, 1);
		ft_strlcpy(new_origin, origin, ft_strlen(origin) + 1);
		ft_strlcat(new_origin, buffer_a, ft_strlen(origin) + ft_strlen(buffer_a) + 1);
	}
	free(origin);
	return (new_origin);
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
char	*gnl_helper(int fd, char *temp, t_gnl *data)
{
while (temp && !ft_strchr(temp, '\n'))
	{
		data.bytes_read = read(fd, data.buffer2, BUFFER_SIZE);
		if (data.bytes_read <= 0)
			break ;
		data.buffer2[data.bytes_read] = '\0';
		data.newline_ptr = ft_strchr(data.buffer2, '\n');
		if (!data.newline_ptr)
			temp = resize(temp, data.buffer2);
		else
		{
			data.temp2 = ft_calloc((data.newline_ptr - data.buffer2) + 2,
					sizeof(char));
			ft_strlcpy(data.temp2, data.buffer2, (data.newline_ptr
					- data.buffer2 + 2));
			data.output = resize(temp, data.temp2);
			temp = NULL;
			temp = resize(NULL, data.newline_ptr + 1);
		}
	}
	return (temp);
}
char	*get_next_line(int fd)
{
	t_gnl		data;
	static char	*temp;

	data.temp2 = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data.buffer2 = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!data.buffer2)
	return (NULL);
	temp = gnl_helper(fd, temp, &data);
	free(data.buffer2);
	if (!data.output && temp && *temp != '\0')
	{
		data.output = temp;
		temp = NULL;
	}
	return (data.output);
}
