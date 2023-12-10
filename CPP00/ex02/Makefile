# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tas <tas@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 10:03:02 by tas               #+#    #+#              #
#    Updated: 2023/05/15 10:05:51 by tas              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= accounts

OBJ_PATH 	= obj/

SRC_NAME 	= Account.cpp	tests.cpp \

OBJ_NAME 	= $(SRC_NAME:.cpp=.o)

SRC 		= $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ 		= $(addprefix $(OBJ_PATH),$(OBJ_NAME))

CC 			= c++
FLAGS 		= -Wall -Wextra -Werror -g -std=c++98
RM 			= @rm -rf

DEPS_NAME = $(SRC_NAME:.cpp=.d)
DEPS = $(addprefix $(OBJ_PATH),$(DEPS_NAME))

all: $(NAME)

$(NAME): Makefile $(OBJ)
		@echo "Build $(NAME)"
		@$(CC) $(FLAGS) $(INC) $(OBJ) -o $(NAME) $(LIBS) -MMD

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
		mkdir -p $(@D)
		$(CC) $(FLAGS) $(INC) -MMD -o $@ -c $<

-include $(DEPS)

clean:
		$(RM) $(OBJ_PATH)

fclean:	clean
		$(RM) $(NAME)
	
re:	fclean
	make all

.PHONY: all clean fclean re