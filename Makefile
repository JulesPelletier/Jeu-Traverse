
#	Sources

SRC			=	srcs/affichage.c				\
				srcs/check_30_rounds.c			\
				srcs/check_victory.c			\
				srcs/create_map.c				\
				srcs/fill_map_with_pawns.c		\
				srcs/init_struct.c				\
				srcs/is_alpha.c					\
				srcs/is_pawn.c					\
				srcs/move_pawn.c 				\
				srcs/saut.c						\
				srcs/secu.c						\
				srcs/swap.c						\
				srcs/update_pos.c				\
				main/main.c						\


#	Includes

INCLUDES	=	includes/lib_func.h	

#	Objects

OBJS		= 	${SRC:.c=.o}

OBJS_B		=	${SRC_BONUS:.c=.o}

#	Output

NAME    = 	traverse

CC      = 	cc

RM      = 	rm -f

AR		= 	ar rcs

CFLAGS	= 	-Wall -Werror -Wextra

all:		${NAME}

.c.o:
			${CC} -c $< -o ${<:.c=.o}

${NAME}:    ${OBJS}
			${CC} -o ${NAME} ${CFLAGS} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:     clean
			${RM} ${NAME}

re:			fclean all

.PHONY:     all clean fclean re