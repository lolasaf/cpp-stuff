# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 15:51:09 by wel-safa          #+#    #+#              #
#    Updated: 2025/06/06 17:17:53 by wel-safa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= unnecessaryViolence
CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

SRCS	= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
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