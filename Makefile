# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/14 15:27:59 by jtrujill          #+#    #+#              #
#    Updated: 2017/07/14 18:44:40 by jtrujill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler
INC = -I filler.h
FLAGS = gcc -Wall -Wextra -Werror

SRCS = srcs/filler_main.c srcs/get_map.c srcs/get_grid.c srcs/get_list.c \
	   srcs/get_piece.c srcs/get_grade.c srcs/shift_value.c srcs/get_place.c \
	   srcs/alt_solve.c

all: $(NAME)

$(NAME):
	@make all -C libft
	$(FLAGS) -o $(NAME) $(INC) $(SRCS) -L libft/ -lft -g

clean:
	@make clean -C libft

fclean: clean
	rm -rf $(NAME)
	@make fclean -C libft

re: fclean all
