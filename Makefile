NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_PATH = ./minilibx-linux
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lX11 -lXext -lm
SRCS = main.c input.c math.c rander.c event.c string.c fractal.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
