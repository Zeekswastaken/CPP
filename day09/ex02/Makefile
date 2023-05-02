SRCS = main.cpp PmergeMe.cpp
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
NAME = PmergeMe

all : $(NAME)
$(NAME) : $(SRCS)
		$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)
clean :
		rm -f $(NAME)
fclean : clean
re : fclean all