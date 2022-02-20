NAME=pipex

SRC_PIPEX = main.c \
			pipex.c \
			kindergarten.c \
			get_next.c \

SRCS_OTHERS	=	split.c \
				strchr.c \
				strdup.c \
				strjoin.c \
				strlen.c \
				strncmp.c \
				strnstr.c \
				substr.c \

all:$(NAME)

$(NAME):
	gcc -I ./headers -I ./libft -Wall -Werror -Wextra -o $(NAME) \
	$(addprefix ./utils/,$(SRCS_OTHERS)) \
	$(addprefix ./src/,$(SRC_PIPEX)) -g3

clean:
	rm -rf $(NAME)

fclean:clean

re:fclean all

teste: re
    ./pipex "./files/teste" "echo $FT_NBR2 + $FT_NBR1" "tr 'mrdoc' 01234" "tr ''\\\\\"?\!' 01234" "xargs echo 'obase=13;ibase=5;'" "bc" "tr '0123456789ABC' 'gtaio luSnemf' " "./files/res"

.PHONY:all clean fclean re 



