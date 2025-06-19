/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:38:02 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/19 14:32:39 by fekandle         ###   ########.fr       */
/*                                                                            																					*/
/* ************************************************************************** */

#include "libftprintf.h"

int	unsign(unsigned int n, int base, const char *symbols, int fd)
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
