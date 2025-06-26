/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkandler <fkandler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:54:33 by fkandler          #+#    #+#             */
/*   Updated: 2024/02/02 16:37:48 by fkandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*output;
	char	*buffer;
	int		total;

	total = count * size;
	output = malloc(total);
	if (output == NULL)
		return (NULL);
	buffer = output;
	while (total-- > 0)
	{
		*buffer++ = 0;
	}
	return (output);
}

char	*read_file(char *leftovers, int fd)
{
	char	*buffer;
	ssize_t	bytesread;
	char	*temp;

	if (!leftovers)
		leftovers = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
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

// char	*ft_strjoin(char *str1, const char *str2)
//{
//    char	*result;
//    size_t	length1 = 0;
//    size_t	length2 = 0;
//    size_t	i = 0;
//    if (str1)
//        while (str1[length1] != '\0') length1++;
//    if (str2)
//        while (str2[length2] != '\0') length2++;

//    result = (char *)ft_calloc(length1 + length2 + 1, sizeof(char));
//    if (!result) return (NULL);

//    while (str1 && *str1) {
//        result[i] = *str1++;
//        i++;
//    }

//    while (str2 && *str2) {
//        result[i] = *str2++;
//        i++;
//    }

//    return (result);
//}
char	*ft_strjoin(char *str1, const char *str2)
{
	char	*result;
	size_t	length1;
	size_t	length2;
	size_t	i;

	length1 = 0;
	length2 = 0;
	if (str1)
		length1 = ft_strlen(str1);
	else
		length1 = 0;
	if (str2)
		length2 = ft_strlen(str2);
	else
		length2 = 0;
	result = (char *)ft_calloc(length1 + length2 + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (str1 && str1[++i])
		result[i] = str1[i];
	while (str2 && *str2)
		result[i++] = *str2++;
	return (result);
}

size_t	ft_strlen(const char *str)
{
	int			i;
	const char	*j;

	j = str;
	i = 0;
	while (j[i] != 0)
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	{
		i = 0;
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = src[i];
		return (dst);
	}
}
