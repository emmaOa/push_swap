MANDATORY= mouve.c\
	push_swap.c\



CC=cc
FLAGS=-Wall -Werror -Wextra -c
NAME=push_swap
O_MANDATORY=$(MANDATORY:%.c=%.o)
O_BONUS=$(BONUS:%.c=%.o)

all: $(NAME)

$(NAME): 
	gcc -Wall -Wextra -Werror push_swap.c push_a_negative.c push_a_positive.c mouves.c func_ut.c push_a_df.c -o push_swap

bonus: $(O_MANDATORY) $(O_BONUS)

%.o:%.c
	$(CC) $(FLAGS) $<
	ar -rc $(NAME) $@

clean:
	rm -rf *.o

fclean:
	rm -rf *.o $(NAME)

re: fclean all