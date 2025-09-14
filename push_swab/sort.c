/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:39:16 by marvin            #+#    #+#             */
/*   Updated: 2025/09/14 01:59:58 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	move_and_write(cmd command, struct Node **Stack_A, struct Node **Stack_B)
{
	int	count;

	count = 0;
	if (command == pa)
	{
		push(Stack_B, Stack_A);
		printf("pa\n");
		count++;
	}
	else if (command == pb)
	{
		push(Stack_A, Stack_B);
		printf("pb\n");
		count++;
	}
	else if (command == ra)
	{
		rotate(Stack_A);
		printf("ra\n");
		count++;
	}
	else
		return (0);
	return (1);
}
void	sort_3_v2(struct Node **head)
{
	ps	v;

	v.first = (*head)->data;
	v.second = (*head)->next->data;
	v.third = (*head)->next->next->data;
	if (v.first == 2 && v.second == 4 && v.third == 3)
	{
		swap(head);
		printf("sa\n");
		rotate(head);
		printf("ra\n");
	}
	else if (v.first == 3 && v.second == 2 && v.third == 4)
	{
		swap(head);
		printf("sa\n");
	}
	else if (v.first == 3 && v.second == 4 && v.third == 2)
	{
		reverse_rotate(head);
		printf("rra\n");
	}
	else if (v.first == 4 && v.second == 2 && v.third == 3)
	{
		rotate(head);
		printf("ra\n");
	}
	else if (v.first == 4 && v.second == 3 && v.third == 2)
	{
		swap(head);
		reverse_rotate(head);
		printf("sa\n");
		printf("ra\n");
	}
}

void	sort_3(struct Node **head)
{
	ps	v;

	v.first = (*head)->data;
	v.second = (*head)->next->data;
	v.third = (*head)->next->next->data;
	if (v.first == 0 && v.second == 2 && v.third == 1)
	{
		swap(head);
		printf("sa\n");
		rotate(head);
		printf("ra\n");
	}
	else if (v.first == 1 && v.second == 0 && v.third == 2)
	{
		swap(head);
		printf("sa\n");
	}
	else if (v.first == 1 && v.second == 2 && v.third == 0)
	{
		reverse_rotate(head);
		printf("rra\n");
	}
	else if (v.first == 2 && v.second == 0 && v.third == 1)
	{
		rotate(head);
		printf("ra\n");
	}
	else if (v.first == 2 && v.second == 1 && v.third == 0)
	{
		swap(head);
		rotate(head);
		printf("sa\n");
		printf("ra\n");
	}
}

void	sort_5(struct Node **head)
{
	struct Node	*Stack_B;

	Stack_B = NULL;
	while (list_length(*head) > 3)
	{
		if ((*head)->data == 0 || (*head)->data == 1)
		{
			push(head, &Stack_B);
			ft_printf("pb\n");
		}
		else
		{
			rotate(head);
			ft_printf("rra\n");
		}
	}
	sort_3_v2(head);
	if ((Stack_B)->data != 1)
	{
		rotate(&Stack_B);
		ft_printf("rb\n");
	}
	while (Stack_B != NULL)
	{
		push(&Stack_B, head);
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
	ft_printf("%d\n , s.count");
}
