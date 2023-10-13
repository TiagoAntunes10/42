BINARY = bin
PRE = ./
HEADER = ./
FUNCTION = /nfs/homes/tialbert/Desktop/git_42/Common_Core/Libft/ft_functions

SOURCE = $(foreach D, $(PRE),$(wildcard $(D)/*.c))

SOURCES = ${addprefix $(PRE), $(SOURCE)}

FUNCTIONS = $(foreach D, $(FUNCTION),$(wildcard $(D)/*.c))

LIB = $(FUNCTION)/libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror -g

OBJ = $(SOURCES:.c=.o)
FUNCTIONS_OBJ = $(FUNCTIONS:.c=.o)

all: $(BINARY)
	norminette $(FUNCTION)

$(BINARY): $(OBJ) $(FUNCTIONS_OBJ)
	$(CC) -o $@ $(OBJ) $(LIB)

.c.o:
	$(MAKE) -C $(FUNCTION)
	$(MAKE) bonus -C $(FUNCTION)
	$(CC) $(FLAGS) -I $(HEADER) -I $(FUNCTION) -c $< -o $(<:.c=.o)

run: 
	./$(BINARY)
	valgrind ./$(BINARY)

clean: 
	rm -f $(OBJ)
	$(MAKE) clean -C $(FUNCTION)
        
fclean: clean
	rm -f $(BINARY)
	$(MAKE) fclean -C $(FUNCTION)

re: fclean all