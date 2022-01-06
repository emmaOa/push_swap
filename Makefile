MANDATORY= mouve.c\
	push_swap.c\



CC=cc
FLAGS=-Wall -Werror -Wextra -c
NAME=libft.a
O_MANDATORY=$(MANDATORY:%.c=%.o)
O_BONUS=$(BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(O_MANDATORY)

bonus: $(O_MANDATORY) $(O_BONUS)

%.o:%.c
	$(CC) $(FLAGS) $<
	ar -rc $(NAME) $@

clean:
	rm -rf *.o

fclean:
	rm -rf *.o $(NAME)

re: fclean all