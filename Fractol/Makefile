NAME = Fractal

SRC_C = srcs/checks_1.c srcs/choice_1.c srcs/color.c srcs/data_init.c \
		srcs/draw_mandelbrot.c srcs/fractol.c srcs/expose_1.c \
		srcs/draw_julia.c srcs/mlx.c srcs/hooks_key_1.c \
		srcs/hooks_mouse_1.c

INCLUDES = minilibx/mlx.h includes/fractol.h libft/includes/libft.h

LIBFT_DIR = libft/

FLAGS =

OBJS = checks_1.o choice_1.o color.o data_init.o \
		draw_mandelbrot.o fractol.o expose_1.o \
		draw_julia.o mlx.o hooks_key_1.o hooks_mouse_1.o

X11FLAGS = -L$(LIBFT_DIR) -lft ../wolf_v2/mlx_linux/libmlx_Linux.a -lXext -lX11 -lm -lz

OBJSF = $(SRC_C:.c=.o)

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) -c $(SRC_C) -I $(INCLUDES)
		@gcc -o $(NAME) $(OBJS) $(X11FLAGS)
		@mv -f $(OBJS) srcs/.

clean:
	@/bin/rm -f $(OBJSF)

fclean: clean
	@/bin/rm -f $(OBJSf)
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
