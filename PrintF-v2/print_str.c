/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:03:00 by codespace         #+#    #+#             */
/*   Updated: 2025/06/20 20:00:44 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *c)
{
	int	len;

	len = 0;
	if (c == NULL)
	{
		if (write(1, "(null)", 6) == -1)
		{
			return (-1);
		}
		return (6);
	}
	while (*c != '\0')
	{
		print_char((int)*c);
		len++;
		c++;
	}
	return (len);
}
