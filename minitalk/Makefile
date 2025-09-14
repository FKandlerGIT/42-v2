# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 19:31:47 by fkandler          #+#    #+#              #
#    Updated: 2025/08/01 14:15:01 by fekandle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CLIENT = client
SERVER = server

PRINTF_DIR = PrintF-v2
PRINTF = $(PRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(CLIENT) $(SERVER)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(CLIENT): ft_client.c | $(PRINTF)
	$(CC) $(CFLAGS) ft_client.c -L$(PRINTF_DIR) -lftprintf -o $(CLIENT)

$(SERVER): ft_server.c | $(PRINTF)
	$(CC) $(CFLAGS) ft_server.c -L$(PRINTF_DIR) -lftprintf -o $(SERVER)

clean:
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all
	
