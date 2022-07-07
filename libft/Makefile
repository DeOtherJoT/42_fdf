SRCS		= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_islpha.c \
			  ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
			  ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
			  ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			  ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
			  ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
			  ft_strrchr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
			  ft_toupper.c
BONUS_SRCS	= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
			  ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
GCC			= gcc
GCC_FLAGS	= -Wall -Werror -Wextra
ARRCS		= ar rcs
RANLIB		= ranlib
NAME		= libft.a
RM			= rm -f

all : $(NAME)

.c.o :
	$(GCC) $(GCC_FLAGS) -I . -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	$(ARRCS) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(RM) $(NAME)

bonus : $(NAME) $(BONUS_OBJS)
	$(ARRCS) $(NAME) $(BONUS_OBJS)
	$(RANLIB) $(NAME)

re : fclean all

rebonus : fclean bonus

.PHONY : all .c.o clean fclean bonus re rebonus
