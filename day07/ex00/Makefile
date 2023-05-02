SRCS = main.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
NAME = whatever
#OBJS = $(SRCS:.cpp=.o)

all : $(NAME)
$(NAME) : $(SRCS)
		$(CC) $(FLAGS) $(SRCS) -o $(NAME)
clean :
		rm -f $(NAME)
fclean : clean
re : fclean all