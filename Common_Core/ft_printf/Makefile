PRE = ./mandatory/
HEADER = ./
BONUS_DIR = ./bonus/
FUNCTION = ./libft

SOURCE = ft_printf.c utils.c write_c.c write_d_i.c\
		write_p.c write_s.c write_spe.c write_u.c write_x_lower.c\
		write_x_upper.c

BONUS = ft_printf.c utils.c write_c.c write_d_i.c\
		write_p.c write_s.c write_spe.c write_u.c write_x_lower.c\
		write_x_upper.c write_bonus.c utils_bonus.c write_d_i_u_bonus.c\
		write_x_bonus.c write_X_bonus.c write_u_bonus.c

SOURCES = ${addprefix $(PRE), $(SOURCE)}
BONUS_SOURCES = ${addprefix $(BONUS_DIR), $(BONUS)}

NAME = libftprintf.a
LIB = $(FUNCTION)/libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror -g

OBJ = $(SOURCES:.c=.o)
OBJ_BONUS = $(BONUS_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJ_BONUS)
	cp $(LIB) $@
	ar rcs $@ $(OBJ_BONUS)

$(LIB):
	$(MAKE) -C $(FUNCTION)

.c.o:
	$(CC) $(FLAGS) -I $(HEADER) -I $(FUNCTION) -c $< -o $(<:.c=.o)

bonus: $(LIB) $(OBJ_BONUS)
	rm -f $(NAME)
	cp $(LIB) $(NAME)
	ar rcs $(NAME) $(OBJ_BONUS)
	
clean: 
	rm -f $(OBJ) $(OBJ_BONUS)
	$(MAKE) clean -C $(FUNCTION)
        
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(FUNCTION)

re: fclean all