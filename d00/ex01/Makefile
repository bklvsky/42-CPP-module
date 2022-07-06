# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 23:55:23 by dselmy            #+#    #+#              #
#    Updated: 2022/04/18 04:00:09 by dselmy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp Contact.cpp PhoneBook.cpp
OBJS			= $(SRCS:.cpp=.o)
DEP				= $(SRCS:.cpp=.d)

CXX				= c++
RM				= rm -f
CXXFLAGS		= -std=c++98 -Wall -Wextra -Werror -I.

NAME			= myPhoneBook

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) -MD

%.o:			%.cpp
				$(CXX) -c $(CXXFLAGS) $< -o $@ -MD

clean:
				$(RM) $(OBJS) $(DEP)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

include $(wildcard $(DEP))

.PHONY:			all clean fclean re
