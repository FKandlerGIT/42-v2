/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:30:10 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/12 21:07:11 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_format(char sign, va_list ap)
{
	int	count;

	count = 0;
	if (sign == 'c')
		count += print_char(va_arg(ap, int));
	else if (sign == 's')
		count += print_str(va_arg(ap, char *));
	else if (sign == 'd')
		count += print_digit(va_arg(ap, long), 10, "0123456789");
	else if (sign == 'x')
		count += print_digit(va_arg(ap, long), 16, "0123456789abcdef");
	else if (sign == 'X')
		count += print_digit(va_arg(ap, long), 16, "0123456789ABCDEF");
	else if (sign == 'i')
		count += print_digit(va_arg(ap, long), 10, "0123456789");
	else if (sign == 'p')
		count += print_ptr(va_arg(ap, unsigned long long), 16);
	else if (sign == 'u')
		count += print_digit((long)va_arg(ap, unsigned int), 10, "0123456789");
	else if (sign == '%')
		count += print_percent_sign();
	return (count);
}

/*
{
	if(specifier = 1, i++)
		if(str == ("c", "s", "p", "d", "i", "u", "x", "X", "%"))
			call_function(format)
	break ;
	while(str)
	{
	if(str[i] != NULL)
		i++;
	if(str[i] == '%')
		specifier = 1;
	}
}

*/