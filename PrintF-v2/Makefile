# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 14:00:36 by fekandle          #+#    #+#              #
#    Updated: 2025/07/04 12:40:56 by fekandle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c print_base.c print_char.c print_digit.c \
			print_percent.c print_ptr.c print_str.c printf_format.c
OBJ = $(SRC:.c=.o)
LIBFT = Libft
LIBFT_MAKE = make -C $(LIBFT)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)/libft.a
	cp $(LIBFT)/libft.a $(NAME)
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
