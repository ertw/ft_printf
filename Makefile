#!/usr/bin/make -f

NAME = libftprintf.a

TEST_O = test.o

OFILES = \
		ft_islower.o\
		ft_isupper.o\
		ft_tolower.o\
		ft_toupper.o\
		ft_isdigit.o\
		ft_isalpha.o\
		ft_isalnum.o\
		ft_isspace.o\
		ft_isascii.o\
		ft_isprint.o\
		ft_striter.o\
		ft_striteri.o\
		ft_memset.o\
		ft_bzero.o\
		ft_memcpy.o\
		ft_memmove.o\
		ft_putchar.o\
		ft_putstr.o\
		ft_putstr_fd.o\
		ft_putstr2.o\
		ft_putstrc.o\
		ft_memchr.o\
		ft_memcmp.o\
		ft_strlen.o\
		ft_strdup.o\
		ft_strncpy.o\
		ft_strclr.o\
		ft_atoi.o\
		ft_strcat.o\
		ft_strncat.o\
		ft_strmap.o\
		ft_strmapi.o\
		ft_memccpy.o\
		ft_strcmp.o\
		ft_strncmp.o\
		ft_strchr.o\
		ft_strrchr.o\
		ft_strstr.o\
		ft_strnstr.o\
		ft_strcpy.o\
		ft_stpcpy.o\
		ft_putnbr.o\
		ft_putnbr_fd.o\
		ft_putnbrhex.o\
		ft_itoa.o\
		ft_itoa_base.o\
		ft_strequ.o\
		ft_strnequ.o\
		ft_putendl.o\
		ft_putchar_fd.o\
		ft_putendl_fd.o\
		ft_strdel.o\
		ft_abs.o\
		ft_memalloc.o\
		ft_memdel.o\
		ft_strnew.o\
		ft_strsub.o\
		ft_strjoin.o\
		ft_strnjoin.o\
		ft_strwjoin.o\
		ft_strtrim.o\
		ft_wordcount.o\
		ft_strsplit.o\
		ft_lstnew.o\
		ft_lstdelone.o\
		ft_lstdel.o\
		ft_lstadd.o\
		ft_lstiter.o\
		ft_countplaces.o\
		ft_strrev.o\
		ft_strlcat.o\
		ft_lstmap.o\
		ft_chrcmp.o\
		ft_strevery.o\
		ft_streveryi.o\
		ft_strndup.o\
		ft_printf.o
TEST_SRC = \
		tests.c

CFLAGS = -Wall -Werror -Wextra -g #-O3 #-fsanitize=address

all: $(NAME)

tests: $(NAME)
	gcc ${CFLAGS} -o ${TEST_O} -L. ${NAME} ${TEST_SRC}

$(NAME):
	gcc ${CFLAGS} -c ft_islower.c
	gcc ${CFLAGS} -c ft_isupper.c
	gcc ${CFLAGS} -c ft_tolower.c
	gcc ${CFLAGS} -c ft_toupper.c
	gcc ${CFLAGS} -c ft_isdigit.c
	gcc ${CFLAGS} -c ft_isalpha.c
	gcc ${CFLAGS} -c ft_isalnum.c
	gcc ${CFLAGS} -c ft_isspace.c
	gcc ${CFLAGS} -c ft_isascii.c
	gcc ${CFLAGS} -c ft_isprint.c
	gcc ${CFLAGS} -c ft_striter.c
	gcc ${CFLAGS} -c ft_striteri.c
	gcc ${CFLAGS} -c ft_memset.c
	gcc ${CFLAGS} -c ft_bzero.c
	gcc ${CFLAGS} -c ft_memcpy.c
	gcc ${CFLAGS} -c ft_memmove.c
	gcc ${CFLAGS} -c ft_putchar.c
	gcc ${CFLAGS} -c ft_putstr.c
	gcc ${CFLAGS} -c ft_putstr_fd.c
	gcc ${CFLAGS} -c ft_putstr2.c
	gcc ${CFLAGS} -c ft_putstrc.c
	gcc ${CFLAGS} -c ft_memchr.c
	gcc ${CFLAGS} -c ft_memcmp.c
	gcc ${CFLAGS} -c ft_strlen.c
	gcc ${CFLAGS} -c ft_strdup.c
	gcc ${CFLAGS} -c ft_strncpy.c
	gcc ${CFLAGS} -c ft_strclr.c
	gcc ${CFLAGS} -c ft_atoi.c
	gcc ${CFLAGS} -c ft_strcat.c
	gcc ${CFLAGS} -c ft_strncat.c
	gcc ${CFLAGS} -c ft_strmap.c
	gcc ${CFLAGS} -c ft_strmapi.c
	gcc ${CFLAGS} -c ft_memccpy.c
	gcc ${CFLAGS} -c ft_strcmp.c
	gcc ${CFLAGS} -c ft_strncmp.c
	gcc ${CFLAGS} -c ft_strchr.c
	gcc ${CFLAGS} -c ft_strrchr.c
	gcc ${CFLAGS} -c ft_strstr.c
	gcc ${CFLAGS} -c ft_strnstr.c
	gcc ${CFLAGS} -c ft_strcpy.c
	gcc ${CFLAGS} -c ft_stpcpy.c
	gcc ${CFLAGS} -c ft_putnbr.c
	gcc ${CFLAGS} -c ft_putnbr_fd.c
	gcc ${CFLAGS} -c ft_putnbrhex.c
	gcc ${CFLAGS} -c ft_itoa.c
	gcc ${CFLAGS} -c ft_itoa_base.c
	gcc ${CFLAGS} -c ft_strequ.c
	gcc ${CFLAGS} -c ft_strnequ.c
	gcc ${CFLAGS} -c ft_putendl.c
	gcc ${CFLAGS} -c ft_putchar_fd.c
	gcc ${CFLAGS} -c ft_putendl_fd.c
	gcc ${CFLAGS} -c ft_strdel.c
	gcc ${CFLAGS} -c ft_abs.c
	gcc ${CFLAGS} -c ft_memalloc.c
	gcc ${CFLAGS} -c ft_memdel.c
	gcc ${CFLAGS} -c ft_strnew.c
	gcc ${CFLAGS} -c ft_strsub.c
	gcc ${CFLAGS} -c ft_strjoin.c
	gcc ${CFLAGS} -c ft_strnjoin.c
	gcc ${CFLAGS} -c ft_strwjoin.c
	gcc ${CFLAGS} -c ft_strtrim.c
	gcc ${CFLAGS} -c ft_wordcount.c
	gcc ${CFLAGS} -c ft_strsplit.c
	gcc ${CFLAGS} -c ft_lstnew.c
	gcc ${CFLAGS} -c ft_lstdelone.c
	gcc ${CFLAGS} -c ft_lstdel.c
	gcc ${CFLAGS} -c ft_lstadd.c
	gcc ${CFLAGS} -c ft_lstiter.c
	gcc ${CFLAGS} -c ft_countplaces.c
	gcc ${CFLAGS} -c ft_strrev.c
	gcc ${CFLAGS} -c ft_strlcat.c
	gcc ${CFLAGS} -c ft_lstmap.c
	gcc ${CFLAGS} -c ft_chrcmp.c
	gcc ${CFLAGS} -c ft_strevery.c
	gcc ${CFLAGS} -c ft_streveryi.c
	gcc ${CFLAGS} -c ft_strndup.c
	gcc ${CFLAGS} -c ft_printf.c
	ar rc ${NAME} ${OFILES}
clean:
	rm -f ${OFILES}
fclean: clean
	rm -f ${NAME} ${TEST_O}
re: fclean all
