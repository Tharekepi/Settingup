##
## EPITECH PROJECT, 2023
## B-CPE-101-LYN-1-1-myprintf-tharek.akaichi
## File description:
## Makefile
##

NAME = libmy.a

PROJECT_NAME = setting_up

CC = gcc

SRC = src/get_file.c\
	  src/main.c\
	  src/my_algo.c\

LIB = $(wildcard lib/my/*.c)

OBJ = $(SRC:.c=.o)

LIBOBJ = $(LIB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBOBJ)
	ar rc $(NAME) $(OBJ) $(LIBOBJ)
	gcc -o $(PROJECT_NAME) $(LIB) $(SRC) -L. -lmy -I./include

clean:
	rm -f $(OBJ) $(LIBOBJ)

fclean: clean
	rm -f $(NAME) $(PROJECT_NAME)

re: fclean all

.PHONY: all clean fclean re
