# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 14:00:36 by fekandle          #+#    #+#              #
#    Updated: 2025/06/11 14:22:00 by fekandle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a
CC =	cc
CFLAGS =	-Wall -Wextra -Werror
SRC =	$(wildcard *.c)
OBJ =	$(SRC: .c = .o)
LIBFT	=	libft
LIBFT_MAKE	=	make -C $(LIBFT)

all:	$(OBJ)

$(NAME):	$(OBJ)
					$(LIBFT_MAKE)
					$(AR)	rcs	$(NAME)	$(OBJ)

%.o:	%.c
					$(CC)	$(CFLAGS)	-c	$<	-o	$@

clean:
					rm	-f	$(OBJ)
					$(LIBFT_MAKE) clean

fclean:		clean
					rm	-f	$(NAME)
					$(LIBFT_MAKE) fclean

re:		fclean	all