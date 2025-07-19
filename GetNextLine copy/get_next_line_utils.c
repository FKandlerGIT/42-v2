/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:54:33 by fkandler          #+#    #+#             */
/*   Updated: 2025/06/26 13:03:38 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while ((i + 1 < size) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= dstlen)
		return (size + srclen);
	while ((i < size - dstlen - 1) && (src[i] != '\0'))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	len1 = 0;
	len2 = 0;
	if (!str1 && !str2)
		return (NULL);
	if (str1 != NULL)
		len1 = ft_strlen(str1);
	if (str2 != NULL)
		len2 = ft_strlen(str2);
	res = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (str1)
		ft_strlcpy(res, str1, len1 + len2 + 1);
	if (str2)
		ft_strlcat(res, str2, len1 + len2 + 1);
	return (res);
}
