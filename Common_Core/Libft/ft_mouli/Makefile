BINARY = bin
PRE = ./
HEADER = ./
FUNCTION = /workspaces/42/Common_Core/Libft/ft_functions

SOURCE = $(foreach D, $(PRE),$(wildcard $(D)/*.c))

SOURCES = ${addprefix $(PRE), $(SOURCE)}

FUNCTIONS = $(foreach D, $(FUNCTION),$(wildcard $(D)/*.c))

CC = cc
FLAGS = -Wall -Wextra -Werror

OBJ = $(SOURCES:.c=.o)
FUNCTIONS_OBJ = $(FUNCTIONS:.c=.o)

all: $(BINARY)
#	norminette $(FUNCTION)

$(BINARY): $(OBJ) $(FUNCTIONS_OBJ)
	$(CC) -o $@ $^

.c.o:
	$(MAKE) -C $(FUNCTION)
	$(MAKE) bonus -C $(FUNCTION)
	$(CC) $(FLAGS) -I $(HEADER) -I $(FUNCTION) -c $< -o $(<:.c=.o)

run: 
	./$(BINARY)

clean: 
	rm -f $(OBJ)
	$(MAKE) clean -C $(FUNCTION)
        
fclean: clean
	rm -f $(BINARY)
	$(MAKE) fclean -C $(FUNCTION)

re: fclean all