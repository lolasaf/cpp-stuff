# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/05 18:54:46 by wel-safa          #+#    #+#              #
#    Updated: 2025/06/05 19:38:02 by wel-safa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= myAwesomePhoneBook
CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

SRCS	= Contact.cpp PhoneBook.cpp main.cpp
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
