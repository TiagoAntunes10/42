PRE = ./
HEADER = ./
FUNCTION = ./libft

SOURCE = ft_printf.c utils.c write_c.c write_d.c write_i.c\
		write_p.c write_s.c write_spe.c write_u.c write_x_lower.c\
		write_x_upper.c

SOURCES = ${addprefix $(PRE), $(SOURCE)}

NAME = libftprintf.a
LIB = $(FUNCTION)/libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror

OBJ = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	ar rcs $@ $(OBJ)

$(LIB):
	$(MAKE) -C $(FUNCTION)

.c.o:
	$(CC) $(FLAGS) -I $(HEADER) -I $(FUNCTION) -c $< -o $(<:.c=.o)

clean: 
	rm -f $(OBJ)
	$(MAKE) clean -C $(FUNCTION)
        
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(FUNCTION)

re: fclean all