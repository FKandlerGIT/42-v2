/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:49:42 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/10 18:51:52 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
