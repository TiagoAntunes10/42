PRE = ./srcs/
HEADER = includes
SOURCE = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SOURCES = ${addprefix $(PRE), $(SOURCE)}

NAME = libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror

OBJ = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $(OBJ)

.c.o:
	cc $(FLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)
    
clean: 
	rm -f $(OBJ)
        
fclean: clean
	rm -f $(NAME)

re: fclean all
