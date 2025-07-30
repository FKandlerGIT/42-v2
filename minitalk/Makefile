# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 19:31:47 by fkandler          #+#    #+#              #
#    Updated: 2025/07/30 20:09:37 by fekandle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CLIENT = client
SERVER = server

LIBFTPRINTF = libftprintf.a
LIBFTPRINTF_DIR = libftprintf

CFILES = client.c server.c 
INCLUDES = minitalk.h

OBJ = $(CFILES:.c=.o)


CC = gcc
CFLAGS = #-Wall -Wextra -Werror

CFILES = ft_client.c ft_server.c 
PRINTF = ft_printf.c print_base.c print_char.c print_digit.c print_percent.c print_ptr.c print_str.c print_format.c
OBJ = $(CFILES:.c=.o)

NAME = minitalk.a

all: $(NAME)

$(NAME): $(OBJ) 
	ar rcs $(NAME) Libft/libft.a $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
test: $(NAME)
	$(CC) $(CFLAGS) ft_client.c $(PRINTF) -o $(CLIENT)
	$(CC) $(CFLAGS) ft_server.c $(PRINTF) -o $(SERVER)
	
