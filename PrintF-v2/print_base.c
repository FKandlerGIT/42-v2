/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:38:02 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/20 18:02:16 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsign(unsigned long n, unsigned long base, const char *symbols, int fd)
{
	int	count;

	count = 0;
	if (n >= base)
	{
		count = unsign(n / base, base, symbols, fd);
		ft_putchar_fd(symbols[n % base], fd);
		return (count + 1);
	}
	else if (n < base)
		ft_putchar_fd(symbols[n], fd);
	return (1);
}
