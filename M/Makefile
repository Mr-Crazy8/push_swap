CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = error_checker.c indexing.c operations.c push_swap.c \
	push_swap_util.c sorte_tree_and_five.c util0.c \
	util1.c util2.c util3.c ft_atoi.c
OBJS = $(SRCS:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean