# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Clkuznie <cluznie@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 14:09:03 by clkuznie          #+#    #+#              #
#    Updated: 2021/11/12 01:12:52 by Clkuznie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	cpp_test

SRC_EXTENSION		:= \
	.cpp

H_EXTENSION			:= \
 	.hpp

SRC_NAME			:= \
	main

H_NAME				:= \
	MutantStack

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

$(O_DIR)%.o:		$(S_DIR)%$(SRC_EXTENSION) %$(H_EXTENSION) $(addsuffix $(H_EXTENSION), $(H_NAME)) Makefile
	$C $(CFLAGS) $I -c $< -o $@

all:				$(NAME)

debug: CFLAGS += -DDEBUG -g
debug: all

$(NAME):			$O
	$C $^ -o $@

clean:
	$R $O

fclean:				clean
	$R $(NAME)

re:					fclean all

.PHONY: all clean fclean re
