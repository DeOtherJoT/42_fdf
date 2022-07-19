GCC		= gcc -Wall -Wextra -Werror -Iincludes -Ilibft -lmlx -framework OpenGL -framework AppKit
CINCAI	= get_next_line/*.c sources/*/*.c libft/*.c
RM		= rm -rf

cincai :
	$(GCC) $(CINCAI) -o fdf

clean :
	$(RM) fdf

PHONY : cincai clean