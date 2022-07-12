NAME = wolf_v2

CC = clang

SRC = srcs/main.c gnl/libft/get_next_line.c srcs/drawing.c srcs/parseur.c\
srcs/window.c srcs/calcul_wolf.c srcs/init_data_wolf.c srcs/wall_wolf.c\
srcs/ft_put_pixel_to_image.c srcs/color.c srcs/wolf_3d.c srcs/expose.c\
srcs/key_hook.c srcs/ft_time.c

FLAGS = 

RM = rm -rf

LIBFT_DIR	= gnl/libft/

X11FLAGS = -L$(LIBFT_DIR) -lft\
			gnl/libft/libft.a \
			mlx_linux/libmlx_Linux.a -lXext -lX11 -lm -lz


INCLUDES = gnl/libft/includes/libft.h includes/wolf.h 

OBJS = main.o get_next_line.o drawing.o parseur.o window.o wall_wolf.o\
calcul_wolf.o init_data_wolf.o ft_put_pixel_to_image.o color.o expose.o\
wolf_3d.o key_hook.o ft_time.o

all: $(NAME)

$(NAME) :
			@make -C gnl/libft/ all
			$(CC) -c $(FLAGS) $(SRC) -I $(INCLUDES)
			$(CC) -o $(NAME) $(OBJS) $(X11FLAGS)
			@mv -f $(OBJS) objs/.
							@echo "Build succesful"

clean :
		@$(RM) $(OBJS)
				@echo "Objects deleted"

fclean : clean
			@$(RM) $(NAME)
					@echo "Binary deleted"

re: fclean all
			@echo "Project rebuild."

.PHONY: clean fclean all
