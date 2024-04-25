PRE = ./
HEADER = ./
FUNCTION = ./libft
BONUS = ./bonus/

SOURCE = fractol.c errors.c ft_atod.c mlx_utils.c mlx_hooks.c \
		utils.c mandel.c

# SOURCE_BON = checker_bonus.c push_swap_bonus.c utils_bonus.c \
# 			 moveset_cross_bonus.c moveset_mult_bonus.c \
# 			 moveset_stack_bonus.c

SOURCES = ${addprefix $(PRE), $(SOURCE)}
SOURCES_BON = ${addprefix $(BONUS), $(SOURCE_BON)}

NAME = fractol
NAME_BONUS = fractol_bonus
LIB = $(FUNCTION)/libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror -g 
LIB_FLAGS = -lm -lmlx -lXext -lX11

OBJ = $(SOURCES:.c=.o)
OBJ_BON = $(SOURCES_BON:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	cc $(FLAGS) -o $@ $^ $(LIB_FLAGS)

$(LIB):
	$(MAKE) -C $(FUNCTION)

.c.o:
		$(CC) $(FLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BON) $(LIB)
	cc $(FLAGS) -o $@ $^

.c.o2:
	$(CC) $(FLAGS) -I $(BONUS) -c $< -o $(<:.c=.o)

clean: 
	rm -f $(OBJ) $(OBJ_BON)
	$(MAKE) clean -C $(FUNCTION)
        
fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) fclean -C $(FUNCTION)

re: fclean all
