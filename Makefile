# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 10:09:08 by kmeixner          #+#    #+#              #
#    Updated: 2022/09/13 18:05:15 by kmeixner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	containers

SRCS		=	main.cpp

CC			=	c++

RM			=	rm

CFLAGS		=	-Wall -Werror -Wextra -std=c++98 -g

all:		$(NAME)

$(NAME):	$(SRCS)
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:		
			$(RM) -f $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re
