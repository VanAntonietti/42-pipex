NAME=pipex

SRC_PIPEX = main.c \
			pipex.c \
			kindergarten.c \
			get_next.c \

SRC_LIBFT				=       ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRCS_OTHERS	=		ft_printf.c \
					ft_printf_c.c \
					ft_printf_d.c \
					ft_printf_i.c \
					ft_printf_p.c \
					ft_printf_percentage.c \
					ft_printf_s.c \
					ft_printf_u.c \
					ft_printf_x.c \
					ft_printf_xu.c \
					get_next_line.c \

all:$(NAME)

$(NAME):
	gcc -I ./headers -I ./libft -Wall -Werror -Wextra -o $(NAME) \
	$(addprefix ./libft/,$(SRC_LIBFT)) \
	$(addprefix ./libft/others/,$(SRCS_OTHERS)) \
	$(addprefix ./src/,$(SRC_PIPEX)) -g3

clean:
	rm -rf $(NAME)

fclean:clean

re:fclean all

teste: re
    ./pipex "./files/teste" "echo $FT_NBR2 + $FT_NBR1" "tr 'mrdoc' 01234" "tr ''\\\\\"?\!' 01234" "xargs echo 'obase=13;ibase=5;'" "bc" "tr '0123456789ABC' 'gtaio luSnemf' " "./files/res"

.PHONY:all clean fclean re 



