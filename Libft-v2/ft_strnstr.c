/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:39:34 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/04 20:48:31 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *dst, const char *src, size_t len)
{
	size_t i;
	size_t maxLen;
	maxLen = len;
	
	if(!src)
		return dst;

	else 
		ft_strncmp(src[i], dst[i], maxLen);
	if(src[i] == dst[i])
		return(dst + 1);
	else if(src[i] < dst[i] || (src[i] != dst[i]))
		return NULL;
	
}
