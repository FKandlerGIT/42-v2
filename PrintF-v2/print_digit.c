/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:38:54 by codespace         #+#    #+#             */
/*   Updated: 2025/07/01 13:46:41 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(int n)
{
	int		len;
	long	m;

	m = n;
	len = 0;
	if (m == 0)
	{
		ft_putnbr_fd(0, 1);
		return (1);
	}
	if (m < 0)
	{
		len++;
		m = -m;
	}
	while (m != 0)
	{
		len++;
		m = m / 10;
	}
	ft_putnbr_fd((long)n, 1);
	return (len);
}
