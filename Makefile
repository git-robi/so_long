NAME		= so_long
LIBS		= include/so_long.h
MINILIBX	= minilibx-linux/libmlx.a
CC		= gcc
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=leak
CFLAGSMLX	= -Lminilibx-linux -lmlx_Linux -lX11 -lXext
SRC = src/so_long.c src/error_check.c src/libft_utils.c src/libft_utils_two.c src/handle_input.c src/initialize_map.c src/path_check.c src/exit_game.c src/init_game.c src/free_memory.c src/make_screen.c src/gnl/get_next_line.c src/gnl/get_next_line_utils.c
OBJS = $(SRC:.c=.o)
HEADER = includes/so_long.h

all: $(NAME)

$(NAME): $(OBJS) $(MINILIBX) Makefile
	$(CC) $(CFLAGS) $(OBJS) $(CFLAGSMLX) -o $(NAME)

$(MINILIBX): 
	make -C minilibx-linux

%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
