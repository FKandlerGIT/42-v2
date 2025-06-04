/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:42:03 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/04 20:13:00 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	
	size_t i;
	i = ft_strlen(s);
	if(c == '\0')
		return (s + i);
	
	while(i > 0)
	{
		i--;
		if(s[i] == (unsigned char) c)
			return (s + i);
	}
		return NULL;
}
