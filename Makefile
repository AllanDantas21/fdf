NAME = fdf
LIBFT = libft.a
MINILIBX = libmlx.a
SRCC_FILES =	fdf.c checks.c gets.c utils.c bresenham.c
SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
OBJ = ${SRC:.c=.o}
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

all:	$(NAME) 

$(NAME) : $(OBJ)
		@make -C libft
		@make -C minilibx
		$(CC) $(CFLAGS)  $(OBJ) $(INCLUDE) libft/$(LIBFT) minilibx/$(MINILIBX) -o $(NAME)  -lX11 -lXext

clean : 
		@make clean -C libft
		${RM} ${OBJ}


fclean : clean
		@make fclean -C libft
		@make clean -C minilibx
		${RM} $(NAME)
		${RM} $(LIBFT)

re: fclean all

.PHONY:		all clean fclean re
