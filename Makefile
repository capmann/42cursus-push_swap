# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarteau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 18:53:38 by cmarteau          #+#    #+#              #
#    Updated: 2021/09/22 01:52:28 by cmarteau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -g

LIB		=	libft

NAME	=	push_swap

.c		:	.o
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}	:	./libft/libft.a ${OBJS}
				${CC} -L${LIB} ${CFLAGS} ${OBJS} -o ${NAME}

./libft/libft.a	:
		${MAKE} -C ${LIB}

all		:	${NAME}

clean	:
			rm -rf ${OBJS}

fclean	:	clean
			rm -rf ${NAME}
			$(MAKE) -C ${LIB}/. clean

re	:	fclean all

.PHONY	:	all clean fclean re
			
