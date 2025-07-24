# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/23 18:13:03 by hugo-mar          #+#    #+#              #
#    Updated: 2025/07/24 13:29:14 by hugo-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = materiaWorld

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS_PATH = ./srcs/

SRCS = $(SRCS_PATH)main.cpp $(SRCS_PATH)Ice.cpp \
       $(SRCS_PATH)Cure.cpp $(SRCS_PATH)AMateria.cpp \
	   $(SRCS_PATH)Character.cpp $(SRCS_PATH)MateriaSource.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
