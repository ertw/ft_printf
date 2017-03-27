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
		ft_mempmove.o\
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
		ft_strwfjoin.o\
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
		ft_printf.o\
		ft_wctomb.o\
		wstrbytelen.o\
		wstrtombstr.o

CFLAGS = -Wall -Werror -Wextra -g #-O3 #-fsanitize=address

all: $(NAME)

tests: $(NAME)
	clang ${CFLAGS} -o ${TEST_O} -L. ${NAME}

$(NAME):
	clang ${CFLAGS} -c ft_islower.c
	clang ${CFLAGS} -c ft_isupper.c
	clang ${CFLAGS} -c ft_tolower.c
	clang ${CFLAGS} -c ft_toupper.c
	clang ${CFLAGS} -c ft_isdigit.c
	clang ${CFLAGS} -c ft_isalpha.c
	clang ${CFLAGS} -c ft_isalnum.c
	clang ${CFLAGS} -c ft_isspace.c
	clang ${CFLAGS} -c ft_isascii.c
	clang ${CFLAGS} -c ft_isprint.c
	clang ${CFLAGS} -c ft_striter.c
	clang ${CFLAGS} -c ft_striteri.c
	clang ${CFLAGS} -c ft_memset.c
	clang ${CFLAGS} -c ft_bzero.c
	clang ${CFLAGS} -c ft_memcpy.c
	clang ${CFLAGS} -c ft_memmove.c
	clang ${CFLAGS} -c ft_mempmove.c
	clang ${CFLAGS} -c ft_putchar.c
	clang ${CFLAGS} -c ft_putstr.c
	clang ${CFLAGS} -c ft_putstr_fd.c
	clang ${CFLAGS} -c ft_putstr2.c
	clang ${CFLAGS} -c ft_putstrc.c
	clang ${CFLAGS} -c ft_memchr.c
	clang ${CFLAGS} -c ft_memcmp.c
	clang ${CFLAGS} -c ft_strlen.c
	clang ${CFLAGS} -c ft_strdup.c
	clang ${CFLAGS} -c ft_strncpy.c
	clang ${CFLAGS} -c ft_strclr.c
	clang ${CFLAGS} -c ft_atoi.c
	clang ${CFLAGS} -c ft_strcat.c
	clang ${CFLAGS} -c ft_strncat.c
	clang ${CFLAGS} -c ft_strmap.c
	clang ${CFLAGS} -c ft_strmapi.c
	clang ${CFLAGS} -c ft_memccpy.c
	clang ${CFLAGS} -c ft_strcmp.c
	clang ${CFLAGS} -c ft_strncmp.c
	clang ${CFLAGS} -c ft_strchr.c
	clang ${CFLAGS} -c ft_strrchr.c
	clang ${CFLAGS} -c ft_strstr.c
	clang ${CFLAGS} -c ft_strnstr.c
	clang ${CFLAGS} -c ft_strcpy.c
	clang ${CFLAGS} -c ft_stpcpy.c
	clang ${CFLAGS} -c ft_putnbr.c
	clang ${CFLAGS} -c ft_putnbr_fd.c
	clang ${CFLAGS} -c ft_putnbrhex.c
	clang ${CFLAGS} -c ft_itoa.c
	clang ${CFLAGS} -c ft_itoa_base.c
	clang ${CFLAGS} -c ft_strequ.c
	clang ${CFLAGS} -c ft_strnequ.c
	clang ${CFLAGS} -c ft_putendl.c
	clang ${CFLAGS} -c ft_putchar_fd.c
	clang ${CFLAGS} -c ft_putendl_fd.c
	clang ${CFLAGS} -c ft_strdel.c
	clang ${CFLAGS} -c ft_abs.c
	clang ${CFLAGS} -c ft_memalloc.c
	clang ${CFLAGS} -c ft_memdel.c
	clang ${CFLAGS} -c ft_strnew.c
	clang ${CFLAGS} -c ft_strsub.c
	clang ${CFLAGS} -c ft_strjoin.c
	clang ${CFLAGS} -c ft_strnjoin.c
	clang ${CFLAGS} -c ft_strwjoin.c
	clang ${CFLAGS} -c ft_strwfjoin.c
	clang ${CFLAGS} -c ft_strtrim.c
	clang ${CFLAGS} -c ft_wordcount.c
	clang ${CFLAGS} -c ft_strsplit.c
	clang ${CFLAGS} -c ft_lstnew.c
	clang ${CFLAGS} -c ft_lstdelone.c
	clang ${CFLAGS} -c ft_lstdel.c
	clang ${CFLAGS} -c ft_lstadd.c
	clang ${CFLAGS} -c ft_lstiter.c
	clang ${CFLAGS} -c ft_countplaces.c
	clang ${CFLAGS} -c ft_strrev.c
	clang ${CFLAGS} -c ft_strlcat.c
	clang ${CFLAGS} -c ft_lstmap.c
	clang ${CFLAGS} -c ft_chrcmp.c
	clang ${CFLAGS} -c ft_strevery.c
	clang ${CFLAGS} -c ft_streveryi.c
	clang ${CFLAGS} -c ft_strndup.c
	clang ${CFLAGS} -c ft_printf.c
	clang ${CFLAGS} -c ft_wctomb.c
	clang ${CFLAGS} -c wstrbytelen.c
	clang ${CFLAGS} -c wstrtombstr.c
	ar rc ${NAME} ${OFILES}
clean:
	rm -f ${OFILES}
fclean: clean
	rm -f ${NAME} ${TEST_O}
re: fclean all
