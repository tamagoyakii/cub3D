CC = cc
CFLAGS = -Wall -Wextra -Werror 
AR = ar rcs
RM = rm -rf
NAME = cub3d 
MLX_DIR = ./mlx

SRCS = main.c
SRCS := $(addprefix srcs/, $(SRCS))

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) -I ./ $(OBJS) -L ./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "☺️  make cub3d"
clean :
	@make -C $(MLX_DIR) clean
	@$(RM) $(OBJS)
	@echo "🧹 clean~~"

fclean : clean
	@$(RM) $(NAME)
	@echo "🔥 fclean~~~"

re : fclean all

.PHONY : all clean fclean re
