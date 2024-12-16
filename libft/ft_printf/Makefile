# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jretter <jretter@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 17:27:46 by jretter           #+#    #+#              #
#    Updated: 2024/10/06 13:56:03 by jretter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for libftprintf.a

NAME = libftprintf.a
CC = cc
AR = ar
CFLAGS = -Wall -Wextra -Werror

# Adding -I. to specify that headers are in the current directory
INCLUDES = -I.

# Source files
SRCS = ft_printf.c ft_putstr.c ft_print_pointer.c ft_putchar.c \
       ft_print_int.c ft_print_uint.c ft_print_hex.c ft_utoa.c ft_utoa_16.c ft_itoa.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): 
		$(CC) $(CFLAGS) -c $(SRCS) 
		$(AR) rcs $(NAME) $(OBJS)
clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all