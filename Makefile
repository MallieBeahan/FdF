# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 15:25:33 by jjory-ca          #+#    #+#              #
#    Updated: 2019/09/22 15:36:48 by jjory-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAG = -Wall -Wextra -Werror
SRC = 
OBG = $(SRC:.c=.o)

all: $(NAME)

		make -C libft/
		gcc $(FLAG) -I libft/ -c $(SRC)
		gcc $(FLAG) -o $(NAME) $(OBJ)
		@echo "\033[1;32mfdf was built\033[0m"
clean:
		rm -rf $(OBJ)
		make -C libft/ clean
		@echo "\033[3;36mObjects cleaned\033[0m"

fclean: clean
		rm -rf $(NAME)
		make -C libft/ fclean
		@echo "\033[3;36mProject fully cleaned\033[0m"

re: fclean all

norm:
	norminette
