# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marene <marene@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/03 09:20:33 by marene            #+#    #+#              #
#    Updated: 2014/04/29 14:01:03 by marene           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		ft_select
CC =		cc
LIBFLAGS =	-L ./libft/ -lft -ltermcap
CFLAGS =	-Wall -Wextra -Werror -c -g -I ./includes -I ./libft/includes -o
LFLAGS =	-o
SRC_DIR =	./src/
OBJ_DIR =	./obj/
SRC =		main.c\
			info_term.c\
			is_ret_esc_spa.c\
			init.c\
			signal.c\
			display.c\
			is_del.c\
			links.c\
			send_selected.c\
			prog.c\
			is_arrow.c
OBJ = $(SRC:.c=.o)

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir $@

$(NAME): $(addprefix $(OBJ_DIR), $(OBJ))
	@echo "\033[A\033[2K"
	@echo "\033[0;032m[SELECT: COMPILING: \
	\033[0;33mDONE\033[0;32m]\033[0m\033[B"
	@make -C ./libft/ re
	@$(CC) $(LIBFLAGS) $^ $(LFLAGS) $(NAME)
	@echo "\033[0;32m[SELECT: LINKING: \033[0;33mDONE\033[0;32m]\033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $@ $<
	@echo "\033[A\033[2K\033[0;32m[SELECT: COMPILING: \033[0;33m$@\033[0;32m]"

clean:
	@rm -rf  $(OBJ_DIR)
	@echo "\033[A\033[2K\033[0;32m[SELECT: CLEANING: \033[0;33m$@\033[0;32m]"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;32m[SELECT: CLEANING: \033[0;33mDONE\033[0;32m]\033[0m\033[B"

re: fclean all

.PHONY: clean fclean re all
