MANDATORY= push_swap.c push_a_negative.c push_a_positive.c mouves.c func_ut.c push_a_df.c\
			instraction_b.c instraction_a.c subsequence.c push.c instraction_else.c subsequence_two.c sort_3.c
BONUS= checker.c func_checker.c get_next_line.c get_next_line_utils.c instraction_b_checker.c instraction_a_checker.c\
			instraction_else_checker.c check.c



CC=cc
FLAGS=-Wall -Werror -Wextra
DEBUG=-fsanitize=address -g
NAME=push_swap
CHECKER=checker
O_MANDATORY=$(MANDATORY:%.c=%.o)
O_BONUS=$(BONUS:%.c=%.o)

all: $(NAME)

$(NAME): 
	gcc $(FLAGS) $(MANDATORY) -o $(NAME)

debug:
	gcc $(FLAGS) $(DEBUG) $(MANDATORY) -o $(NAME)

bonus: $(CHECKER)

$(CHECKER):
	gcc $(FLAGS) $(BONUS) -o $(CHECKER)

clean:
	rm -rf *.o

fclean:
	rm -rf *.o $(NAME) $(CHECKER)

re: fclean all