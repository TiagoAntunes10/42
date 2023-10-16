PRE = ./
HEADER = ./
FUNCTION = ./libft

SOURCE = ft_printf.c

SOURCES = ${addprefix $(PRE), $(SOURCE)}

NAME = libftprintf.a
LIB = $(FUNCTION)/libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror -g

OBJ = $(SOURCES:.c=.o)

all: $(NAME)
	norminette $(FUNCTION)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $@ $(OBJ) $(LIB)

.c.o:
	$(CC) $(FLAGS) -I $(HEADER) -I $(FUNCTION) -c $< -o $(<:.c=.o)

$(LIB):
	$(MAKE) -C $(FUNCTION)

clean: 
	rm -f $(OBJ)
	$(MAKE) clean -C $(FUNCTION)
        
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(FUNCTION)

re: fclean all