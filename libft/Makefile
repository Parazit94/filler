# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vferry <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 12:37:56 by vferry            #+#    #+#              #
#    Updated: 2018/12/08 18:23:47 by vferry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

INC = ./includes/

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJ): $(SRC)
	gcc -Wall -Wextra -Werror -c $(SRC) -I$(INC)
