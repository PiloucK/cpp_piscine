# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 14:09:03 by clkuznie          #+#    #+#              #
#    Updated: 2021/11/06 16:26:29 by Clkuznie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	cpp_test

SRC_EXTENSION		:= \
	.cpp

H_EXTENSION			:= \
 	.hpp

SRC_NAME			:= \
	Bureaucrat \
	main

H_NAME				:=

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

all:				debug

debug: CFLAGS += -DDEBUG -g
debug: $(NAME)

$(NAME):			$O
	$C $^ -o $@

clean:
	$R $O

fclean:				clean
	$R $(NAME)

re:					fclean all

.PHONY: all clean fclean re
