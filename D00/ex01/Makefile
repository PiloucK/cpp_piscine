# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 14:09:03 by clkuznie          #+#    #+#              #
#    Updated: 2021/05/02 14:00:37 by clkuznie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	intercom_explorer

SRC_EXTENSION		:= \
	.cpp

H_EXTENSION			:= \
	.hpp

SRC_NAME			:= \
	$(NAME) \
	CIntercomContact

H_NAME				:= \
	CIntercomContact

S_DIR		 		:= \
	./

O_DIR				:= \
	./

I					:= \
	-I ./

O					= \
	$(addprefix $(O_DIR), $(addsuffix .o, $(SRC_NAME)))

C					:= clang++
CFLAGS				:= -Wall -Wextra -Werror -std=c++98

R					:= rm -f

$(O_DIR)%.o:		$(S_DIR)%$(SRC_EXTENSION)
	$C $(CFLAGS) $I -c $< -o $@

all:				$(NAME)

$(NAME):			$O
	$C $^ -o $@

clean:
	$R $O

fclean:				clean
	$R $(NAME)

re:					fclean all

.PHONY: all clean fclean re
