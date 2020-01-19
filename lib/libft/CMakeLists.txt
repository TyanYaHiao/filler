cmake_minimum_required(VERSION 3.13)
project(libft)

set(CMAKE_C_STANDARD 99)

set(HEADER includes/libft.h)

set(SOURCES src/ft_abs.c
		src/ft_atoi.c
		src/ft_atoi_hex.c
		src/ft_bzero.c
		src/ft_count_words.c
		src/ft_isalnum.c
		src/ft_isalpha.c
		src/ft_isascii.c
		src/ft_isdigit.c
		src/ft_isprint.c
		src/ft_itoa.c
		src/ft_itoalen.c
		src/ft_lstadd.c
		src/ft_lstdel.c
		src/ft_lstdelone.c
		src/ft_lstiter.c
		src/ft_lstmap.c
		src/ft_lstnew.c
		src/ft_memalloc.c
		src/ft_memccpy.c
		src/ft_memchr.c
		src/ft_memcmp.c
		src/ft_memcpy.c
		src/ft_memdel.c
		src/ft_memmove.c
		src/ft_memset.c
		src/ft_putchar.c
		src/ft_putchar_fd.c
		src/ft_putendl.c
		src/ft_dtoa.c
		src/ft_diff_double.c
		src/ft_putendl_fd.c
		src/ft_putnbr.c
		src/ft_putnbr_fd.c
		src/ft_putstr.c
		src/ft_putstr_fd.c
		src/ft_strcat.c
		src/ft_strchr.c
		src/ft_strchrn.c
		src/ft_strclr.c
		src/ft_strcmp.c
		src/ft_strcpy.c
		src/ft_strdel.c
		src/ft_strdup.c
		src/ft_strequ.c
		src/ft_striter.c
		src/ft_striteri.c
		src/ft_strjoin.c
		src/ft_strlcat.c
		src/ft_strlen.c
		src/ft_strmap.c
		src/ft_strmapi.c
		src/ft_strncat.c
		src/ft_strncmp.c
		src/ft_strncpy.c
		src/ft_strnequ.c
		src/ft_strnew.c
		src/ft_strnstr.c
		src/ft_strrchr.c
		src/ft_strsplit.c
		src/ft_strstr.c
		src/ft_strsub.c
		src/ft_strtrim.c
		src/ft_tolower.c
		src/ft_toupper.c
		src/ft_strcut.c
		src/get_next_line.c
		src/ft_sqrt_up.c
		src/ft_power.c
		src/ft_round_double.c
		src/ft_abs_double.c
		src/ft_strsplitwhitespaces.c)

add_library(libft STATIC ${SOURCES} )
