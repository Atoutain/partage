NAME=fdf

CC=clang

SRC = srcs/fdf.c srcs/hooks.c srcs/tableur.c srcs/get_next_line.c \
	  srcs/move_tmp.c srcs/ft_put_pixel_to_image.c srcs/init_window.c

FLAGS=-Wall -Wextra -Werror

RM=rm -f

X11FLAGS = -L.. -lmlx -O3 -lm lib/gnl/libft/libft.a \
		   -L lib/minilibx \
		   -framework OpenGL -framework AppKit

INCLUDES=-I lib/gnl/libft/includes/libft.h includes/fdf.h

OBJS = fdf.o hooks.o tableur.o get_next_line.o move_tmp.o \
	   ft_put_pixel_to_image.o init_window.o

OBJF = srcs/fdf.o srcs/hooks.o srcs/tableur.o srcs/get_next_line.o \
	   srcs/move_tmp.o srcs/ft_put_pixel_to_image.o srcs/init_window.o
all: $(NAME)

$(NAME):
			@make -C lib/gnl/libft/ all
			$(CC) $(FLAGS) -c $(SRC) -I $(INCLUDES)
			$(CC) -o $(NAME) $(OBJS) $(X11FLAGS)
			@mv -f $(OBJS) srcs/.
									@echo "Build succesful."

clean:
			@$(RM) $(OBJF)
					@echo "Objects deleted."

fclean: clean
			@$(RM) $(NAME)
					@echo "Binary deleted."

re: fclean all
			@echo "Project rebuild."

.PHONY: clean fclean all
