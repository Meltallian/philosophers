# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -pthread
NAME = philosophers
philosophers_SRC = main.c utils.c parse.c name.c init.c actions.c \
					to_eat_even.c to_eat_odd.c 
philosophers_OBJ = $(philosophers_SRC:.c=.o)

# Default rule
all: $(NAME)

# This won't be called if the files don't exist or are not updated
$(philosophers_OBJ): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES_DIR) -c $< -o $@

$(NAME):  $(philosophers_OBJ)
	$(CC) $(CFLAGS) $(philosophers_OBJ) -o $(NAME)

clean:
	rm -f $(philosophers_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

leaks: $(NAME)
	leaks --atExit -- ./$(NAME)

.PHONY: all clean fclean re run