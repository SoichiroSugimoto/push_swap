NAME	= push_swap

SRCS	= ${shell find ./srcs/*.c}

OBJS	= $(SRCS:.c=.o)

HEADER	= ${shell find ./include/*.h}

LIBFT	= ./libft/libft.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror


#サフィックスルールに基づいた記述
#.oファイルが必要になれば.cファイルから作成する
# .c.o :
# 	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

all : $(NAME)

#コンパイル後に.cファイルの一部を変更した場合、再度コンパイルしようとすれば全ての.cファイルをコンパイルする必要がある
#.oファイルを使えば二度手間を省ける。
#必須項目として.oファイル'$(OBJS)'を指定すれば自動生成される。
$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT) -L ./libft -lft
# cp libft/libft.a push_swap
# ar rcs $(NAME) $(OBJS)

$(LIBFT) :
	make -C libft

clean :
	rm -f $(OBJS)
	make clean -C libft

fclean : clean
	rm -f $(NAME)
	make fclean -C libft

re : fclean all

.PHONY : all clean fclean re
