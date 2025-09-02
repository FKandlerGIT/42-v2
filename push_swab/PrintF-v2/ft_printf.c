/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:03:47 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/25 18:50:30 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += print_format(*format, &ap);
		}
		else
			count += print_char(*format);
		format++;
	}
	va_end(ap);
	return (count);
}
//#include <stdio.h>

//int main(void)
//{
//    int ret;

//    // Erwartete Ausgabe: " 0x0 0x0 "
//    // Erwartete Rückgabe: 9 (Anzahl der ausgegebenen Zeichen)
//    ret = ft_printf(" %p %p ", 0, 0);
//    printf("\nft_printf returned: %d\n", ret);

//    // Zum Vergleich: printf von libc
//    ret = printf(" %p %p ", 0, 0);
//    printf("\nprintf returned: %d\n", ret);

//    return 0;
//}