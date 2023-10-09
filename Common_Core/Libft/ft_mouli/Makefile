BINARY = bin
PRE = ./
HEADER = ./
FUNCTION = /workspaces/42/Common_Core/Libft/ft_functions

SOURCE = $(foreach D, $(PRE),$(wildcard $(D)/*.c))

SOURCES = ${addprefix $(PRE), $(SOURCE)}

FUNCTIONS = $(foreach D, $(FUNCTION),$(wildcard $(D)/*.h))

CC = cc
FLAGS = -Wall -Wextra -Werror

OBJ = $(SOURCES:.c=.o)
FUNCTIONS_OBJ = $(FUNCTIONS:.h=.a)

all: $(BINARY)
#	norminette $(FUNCTION)

$(BINARY): $(OBJ) $(FUNCTIONS_OBJ)
	$(CC) -o $@ $^

.c.o:
	$(CC) $(FLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

.h.a:
	$(MAKE) -C $(FUNCTION)
	$(MAKE) bonus -C $(FUNCTION)

run: 
	./$(BINARY)

clean: 
	rm -f $(OBJ)
	$(MAKE) clean -C $(FUNCTION)
        
fclean: clean
	rm -f $(BINARY)
	$(MAKE) fclean -C $(FUNCTION)

re: fclean all