# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 23:46:05 by jaleman           #+#    #+#              #
#    Updated: 2019/09/24 20:19:53 by jjory-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a

CFLAGS	= -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(patsubst %.c,%.o,$(wildcard *.c))
	@ar rs $(NAME) $?

%.o: %.c
	@gcc $(CFLAGS) -I includes/ $<

clean:
	@/bin/rm -rf *.o

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
