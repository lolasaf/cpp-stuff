# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/05 22:33:10 by wel-safa          #+#    #+#              #
#    Updated: 2025/06/06 00:47:17 by wel-safa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= zombie
CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

SRCS	= zombieHorde.cpp Zombie.cpp main.cpp
OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re