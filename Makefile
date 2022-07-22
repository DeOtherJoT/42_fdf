#EXEC NAME#

NAME	= fdf

#FLAGS#

GCC		= gcc -Wall -Werror -Wextra -fsanitize=address -g
MLX		= -lmlx -framework OpenGL -framework AppKit
RM		= rm -rf

#PATH AND LIB#

LIBFT	= libft
INC		= -Iinclude -I$(LIBFT)
LIB		= -L$(LIBFT) libft/libft.a
SRC_DIR = sources/
GNL_DIR = get_next_line/
BNS_DIR	= sources/Bonus/
BLA_DIR = sources/Bresenham/
DRV_DIR = sources/Driver/
MAT_DIR = sources/Matrix/
PAR_DIR = sources/Parsing/
MAIN	= sources/Driver/main.c

#SOURCE FILE#

S_SRCS	= $(addprefix $(BNS_DIR), bonus_helper.c bonus_init.c bonus.c) \
		  $(addprefix $(BLA_DIR), algo.c bresenham_utils.c init_coord.c) \
		  $(addprefix $(DRV_DIR), init_data.c main_helper.c main_utils.c) \
		  $(addprefix $(MAT_DIR), affine_rotation.c affine_transformation.c init_matrix.c matrix_utils.c mult_matrix.c) \
		  $(addprefix $(PAR_DIR), init_map.c parse_map.c parse_utils.c) \
		  $(addprefix $(GNL_DIR), get_next_line.c get_next_line_utils.c)
OBJS	= $(S_SRCS:.c=.o)

#COMMANDS#

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) re -C $(LIBFT)
	ar rcs fdf.a $(OBJS)
	$(GCC) $(MLX) $(INC) -o $(NAME) $(MAIN) fdf.a $(LIB)

%.o : %.c
	 $(GCC) $(INC) -c $< -o $@

clean :
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re
