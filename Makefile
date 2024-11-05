NAME = fdf
LIBFT = libft.a
MINILIBX = libmlx.a
SRCC_FILES =	fdf.c checks.c map.c utils.c bresenham.c display.c controls.c rotate.c keys.c
SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
OBJ = ${SRC:.c=.o}
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

all:	$(NAME) 

$(NAME) : $(OBJ)
		@make -C libs/libft
		@make -C libs/minilibx
		$(CC) $(CFLAGS)  $(OBJ) $(INCLUDE) libs/libft/$(LIBFT) libs/minilibx/$(MINILIBX) -o $(NAME)  -lX11 -lXext -lm

clean : 
		@make clean -C libs/libft
		${RM} ${OBJ}


fclean : clean
		@make fclean -C libs/libft
		@make clean -C libs/minilibx
		${RM} $(NAME)
		${RM} $(LIBFT)

re: fclean all

.PHONY:		all clean fclean re
