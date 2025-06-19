/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:38:54 by codespace         #+#    #+#             */
/*   Updated: 2025/06/19 13:35:31 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_digit(int n)
{
	int	len;
	int	m;

	m = n;
	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		len++;
		n = n / 10;		// exampl: 1234 is one number, by dividing it i split it in '1' size "chars" that i can count
	}
	ft_putnbr_fd(m, 1);
	return (len);
}
