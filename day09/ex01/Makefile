SRCS = main.cpp RPN.cpp
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = RPN
CC = c++

all : $(NAME)
$(NAME) : $(SRCS)
		$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)
clean :
		rm -f $(NAME)
fclean : clean
re : fclean all