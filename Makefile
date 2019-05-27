NAME = vferry.filler
SRCS = $(wildcard srcs/*.c)
OBJS = $(patsubst srcs/%.c,objs/%.o,$(SRCS))
GNL_INC = get_nextline.h
INCLUDES = includes/
LIBFT_INC = libft/includes
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

objs/%.o: srcs/%.c
	gcc -c $(FLAGS) $< -o $@ -I $(INCLUDES)

$(NAME): $(OBJS)
	make -C libft/ 
	gcc -o $(NAME) $(FLAGS) $(OBJS) -I$(INCLUDES) -L libft -lft

clean:
	/bin/rm -f $(OBJS)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

test:
	gcc -I$(INCLUDES) -L libft -lft test.c $(SRCS)

re: fclean all