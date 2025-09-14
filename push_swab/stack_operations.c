/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:39:23 by marvin            #+#    #+#             */
/*   Updated: 2025/09/02 15:15:21 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

struct Node	*createNode(int value)
{
	struct Node	*newNode;

	newNode = (struct Node *)malloc(sizeof(struct Node));
	if (newNode == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	newNode->data = value;
	newNode->process = 'u';
	newNode->binary[0] = '\0';
	newNode->next = NULL;
	newNode->prev = NULL;
	return (newNode);
}

void	appendNode(struct Node **head, int value)
{
	struct Node	*newNode;
	struct Node	*temp;

	newNode = createNode(value);
	// printf("Created node with value: %d, process: %c\n", newNode->data,
	//	newNode->process);
	if (*head == NULL)
	{
		*head = newNode;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
	// printf("Appended node with value: %d, process: %c\n", newNode->data,
	//	newNode->process);
}

void	push(struct Node **src, struct Node **dest)
{
	struct Node	*temp;

	if (*src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	temp->next = *dest;
	if (*dest != NULL)
		(*dest)->prev = temp;
	*dest = temp;
}

void	pop(struct Node **stack)
{
	struct Node	*temp;

	if (*stack == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
	temp->next = NULL;
}

void	rotate(struct Node **stack)
{
	struct Node	*tail;
	struct Node	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = temp;
}

void	reverse_rotate(struct Node **stack)
{
	struct Node	*current;
	struct Node	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	temp = current;
	current->prev->next = NULL;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}
void	swap(struct Node **stack)
{
	struct Node	*first;
	struct Node	*second;
	struct Node	*third;

	first = *stack;
	second = first->next;
	third = second->next;
	*stack = second;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
}

void	printStack(struct Node *stack)
{
	while (stack != NULL)
	{
		printf("%d -> ", stack->data);
		stack = stack->next;
	}
	printf("NULL\n");
}

void	freeList(struct Node *head)
{
	struct Node	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
