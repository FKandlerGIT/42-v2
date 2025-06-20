# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 14:00:36 by fekandle          #+#    #+#              #
#    Updated: 2025/06/20 18:09:56 by fekandle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard *.c) 
OBJ = $(SRC:.c=.o)
LIBFT = Libft
LIBFT_MAKE = make -C $(LIBFT)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)/libft.a
	$(AR) rcs $(NAME) $(OBJ) 
	
$(LIBFT)/libft.a:
		$(LIBFT_MAKE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ)
	$(LIBFT_MAKE) clean

fclean: clean
	rm -f $(NAME)
	$(LIBFT_MAKE) fclean

re: fclean all
