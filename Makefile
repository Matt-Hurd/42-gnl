# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/25 10:13:56 by mhurd             #+#    #+#              #
#    Updated: 2016/09/23 02:48:40 by mhurd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

IDIR					= includes
SDIR					= srcs

NAME					= test_gnl
OBJS					= main.o get_next_line.o

CC						= gcc
CFLAGS					= -Wall -Werror -Wextra
RM						= rm -f

all						: love

love					: $(NAME)

$(NAME)					:
						make -C libft/ fclean && make -C libft/
						clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
						clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
						clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

%.o						: $(SDIR)/%.c
						$(CC) $(CFLAGS) -c $<

clean					:
						$(RM) $(OBJS)

fclean					: clean
						$(RM) $(NAME)

re						: fclean all
