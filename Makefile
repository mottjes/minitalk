# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 12:54:50 by mottjes           #+#    #+#              #
#    Updated: 2024/01/09 15:06:40 by mottjes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client

NAMES = server

SRC =  	src/client.c			\
		src/server.c			\
		src/utils.c 			\

OBJS = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: ${NAMEC} $(NAMES)

${NAMEC}: $(OBJS)
	$(CC) $(FLAGS) src/client.o src/utils.o -o client

${NAMES}: $(OBJS)
	$(CC) $(FLAGS) src/server.o src/utils.o -o server

src/%.o: %.c
	$(CC) $(FLAGS) $(SRC) -c -o $@ $<

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f client server

re: fclean all

.PHONY: all clean fclean re
