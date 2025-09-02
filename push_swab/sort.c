/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:39:16 by marvin            #+#    #+#             */
/*   Updated: 2025/09/02 17:32:08 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	move_and_write(cmd command, struct Node **Stack_A, struct Node **Stack_B)
{
	if (command == pa)
	{
		push(Stack_B, Stack_A);
		printf("pa\n");
	}
	else if (command == pb)
	{
		push(Stack_A, Stack_B);
		printf("pb\n");
	}
	else if (command == ra)
	{
		rotate(Stack_A);
		printf("ra\n");
	}
	else
		return (0);
	return (1);
}

void	sort_3(struct Node **head)
{
	struct Node	*Stack_A;
	ps			v;

	Stack_A = *head;
	v.first = (*head)->data;
	v.second = (*head)->next->data;
	v.third = (*head)->next->next->data;
	if (v.first > v.second && v.second < v.third && v.first < v.third)
		swap(&Stack_A);
	else if (v.first > v.second && v.second > v.third)
	{
		swap(&Stack_A);
		reverse_rotate(&Stack_A);
	}
	else if (v.first > v.second && v.second < v.third && v.first > v.third)
		rotate(&Stack_A);
	else if (v.first < v.second && v.second < v.third && v.first > v.third)
	{
		swap(&Stack_A);
		rotate(&Stack_A);
	}
	else if (v.first < v.second && v.second > v.third && v.first > v.third)
		reverse_rotate(&Stack_A);
	*head = Stack_A;
}

void	sort_5(struct Node **head)
{
	struct Node	*Stack_A;
	struct Node	*Stack_B;

	Stack_A = *head;
	Stack_B = NULL;
	while (list_length(Stack_A) > 3)
	{
		push(&Stack_A, &Stack_B);
		printf("pb\n");
	}
	sort_3(&Stack_A);
	while(Stack_B != NULL)
	{
		push(&Stack_B, &Stack_A);
		ft_printf("pa\n");
	}
	//*head = Stack_A;
}

void	Sorting(struct Node **head)
{
	sort		s;
	struct Node	*Stack_A;
	struct Node	*Stack_B;

	if (*head == NULL)
		return ;
	s.maxBits = bitSize(*head);
	Stack_A = *head;
	Stack_B = NULL;
	s.bitIndex = s.maxBits - 1;
	while (s.bitIndex >= 0)
	{
		s.count = countStack(Stack_A);
		s.i = 0;
		while (s.i < s.count)
		{
			move_Stacks(&Stack_A, &Stack_B, s.bitIndex);
			s.i++;
		}
		while (Stack_B != NULL)
			move_and_write(pa, &Stack_A, &Stack_B);
		s.bitIndex--;
	}
	//*head = Stack_A;
	printStack(*head);
}
