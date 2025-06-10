/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:36:37 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/10 18:51:49 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s);
	dst = ft_calloc(len + 1, sizeof(char));
	ft_strlcpy(dst, s, len + 1);
	return (dst);
}
