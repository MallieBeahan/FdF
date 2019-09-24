# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 15:25:33 by jjory-ca          #+#    #+#              #
#    Updated: 2019/09/23 21:06:57 by jjory-ca         ###   ########.fr        #
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
	make -C libft/
	gcc $(FLAGS) -I libft/ -c $(SRC)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(ATTACH)
run42:
	./fdf tests/42.fdf
clean:
	rm -f $(OBJ)
	make -C libft/ clean
fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
re: fclean all