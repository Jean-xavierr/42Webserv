# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 15:03:53 by jereligi          #+#    #+#              #
#    Updated: 2021/04/08 14:59:58 by jereligi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOR :

EOC = \033[0m
BOLD = \033[1m
RED = \033[91m
GREEN = \033[92m
YELLOW = \033[93m
BLUE = \033[94m
PURPLE = \033[95m
CYAN = \033[96m

# ############################################################################ #


NAME = mini_serv

SRC = 	mini_serv.cpp			\
		./GNL/get_next_line.cpp \
		./GNL/gnl_utils.cpp

OBJ = $(SRC:.cpp=.o)

CC = clang++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all : 
			@printf "$(BOLD)Make $(RED)$(NAME)$(EOC)"
			@printf " $(BOLD)with$(EOC) $(BLUE)$(CC)$(EOC) $(CYAN)$(CPPFLAGS)$(EOC):\n"
			@make $(NAME)

$(NAME) :	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
			
clean :
			rm -rf $(OBJ)

fclean : clean
			rm -rf $(NAME)

re : fclean all
