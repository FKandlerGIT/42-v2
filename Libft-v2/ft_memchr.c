/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:08:25 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/03 12:03:04 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *src = ( const unsigned char *)s;
	size_t i;
	i = 0;
	
	while(i < n)
	{
		if(src[i] == (unsigned char) c)
		return (void *)(src + i);

		i++;
	}
	return NULL;
	
}

/*
	The cast to (void *) in "return (void *)(src + i)" is not strictly required for the code to work,
	because C allows implicit conversion from any object pointer type to void *.
	
	However, adding the cast makes the return type explicit and avoids compiler warnings,
	especially when using strict flags like -Wall. It ensures the returned pointer matches
	the function's declared return type: void *.
*/
