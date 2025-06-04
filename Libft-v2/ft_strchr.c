/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:25:24 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/04 19:39:42 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	size_t i;
	i = 0;
	
	while(s[i] != '\0')
	{
		if(s[i] == (unsigned char) c)
			return (s + i);
	
		i++;
	}
	if(c == '\0')
		return(s + i);
	return NULL;
}
