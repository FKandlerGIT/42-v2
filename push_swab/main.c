/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:38:58 by marvin            #+#    #+#             */
/*   Updated: 2025/09/02 15:30:14 by fekandle         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	struct Node	*head;
	int			i;
	int			value;
	int			newValue;
	int			j;

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
		value = atoi(argv[i]); // change to ft_atoi later
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
	int count = argc - 1; 
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
	return (0);
}
