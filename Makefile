# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 15:25:33 by jjory-ca          #+#    #+#              #
#    Updated: 2019/09/24 20:22:37 by jjory-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -ggdb
ATTACH = -lmlx -framework OpenGL -framework AppKit -L./libft -lft
SRC = main.c add_keys.c axis_proj.c ft_parsing_av.c \
	  ft_read_av.c linemarker.c
OBJ = $(subst .c,.o,$(SRC))
all: $(NAME)

$(NAME):

	@echo ""
	@echo "===========[ \x1b[31mF \x1b[32mD \x1b[34mF \x1b[37m]==========="
	@echo ""
	@echo "\x1b[31m > \x1b[32mCompilation FDF...\x1b[37m"
	@echo ""
	@make -C libft/
	@echo ""
	@echo "\x1b[31m > \033[1;35mLibft was built\033[0m"
	@gcc $(FLAGS) -I libft/ -c $(SRC)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(ATTACH)
	@echo ""
	@echo "\x1b[31m > \033[1;32mProject was built\033[0m"
	
run42:
	./fdf tests/42.fdf
	
clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	@echo ""
	@echo "\x1b[31m > \033[3;36mObjects cleaned\033[0m"
	@echo ""
fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "\x1b[31m > \033[3;31mProject fully cleaned\033[0m"

re: fclean all