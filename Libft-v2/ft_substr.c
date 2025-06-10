/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:48:44 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/10 18:52:01 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	strlength;
	char	*substring;

	strlength = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start >= strlength)
		return (ft_strdup(""));
	if (start + len > strlength)
		len = strlength - start;
	substring = (char *)malloc(len + 1);
	if (substring == NULL)
		return (NULL);
	ft_strlcpy(substring, s += start, len + 1);
	return (substring);
}
