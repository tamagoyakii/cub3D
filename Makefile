CC = cc
CFLAGS = -Wall -Wextra -Werror 
AR = ar rcs
RM = rm -rf
NAME = cub3D 
MLX_DIR = ./mlx

SRCS = main.c move.c draw.c parse.c
SRCS := $(addprefix srcs/, $(SRCS))
GNL_SRCS	= gnl/get_next_line.c gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o) $(GNL_SRCS:.c=.o)

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
