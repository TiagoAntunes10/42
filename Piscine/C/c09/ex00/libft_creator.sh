#!/bin/bash

cc -c -Wall -Wextra -Werror *.c
ar -rcs libft.a *.o
