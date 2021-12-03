NAME		= push_swap

CHECKER 	= checker

SRCS		=	srcs/arrange_output.c \
				srcs/insert_contents.c \
				srcs/reverse_rotate_operation.c \
				srcs/under6_sort.c \
				srcs/check_sorted.c \
				srcs/main.c \
				srcs/rotate_operation.c \
				srcs/use_operations_utils.c \
				srcs/over7_sort.c \
				srcs/sort_number.c \
				srcs/utils.c \
				srcs/get_as_str.c \
				srcs/over7_sort_utils.c \
				srcs/sort_number_utils.c \
				srcs/utils2nd.c \
				srcs/get_median.c \
				srcs/over7_sort_utils2.c \
				srcs/swap_operation.c \
				srcs/get_median_2nd.c \
				srcs/over7_sort_utils3.c \
				srcs/under3_sort.c \
				srcs/get_struct_ps.c \
				srcs/push_operation.c \
				srcs/under3_sort_b.c \

SRCS2		=	srcs/arrange_output.c \
				srcs/insert_contents.c \
				srcs/reverse_rotate_operation.c \
				srcs/under6_sort.c \
				srcs/check_sorted.c \
				srcs/rotate_operation.c \
				srcs/use_operations_utils.c \
				srcs/over7_sort.c \
				srcs/sort_number.c \
				srcs/utils.c \
				srcs/get_as_str.c \
				srcs/over7_sort_utils.c \
				srcs/sort_number_utils.c \
				srcs/utils2nd.c \
				srcs/get_median.c \
				srcs/over7_sort_utils2.c \
				srcs/swap_operation.c \
				srcs/get_median_2nd.c \
				srcs/over7_sort_utils3.c \
				srcs/under3_sort.c \
				srcs/get_struct_ps.c \
				srcs/push_operation.c \
				srcs/under3_sort_b.c \

CHK_SRCS	=	srcs/checker/checker.c \
				srcs/checker/checker_operation2nd.c \
				srcs/checker/checker_sort.c \
				srcs/checker/checker_2nd.c \
				srcs/checker/checker_operationc.c \
				srcs/checker/checker_utils.c \

OBJS		= $(SRCS:.c=.o)

OBJS2		= $(SRCS2:.c=.o)

CHK_OBJS	= $(CHK_SRCS:.c=.o)

HEADER		=	include/checker.h \
				include/push_swap.h \
				include/structs.h \
				include/utils.h \
				include/insert_contents.h \
				include/sort_number.h \
				include/use_operations.h \

LIBFT		= ./libft/libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -L ./libft -lft

$(CHECKER) : $(OBJS2) $(CHK_OBJS)
	make -C libft
	$(CC) $(CFLAGS) -o $(CHECKER) $(OBJS2) $(CHK_OBJS) $(LIBFT) -L ./libft -lft

$(LIBFT) :
	make -C libft

clean :
	rm -f $(OBJS)
	rm -f $(OBJS2) $(CHK_OBJS)
	make clean -C libft

fclean : clean
	rm -f $(NAME)
	rm -f $(CHECKER)
	make fclean -C libft

re : fclean all

.PHONY : all clean fclean re
