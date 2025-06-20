/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:03:00 by codespace         #+#    #+#             */
/*   Updated: 2025/06/20 17:47:16 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_str(char *c)
{
	int	len;

	len = 0;
	if (c == NULL)
		return (0);
	len = ft_strlen(c);
	ft_putstr_fd(c, 1);
	return (len);
}
