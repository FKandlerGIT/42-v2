/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:41:10 by codespace         #+#    #+#             */
/*   Updated: 2025/06/26 15:06:30 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char format, va_list *ap)
{
	if (format == 'c')
		return (print_char(va_arg(*ap, int)));
	else if (format == 'd' || format == 'i')
		return (print_digit(va_arg(*ap, int)));
	else if (format == 's')
		return (print_str(va_arg(*ap, char *)));
	else if (format == 'x')
		return (unsign(va_arg(*ap, unsigned int), 16, "0123456789abcdef", 1));
	else if (format == 'X')
		return (unsign(va_arg(*ap, unsigned int), 16, "0123456789ABCDEF", 1));
	else if (format == 'u')
		return (unsign(va_arg(*ap, unsigned int), 10, "0123456789", 1));
	else if (format == '%')
		return (print_percent());
	else if (format == 'p')
		return (print_ptr(va_arg(*ap, void *)));
	return (0);
}
