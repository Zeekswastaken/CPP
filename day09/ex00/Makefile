SRCS = main.cpp BitcoinExchange.cpp
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
NAME = btc

all : $(NAME)
$(NAME) : $(SRCS)
		$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)
clean :
		rm -f $(NAME)
fclean : clean
re : fclean all