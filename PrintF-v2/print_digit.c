/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:38:54 by codespace         #+#    #+#             */
/*   Updated: 2025/06/26 15:10:19 by fekandle         ###   ########.fr       */
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
		return (1);
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
	ft_putnbr_fd((long)m, 1);
	return (len);
}
