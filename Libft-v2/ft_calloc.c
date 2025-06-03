/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:00:41 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/03 14:34:13 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_calloc(size_t count, size_t size)
{
	void *ptr;

		ptr = malloc(count * size);
		
		if (!ptr)
		return NULL;
		
		ft_bzero(ptr, count * size);
			return ptr;
			
}
