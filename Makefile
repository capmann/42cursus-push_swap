# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarteau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 18:53:38 by cmarteau          #+#    #+#              #
#    Updated: 2021/09/26 16:50:26 by cmarteau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c ft_error.c ft_sort_algo.c ft_lstops.c ft_commands.c ft_big_sort.c ft_launch_sorts.c

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -g

LIB		=	libft

LIBPATH =	./libft/libft.a

NAME	=	push_swap

.c		:	.o
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}	:	${LIBPATH} ${OBJS}
		${CC} ${CFLAGS} ${OBJS} ${LIBPATH} -o ${NAME}

${LIBPATH}	:
		${MAKE} -C ${LIB}

all		:	${NAME}

clean	:
			rm -rf ${OBJS}

fclean	:	clean
			rm -rf ${NAME}
			$(MAKE) -C ${LIB}/. clean

re	:	fclean all

.PHONY	:	all clean fclean re
			
