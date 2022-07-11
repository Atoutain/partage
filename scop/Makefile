NAME = scop

CC = clang

SRC = srcs/parseur.c lib/gnl/get_next_line.c\

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

X11FLAGS = -lm lib/libft/libft.a \

INCLUDES = -I lib/libft/includes/libft.h lib/gnl/get_next_line.h includes/scop.h

OBJS = parseur.o get_next_line.o\

all: $(NAME)

$(NAME) :
			@make -C lib/libft/ all
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
