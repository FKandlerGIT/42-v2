/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:17:20 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/30 13:51:49 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(void *p)
{
	unsigned long	ptr;
	int				count;

	ptr = (unsigned long)p;
	count = 0;
	if (p == NULL)
		return (print_str("(nil)"));
	else
		count += print_str("0x");
	count += unsign(ptr, 16, "0123456789abcdef", 1);
	return (count);
}
