SRCS 		= 	push_swap.c utils/pars_args.c utils/sort_three_and_five.c utils/algorithm.c list_functions/list_move.c \
				list_functions/list_stack.c libft/ft_strlen.c libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c \
				libft/ft_split.c libft/ft_substr.c utils/sort_two.c utils/sort_utils.c list_functions/list_move_utils.c \
				list_functions/list_init.c utils/help_functions_to_algorithm.c utils/algorithm_utils.c utils/push_swap_utils.c \
				utils/ft_atoi_long.c
CHECK		=	my_checker/my_checker.c my_checker/run_comands.c my_checker/g_n_l/get_next_line.c my_checker/g_n_l/get_next_line_utils.c \
				list_functions/list_stack.c list_functions/list_move.c utils/pars_args.c libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c \
				libft/ft_split.c libft/ft_substr.c libft/ft_strlen.c list_functions/list_move_utils.c list_functions/list_init.c \
				utils/help_functions_to_algorithm.c utils/push_swap_utils.c utils/sort_three_and_five.c utils/sort_two.c utils/sort_utils.c \
				libft/ft_strncmp.c utils/ft_atoi_long.c
NAME		= 	push_swap
INCS		=	./
GCC			=	gcc
CHECKER		=	checker
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror

all:			${NAME}

${NAME}:
	${GCC} ${CFLAGS} ${SRCS} -I${INCS} -o ${NAME}

bonus:			${CHECKER}

${CHECKER}:
	${GCC} ${CFLAGS} ${CHECK} -I${INCS} -o ${CHECKER}




clean:
				${RM} ${NAME} ${CHECKER}

fclean:			clean
				${RM} ${NAME}

re:				fclean all
.PHONY:
				all, fclean, clean, re