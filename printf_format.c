/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:41:10 by codespace         #+#    #+#             */
/*   Updated: 2025/06/19 14:36:52 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_format(char format, va_list args)
{
	if (format == 'd' || format == 'i')
		return (print_digit(va_arg(args, int)));
	else if (format == 's')
		return (print_str(va_arg(args, char *)));
	else if (format == 'x')
		return (unsigned_fd(va_arg(args, unsigned int), 16, "0123456789abcdef",
				1));
	else if (format == 'X')
		return (unsigned_fd(va_arg(args, unsigned int), 16, "0123456789ABCDEF",
				1));
	else if (format == 'u')
		return (unsigned_fd(va_arg(args, unsigned int), 10, "0123456789", 1));
	return (0);
}

(unsigned int n, int base, const char *symbols, int fd)