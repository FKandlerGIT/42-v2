/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:47:28 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/03 17:35:21 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	i = 0;

	while((i + 1 < size) &&(src[i] != '\0') )
	{
		dst[i] = src[i];	
		i++;
	}
	
	if(size > 0)
		dst[i] = '\0';

	while(src[i] != '\0')
		i++;

	return i;
	
}

					