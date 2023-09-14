SOURCE_DIR = ~/srcs

HEADER_DIR = ~/includes

CFILES = ft_putchar.c \
	 ft_swap.c \
	 ft_putstr.c \
	 ft_strlen.c \
	 ft_strcmp.c

OFILES = $(CFILES:.c=.o)
            
HFILES = ft.h

NAME = libft.a

CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME) clean

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

    
clean: 
	rm -rf $(OFILES)
	echo rm -rf $(OFILES)
        
fclean: 
	clean rm -rf $(NAME)
	echo clean rm -rf $(NAME)

re: fclean $(NAME)
    echo fclean $(NAME)
