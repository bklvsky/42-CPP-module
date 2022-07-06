# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 23:55:23 by dselmy            #+#    #+#              #
#    Updated: 2022/05/05 01:05:06 by dselmy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	Animal.cpp \
					Cat.cpp \
					Dog.cpp \
					WrongAnimal.cpp \
					WrongCat.cpp \
					main.cpp
OBJS			= $(SRCS:.cpp=.o)
DEP				= $(SRCS:.cpp=.d)

CXX				= c++
RM				= rm -f
CXXFLAGS		= -std=c++98 -Wall -Wextra -Werror -I.

NAME			= animals

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o:			%.cpp
				$(CXX) -c $(CXXFLAGS) $< -o $@ -MD

clean:
				$(RM) $(OBJS) $(DEP)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

include $(wildcard $(DEP))

.PHONY:			all clean fclean re
