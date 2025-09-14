/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:39:30 by marvin            #+#    #+#             */
/*   Updated: 2025/09/14 00:57:03 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_for_dupes(struct Node *head)
{
	struct Node	*current;
	struct Node	*duplicateFinder;

	current = head;
	duplicateFinder = NULL;
	while (current != NULL)
	{
		duplicateFinder = current->next;
		while (duplicateFinder != NULL)
		{
			if (current->data == duplicateFinder->data)
				return (1);
			duplicateFinder = duplicateFinder->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_integer(char *str)
{
	if (*str == '-' || *str == '+')
	{
		str++;
		if (!is_digit(*str))
			return (0);
	}
	while (*str)
	{
		if (*str == '\0' || !is_digit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	check_all_ints(char *list[], int size)
{
	char	*arg;
	int		i;

	i = 0;
	while (i < size)
	{
		arg = list[i];
		if (*arg == '\0')
			return (1);
		// Check if it's just a '+' or '-'
		if ((*arg == '+' || *arg == '-') && *(arg + 1) == '\0')
			return (1);
		if (*arg == '+' || *arg == '-')
			arg++;
		while (*arg)
		{
			if (!is_digit(*arg))
				return (1);
			arg++;
		}
		i++;
	}
	return (0);
}
// int check_all_ints(char *list[], int size)
//{
//	char *arg;
//	int i;

//	i = 0;
//	while (i < size)
//	{
//		arg = list[i];

//		if (*arg == '\0')
//		{
//			printf("Invalid: Empty argument\n");
//			return (1);
//		}
//		// Check if it's just a '+' or '-'
//		if ((*arg == '+' || *arg == '-') && *(arg + 1) == '\0')
//		{
//			printf("Invalid: Standalone sign\n");
//			return (1);
//		}
//		if (*arg == '+' || *arg == '-')
//			arg++;
//		while (*arg)
//		{
//			if (!is_digit(*arg))
//			{
//				printf("Invalid: Non-digit character '%c'\n", *arg);
//				return (1);
//			}
//			arg++;
//		}
//		i++;
//	}
//	return (0);
//}
