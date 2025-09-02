/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:43:34 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/10 18:51:56 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			index;
	char			*result;

	i = 0;
	index = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	result = (char *)ft_calloc(i + 1, sizeof(char));
	if (result == 0)
		return (0);
	while (index < i)
	{
		result[index] = f(index, s[index]);
		index++;
	}
	result[i] = '\0';
	return (result);
}

/*

	You do not change any characters directly just with the index.
	ft_strmapi simply goes through each character of your string,
	and for each one, it calls your custom function and says:
	“Hey, this is character 'c',
		and it’s at position index. What do you want to do with it?”
	Your function decides whether to leave it, change it,
		or do something fancy based on that index.

*/