# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 15:25:33 by jjory-ca          #+#    #+#              #
#    Updated: 2019/09/23 19:51:26 by jjory-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
ATTACH = -lmlx -framework OpenGL -framework AppKit -L./libft -lft


SRC = 	src/add_keys.c\
		src/axis_proj.c\
		src/ft_parsing_av.c\
		src/ft_read_av.c\
		src/linemarker.c\
		src/main.c

OBG = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		make -C libft/
		gcc  -I libft/ -c $(SRC)
		gcc  -o $(NAME) $(OBJ) $(ATTACH)
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
