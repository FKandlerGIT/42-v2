/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:41:10 by codespace         #+#    #+#             */
/*   Updated: 2025/06/18 21:43:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libftprintf.h"

int print_format(char format, va_list args)
{
    if (format == 'd' || format == 'i')
        return (print_digit(va_arg(args, int)));
    else if (format == 's')
        return (print_str(va_arg(args, char *)));
    else if (format == 'x')
        return (print_hex(va_arg(args, unsigned int), "0123456789abcdef"));
    else if (format == 'X')
        return (print_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
}