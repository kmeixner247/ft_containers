# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 10:09:08 by kmeixner          #+#    #+#              #
#    Updated: 2022/10/05 23:27:35 by kmeixner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	containers

SRCS		=	main.cpp

CC			=	c++

RM			=	rm

CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g

all:		
	sh run.sh

vector:
	$(CC) $(CFLAGS) -o $(NAME) ./tests/vector_tests.cpp && leaks --atExit -- ./$(NAME)

map:
	$(CC) $(CFLAGS) -o $(NAME) ./tests/map_tests.cpp && leaks --atExit -- ./$(NAME)

stack:
	$(CC) $(CFLAGS) -o $(NAME) ./tests/stack_tests.cpp && leaks --atExit -- ./$(NAME)
	
set:
	$(CC) $(CFLAGS) -o $(NAME) ./tests/set_tests.cpp && leaks --atExit -- ./$(NAME)

clean:		
			$(RM) -f $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re vector map stack set
