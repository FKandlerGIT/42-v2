/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 20:28:48 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/10 20:35:20 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = (n == 0);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int num)
{
	int		length;
	long	n;
	char	*str;
	int		negative;

	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	negative = (num < 0);
	length = count_digits(num) + negative;
	str = ft_calloc(length + 1, sizeof(char));
	if (!str)
		return (NULL);
	n = num;
	if (negative)
	{
		str[0] = '-';
		n = -(long)num;
	}
	str[length] = '\0';
	while (length-- > negative)
	{
		str[length] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

/*
** First of all I check if my value is equal to MIN_INT.
** If so, I return it directly as a string, since I return
** all values as positive in the string and just add the minus
** sign at the start.
** But because 2147483648 does not exist as a positive int,
** I return it immediately.
** Then I check if the number is negative, and if so, I
** remember to place the minus char at position 0.
** Next I count the length of my int +1 if negative, then
** allocate that length +1 for the '\0' terminator.
** I then verify if allocation was successful. Finally, I use
** long to avoid sign issues or overflows, then iterate
** backwards through the string, converting digits into chars.
*/