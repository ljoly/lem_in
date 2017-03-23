 # *************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/24 16:34:42 by ljoly             #+#    #+#              #
#    Updated: 2017/03/22 17:20:46 by ljoly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
SRCS = main.c get_input.c check_input.c get_rooms.c get_links.c
FLAGS = -Wall -Werror -Wextra
LIBFT = ./libft/
HEADER = ./includes
OBJ = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))
OBJ_PATH = ./obj/
SRCS_PATH = ./srcs/

RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -L $(LIBFT) -lft
	@echo "$(GREEN)[✓]$(NC) Executable $(NAME) ready!"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAGS) -I $(LIBFT) -o $@ -c $<
	@echo "$(GREEN)[✓]$(NC) Compiling" $<

clean:
	@make -C $(LIBFT) clean
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)[-]$(NC) Objects cleaned..."

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -f $(NAME)
	@echo "$(RED)[-]$(NC) Executable $(NAME) cleaned..."

re: fclean all

.PHONY: $(NAME) all clean fclean re
