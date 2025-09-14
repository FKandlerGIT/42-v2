/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:38:58 by marvin            #+#    #+#             */
/*   Updated: 2025/09/14 01:50:31 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_and_exit_on_dupes(struct Node *head)
{
	if (check_for_dupes(head))
	{
		printf("Duplicate Numbers.\n");
		return (1);
	}
	return (0);
}
int	check_overflow_single(char *str)
{
	int	result;
	int	sign;
	int	j;
	int	digit;

	result = 0;
	sign = 1;
	j = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		j = 1;
	}
	while (str[j])
	{
		digit = str[j] - '0';
		if (ft_overflow(result, digit, sign))
			return (1);
		result = result * 10 + digit;
		j++;
	}
	return (0); // safe
}

int	main(int argc, char *argv[])
{
	struct Node	*head;
	int			i;
	int			value;
	int			newValue;
	int			j;
	int			count;

	head = NULL;
	i = 1;
	newValue = 0;
	if (argc < 2)
	{
		printf("Usage: %s <numbers>\n", argv[0]);
		return (1);
	}
	if (check_all_ints(argv + 1, argc - 1))
	{
		printf("argc: %d\n", argc);
		j = 0;
		while (j < argc)
		{
			printf("argv[%d]: %s\n", j, argv[j]);
			j++;
		}
		printf("Invalid Input\n");
		return (1);
	}
	while (i < argc)
	{
		if (check_overflow_single(argv[i]))
		{
			printf("Number out of int range\n");
			return (1);
		}
		value = ft_atoi(argv[i]);
		appendNode(&head, value);
		i++;
	}
	if (check_and_exit_on_dupes(head))
		return (1);
	while (!allProcessed(head))
	{
		processLowestUnprocessedNumber(head, newValue);
		newValue++;
	}
	printStack(head);
	count = argc - 1;
	if (count == 3)
		sort_3(&head);
	else if (count == 5)
		sort_5(&head);
	else
	{
		updateBinaryRepresentation(head);
		Sorting(&head);
	}
	printStack(head);
	if (!allProcessed(head))
	{
		printf("Sorting Failed.\n");
		return (1);
	}
	printf("%d\n", count);
	return (0);
}
