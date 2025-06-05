/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:48:00 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/04 19:23:03 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *s, unsigned char c, size_t n)
{
	unsigned char *ptr = s;
	size_t i;
	i = n;
	while(i > 0)
	{
		i--;
		ptr[i] = c;
	}
	return s;
}

/*
Using int c isntead of unsigned char c would overcomplicate things,
because in the case of memset, you're dealing with byte-level operations.
Since only the  least significant byte of the Integer will be used to fill the memory anyways,
there's no need to use a larger  datatype like int.
*/