# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tas <tas@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 13:16:07 by tas               #+#    #+#              #
#    Updated: 2023/05/15 09:56:45 by tas              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= MyAwsomePhonebook

OBJ_PATH 	= obj/

SRC_NAME 	= Contact.cpp PhoneBook.cpp main.cpp \

OBJ_NAME 	= $(SRC_NAME:.cpp=.o)

SRC 		= $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ 		= $(addprefix $(OBJ_PATH),$(OBJ_NAME))

CC 			= c++
FLAGS 		= -Wall -Wextra -Werror -std=c++98
RM 			= @rm -rf

DEPS_NAME 	= $(SRC_NAME:.cpp=.d)
DEPS 		= $(addprefix $(OBJ_PATH),$(DEPS_NAME))

all: $(NAME)

$(NAME): Makefile $(OBJ)
		@echo "______ _                       ______             _    "
		@echo "| ___ \ |                      | ___ \           | |   "
		@echo "| |_/ / |__   ___  _ __   ___  | |_/ / ___   ___ | | __"
		@echo "|  __/| '_ \ / _ \| '_ \ / _ \ | ___ \/ _ \ / _ \| |/ /"
		@echo "| |   | | | | (_) | | | |  __/ | |_/ / (_) | (_) |   < "
		@echo "\_|   |_| |_|\___/|_| |_|\___| \____/ \___/ \___/|_|\_|"
		@echo ""
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
