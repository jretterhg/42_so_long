NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Object files for libft
objects = ft_isalpha.o ft_isalnum.o ft_isascii.o ft_isdigit.o ft_isprint.o \
          ft_strlen.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_strlcpy.o  \
          ft_strlcat.o ft_toupper.o ft_tolower.o  ft_strchr.o ft_strrchr.o ft_strncmp.o  \
          ft_atoi.o ft_memchr.o ft_memcmp.o ft_calloc.o ft_strnstr.o ft_strdup.o  \
          ft_substr.o ft_strjoin.o ft_strtrim.o ft_putchar_fd.o ft_putendl_fd.o  \
          ft_putnbr_fd.o ft_putstr_fd.o ft_itoa.o ft_substr.o ft_split.o \
          ft_striteri.o ft_strmapi.o ft_realloc.o ft_printf.o

# Add ft_printf objects to libft
ft_printf_objects = ft_printf/ft_print_hex.o ft_printf/ft_print_int.o \
                    ft_printf/ft_print_pointer.o ft_printf/ft_print_uint.o \
                    ft_printf/ft_putchar.o ft_printf/ft_putstr.o \
                    ft_printf/ft_utoa.o ft_printf/ft_utoa_16.o

all: $(NAME)

$(NAME): $(objects) $(ft_printf_objects)
	ar crs $(NAME) $(objects) $(ft_printf_objects)

# Build ft_printf objects by calling its Makefile
ft_printf/%.o: ft_printf/%.c
	$(MAKE) -C ft_printf

# Clean rules
clean:
	rm -f $(objects)
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ft_printf fclean

re: fclean all
