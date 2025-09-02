/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:39:34 by fekandle          #+#    #+#             */
/*   Updated: 2025/07/07 13:26:31 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	maxlen;

	maxlen = len;
	i = 0;
	if (!src[i])
		return ((char *)(dst));
	if (ft_strncmp(dst + i, src, ft_strlen(src)) == 0)
		return ((char *)(dst + i));
	while (i + ft_strlen(src) <= maxlen && i <= ft_strlen(dst))
	{
		if (ft_strncmp(dst + i, src, ft_strlen(src)) == 0)
			return ((char *)(dst + i));
		else
			i++;
	}
	return (NULL);
}

/*

get		maxLen;
get		String1;
	if string1 empty return (dst);
move to	String2;
if current position[i] + strlen(src) < maxLen
{
check if first char of string1 match char of string2;
if true, check 2 char of string match 2 char of string 2, and so forth;
if false, iterrate string2 by one and try again until maxLen;
}


*/