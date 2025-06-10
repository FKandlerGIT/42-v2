/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 20:28:48 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/09 14:28:28 by fekandle         ###   ########.fr       */
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

	first of all i check if my value is equal the min_int, if so i return it directly
	as a string as i return all my values as positive in the string and then just putting a minus sign in beforehand,
	but because 2147483648 does not exist as a positive value in int, i return it immediatly.
	then i check if my number in generell is negative and if so i will remember the system to put a minus char at position "0",
	so it will be infront of the string.
	then i will count the length of my int + negative to allocate the right amount of space,
	as negative will only allocate + 1 if the number is negative otherwise it will be + 0 .
	then i allocate length + 1 for the '\0' terminator .
	then i check if i have a str(int) to check if allocation was succesfull.
	then ill check for negative as i explained it before,
	i will use long here to ensure no missbehavior will happen for min _int (avoid accidental overflows, avoid sign related bugs, easier adapt to larger types).
	then lastly i'll iterate backwards to my string and change my int's finally into char's

*/