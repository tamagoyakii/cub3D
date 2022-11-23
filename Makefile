CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
AR = ar rcs
RM = rm -rf
NAME = cub3D 
MLX_DIR = ./mlx
libft = ./libft/libft.a

SRCS = main.c init.c free.c operate.c draw.c draw_util.c raycasting.c\
parse.c parse_cub.c parse_map.c parse_color.c parse_utils.c
SRCS := $(addprefix srcs/, $(SRCS))
GNL_SRCS	= gnl/get_next_line.c gnl/get_next_line_utils.c


OBJS = $(SRCS:.c=.o) $(GNL_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(MLX_DIR)
	@make -C ./libft
	@$(CC) $(CFLAGS) -I ./ $(OBJS) $(libft) -L ./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "☺️  make cub3d"
clean :
	@make -C $(MLX_DIR) clean
	@make -C ./libft clean
	@$(RM) $(OBJS)
	@echo "🧹 clean~~"

fclean : clean
	@make -C ./libft fclean
	@$(RM) $(NAME)
	@echo "🔥 fclean~~~"

re : 
	@make fclean
	@make all

.PHONY : all clean fclean re
