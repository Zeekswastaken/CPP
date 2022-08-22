SRCS = Fixed.cpp main.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98
CC = clang++
NAME = Fixed
OBJS = $(SRCS:.c=.o)

all : $(NAME)
$(NAME) : $(OBJS)
		$(CC) $(FLAGS) $(SRCS) -o $(NAME)
clean :
		rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all