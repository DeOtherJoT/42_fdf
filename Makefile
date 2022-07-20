GCC		= gcc -Wall -Wextra -Werror -Iincludes -Ilibft -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g
CINCAI	= get_next_line/*.c sources/*/*.c libft/*.c
RM		= rm -rf

SRCS_GNL	= get_next_line.c get_next_line_utils.c
SRCS_BNS	= bonus_helper.c bonus_init.c bonus.c
SRCS_BLA	= algo.c bresenham_utils.c init_coord.c
SRCS_PARS	= init_map.c parse_map.c parse_utils.c
SRCS_MAT	= affine_rotation.c affine_transformation.c init_matrix.c \
				matrix_utils.c mult_matrix.c
SRCS_DRI	= init_data.c main_helper.c main_utils.c main.c

cincai :
	$(GCC) $(CINCAI) -o fdf

clean :
	$(RM) fdf

PHONY : cincai clean
