BINARY = bin
PRE = ./
HEADER = ./
FUNCTION = /home/tiago/git_42/Common_Core/Libft/ft_functions

SOURCE = $(foreach D, $(PRE),$(wildcard $(D)/*.c))

SOURCES = ${addprefix $(PRE), $(SOURCE)}

FUNCTIONS = $(foreach D, $(FUNCTION),$(wildcard $(D)/*.a))

CC = cc
FLAGS = -Wall -Wextra -Werror

OBJ = $(SOURCES:.c=.o)

all: $(BINARY)
	norminette $(FUNCTION)

$(BINARY): $(OBJ) $(FUNCTIONS)
	$(CC) -o $@ $^

.c.o:
	$(CC) $(FLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

$(FUNCTIONS):
	cd $(FUNCTION) make

run: 
	./$(BINARY)

clean: 
	rm -f $(OBJ)
        
fclean: clean
	rm -f $(BINARY)

re: fclean all