BINARY = bin
SOURCE_DIR = ./srcs/
HEADER_DIR = ./includes/
CFILES = ft_putchar.c \
	 ft_swap.c \
	 ft_putstr.c \
	 ft_strlen.c \
	 ft_strcmp.c
HFILES = ft.h

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(foreach D,$(SOURCE_DIR), -I$(D))

OBJECTS = $(patsubst %.c,%.o,$(CFILES))

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c $@ $^
    
clean: 
	rm -rf $(OBJECTS)
        
fclean: 
	rm -rf $(OBJECTS) $(NAME)

re:
	fclean
	all	
