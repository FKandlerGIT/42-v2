# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 14:00:36 by fekandle          #+#    #+#              #
#    Updated: 2025/09/02 15:16:03 by fekandle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswab.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = list_prep.c main.c  sort.c stack_operations.c validation.c ps_helper.c 
OBJ = $(SRC:.c=.o)
LIBFT = Libft-v2
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
