/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overflow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 00:09:18 by fekandle          #+#    #+#             */
/*   Updated: 2025/09/14 01:45:52 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_overflow(int result, int digit, int sign)
{
	int	int_max;

	int_max = 2147483647;
	if (sign == 1)
	{
		if (result > (int_max / 10) || (result == (int_max / 10) && digit > 7))
		{
			ft_printf("Number is too high");
			return (1);
		}
	}
	if (sign == -1)
	{
		if (result > (int_max / 10) || (result == (int_max / 10) && digit > 8))
		{
			ft_printf("Number is too low");
			return (1);
		}
	}
	return (0);
}
