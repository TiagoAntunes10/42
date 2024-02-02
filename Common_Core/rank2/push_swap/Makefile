PRE = ./
HEADER = ./
FUNCTION = ./libft
# BONUS = ./bonus/

SOURCE = push_swap.c utils.c checker.c moveset_cross.c \
		moveset_mult.c moveset_stack.c sorters.c cost.c \
		final_steps.c
# SOURCE_BON = checkers_bonus.c main_bonus.c limiter_bonus.c \
			 # mult_pipe_bonus.c path_pars_bonus.c utils_bonus.c

SOURCES = ${addprefix $(PRE), $(SOURCE)}
# SOURCES_BON = ${addprefix $(BONUS), $(SOURCE_BON)}

NAME = push_swap
LIB = $(FUNCTION)/libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror -g

OBJ = $(SOURCES:.c=.o)
# OBJ_BON = $(SOURCES_BON:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	cc $(FLAGS) -o $@ $^

$(LIB):
	$(MAKE) -C $(FUNCTION)

.c.o:
		$(CC) $(FLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

# bonus: $(OBJ_BON) $(LIB)
#	cc $(FLAGS) -o $(NAME) $^

# .c.o2:
#		$(CC) $(FLAGS) -I $(BONUS) -c $< -o $(<:.c=.o)

clean: 
	rm -f $(OBJ)
	$(MAKE) clean -C $(FUNCTION)
        
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(FUNCTION)

re: fclean all
