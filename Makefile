# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = philosophers
LIBFT = libft/libft.a
philosophers_SRC = main.c path.c utils.c
philosophers_OBJ = $(philosophers_SRC:.c=.o)
#INCLUDES_DIR = -I./includes -I./libft/includes -I./minilibx_macos/includes
#pas necessaire parceque -lft -lmlx dans la ligne cc
# Default rule
all: $(NAME)

# This won't be called if the files don't exist or are not updated
$(philosophers_OBJ): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES_DIR) -c $< -o $@

$(LIBFT):
	make -C ./libft

$(NAME): $(LIBFT) $(philosophers_OBJ)
	$(CC) $(CFLAGS) $(philosophers_OBJ) $(LIBFT) -o $(NAME) -L./libft -lft

clean:
	make clean -C ./libft
	rm -f $(philosophers_OBJ)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

leaks: $(NAME)
	leaks --atExit -- ./$(NAME)

.PHONY: all clean fclean re run