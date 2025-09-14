/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:38:23 by marvin            #+#    #+#             */
/*   Updated: 2025/09/14 01:38:07 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include "Libft-v2/libft.h"
# include "PrintF-v2/ft_printf.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct Variable
{
	int			i;
	int			value;
	int			newValue;
	int			j;
	int			first;
	int			second;
	int			third;
}				ps;

struct			Node
{
	int			data;
	char		process;
	char		binary[10];

	struct Node	*next;
	struct Node	*prev;
};

typedef struct sorting
{
	int			i;
	char		bit;
	int			bitIndex;
	int			count;
	int			maxBits;
}				sort;

typedef enum move_command
{
	pa,
	pb,
	sa,
	ra,
	rb,
	rr,
	rrr,
}				cmd;

int				list_length(struct Node *head);

struct Node		*createNode(int value);
void			push(struct Node **src, struct Node **dest);
void			pop(struct Node **stack);
void			swap(struct Node **stack);
void			rotate(struct Node **stack);
void			reverse_rotate(struct Node **stack);
void			printStack(struct Node *stack);
//
void			loadNumbersFromFile(const char *filename, struct Node **head);

struct Node		*findLowestUnprocessedNumber(struct Node *head);
int				processLowestUnprocessedNumber(struct Node *head, int newValue);
void			intToBinary(int value, char *binary, int bitSize);
void			updateBinaryRepresentation(struct Node *head);
void			appendNode(struct Node **head, int value);
void			printList(struct Node *head);
int				allProcessed(struct Node *head);
void			countingSort(struct Node **head, int bit);
void			radixSort(struct Node **head);
void			freeList(struct Node *head);
int				is_integer(char *str);
int				check_for_dupes(struct Node *head);
int				check_all_ints(char *list[], int size);
void			Sorting(struct Node **head);
int				main(int argc, char *argv[]);
int				bitSize(struct Node *data);
int				ft_overflow(int result, int digit, int sign);
int				check_overflow_single(char *str);
int				countStack(struct Node *Stack_A);
int				move_and_write(cmd command, struct Node **Stack_A,
					struct Node **Stack_B);
void			move_Stacks(struct Node **Stack_A, struct Node **Stack_B,
					int bitIndex);
void			sort_3(struct Node **head);
void			sort_5(struct Node **head);

int				ft_atoi(const char *str);

#endif