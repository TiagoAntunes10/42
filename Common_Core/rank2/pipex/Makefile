PRE = ./
HEADER = ./
FUNCTION = ./libraries

SOURCE = main.c 

SOURCES = ${addprefix $(PRE), $(SOURCE)}

NAME = pipex
LIB = $(FUNCTION)/libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror -g

OBJ = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	cc $(FLAGS) -o $@ $^
$(LIB):
	$(MAKE) -C $(FUNCTION)

.c.o:
	$(CC) $(FLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

clean: 
	rm -f $(OBJ)
	$(MAKE) clean -C $(FUNCTION)
        
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(FUNCTION)

re: fclean all
