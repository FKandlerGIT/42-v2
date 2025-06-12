/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:10:29 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/12 21:10:52 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_digit(long number, int base, const char *symbols)
{
	int count;

	count = 0;
	if (symbols == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}

	if (number < 0)
	{
		write(1, "-", 1);
		return (print_digit(-number, base, symbols) + 1);
	}
	else if (number < base)
	{
		return (print_char(symbols[number]));
	}
	else
	{
		count = print_digit(number / base, base, symbols);
		return (count + print_digit(number % base, base, symbols));
	}
}
