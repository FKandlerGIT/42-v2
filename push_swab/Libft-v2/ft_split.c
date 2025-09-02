/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:25:43 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/10 18:51:25 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (NULL);
}

static int	ft_wordcount(const char *str, char symbol)
{
	int	count;
	int	word;

	count = 0;
	word = 0;
	while (*str)
	{
		if (*str == symbol)
			word = 0;
		else if (!word)
		{
			word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

/*

	count will goes up everytime it changes from 1 to 0;

*/

static char	*set_word(char **str, char symbol)
{
	int		wordlen;
	char	*result_string;

	wordlen = 0;
	while ((*str)[wordlen] && (*str)[wordlen] != symbol)
		wordlen++;
	result_string = (char *)ft_calloc((wordlen + 1), sizeof(char));
	if (!result_string)
		return (NULL);
	ft_strlcpy(result_string, *str, wordlen + 1);
	(*str) = (*str) + wordlen;
	return (result_string);
}

char	**ft_split(const char *str, char symbol)
{
	int		i;
	int		word_count;
	char	**result;
	char	*s;

	s = (char *)str;
	word_count = ft_wordcount(str, symbol);
	result = (char **)ft_calloc((word_count + 1), sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != symbol)
		{
			result[i] = set_word(&s, symbol);
			if (!result[i])
				return (free_all(result));
			i++;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
