/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:27:56 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/02 19:17:21 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;
	size_t i;
	i = 0;
	
	if(dest == src || n == 0)
	return dest;

	if (d< s)
	ft_memcpy(dest, src, n);

	else
	{
		i = n;
		while (i  > 0)
		{
			i--;
			d[i] = s[i];
		}
	}

	return dest;
}
