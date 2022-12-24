# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 11:41:50 by jdomingu          #+#    #+#              #
#    Updated: 2022/06/21 17:59:03 by jdomingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/ft_printf.c src/ft_print_things.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
LIBFT = libft
INCLUDE = include
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I
RM = rm -f

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
			@make -C $(LIBFT)
			@mv libft/libft.a $(NAME)
			ar -rc $(NAME) $(OBJS)
clean:
		$(RM) $(OBJS)
		@make clean -C $(LIBFT)

fclean: clean
		$(RM) $(NAME)
		$(RM) $(LIBFT)/libft.a

re: fclean all

.PHONY: all clean fclean re
