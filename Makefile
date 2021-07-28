NAME		= push_swap

CHECKER 	= checker

SRCS		= ${shell find ./srcs/*.c}

SRCS2		= ${shell find ./srcs/*.c -not -name 'main.c'}

CHK_SRCS	= ${shell find ./srcs/checker/*.c}

OBJS		= $(SRCS:.c=.o)

OBJS2		= $(SRCS2:.c=.o)

CHK_OBJS	= $(CHK_SRCS:.c=.o)

HEADER		= ${shell find ./include/*.h}

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
