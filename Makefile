#!/usr/bin/make -f

NAME = libftprintf.a

OBJECTS = \
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

CFLAGS = -Wall -Werror -Wextra -nostartfiles -g #-fsanitize=address
all: $(NAME)
$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS)
	# -o $@
	ar -rcs $(NAME) $(OBJECTS)
%.o: %.c
	$(CC) -c $< -o $@
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME) $(OBJECTS)
re: fclean all
