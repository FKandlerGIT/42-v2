/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_prep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:38:45 by marvin            #+#    #+#             */
/*   Updated: 2025/08/04 11:45:50 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

struct Node *findLowestUnprocessedNumber(struct Node *head)
{
	struct Node *lowestNode = NULL;
	struct Node *current = head;

	while (current != NULL)
	{
		if (current->process == 'u')
		{
			if (lowestNode == NULL || current->data < lowestNode->data)
			{
				lowestNode = current;
			}
		}
		current = current->next;
	}
	return (lowestNode);
}

// Function to process the lowest unprocessed number
int processLowestUnprocessedNumber(struct Node *head, int newValue)
{
	struct Node *lowestNode = findLowestUnprocessedNumber(head);
	if (lowestNode != NULL)
	{
		lowestNode->data = newValue; // Assign the new sequential number
		lowestNode->process = 'p';	 // Mark as processed
		return (1);
	}
	return (0);
}
int bitSize(struct Node *data)
{
    int count = 0;
    struct Node *temp = data;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if(count == 0)
    return(0);

    int bitLength = 0;
    while((1 << bitLength) < count)
        bitLength++;
    return bitLength;
}

// Function to convert an integer to a binary string (always 9 bits)
void intToBinary(int value, char *binary, int bitSize)
{
	int i;

	i = 0;
	while(i < bitSize)
	{
		binary[i] = '0';
		i++;
	}

	i = bitSize -1;

	while (i >= 0)
	{
		if (value & 1)
			binary[i] = '1';
		else
			binary[i] = '0';
		value >>= 1;
		i--;
	}
	binary[bitSize] = '\0';
}

// Function to update the binary representation of each node
void updateBinaryRepresentation(struct Node *head)
{
	struct Node *current = head;
	while (current != NULL)
	{
		//printf("Updating Node with data: %d\n", current->data); // Debug print

		int bitLength = bitSize(head);
		intToBinary(current->data, current->binary, bitLength);

		//printf("Binary representation: %s\n", current->binary); // Verify conversion
		current = current->next;
	}
}

int allProcessed(struct Node *head)
{
	struct Node *current = head;
	while (current != NULL)
	{
		if (current->process == 'u')
			return (0);			 // Return 0 if any node is unprocessed
		current = current->next; // Move to the next node
	}
	return (1); // Return 1 if all nodes are processed
}
