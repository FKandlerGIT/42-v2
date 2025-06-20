/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:17:20 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/20 20:12:16 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(void *p)
{
	unsigned long	ptr;
	int				count;

	count = 0;
	ptr = (unsigned long)p;
	if (p == NULL)
		return (print_str("0x0"));
	else
	{
		count += print_str("0x");
		count += unsign(ptr, 16, "0123456789abcdef", 1);
	}
	return (count);
}
