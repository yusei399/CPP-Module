CC = c++
FLAG = -Wall -Wextra -Werror -std=c++98
NAME = megaphone
SRCS = megaphone.cpp
OBJS	= ${SRCS:.cpp=.o}


all: ${NAME}

.cpp.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)


clean:
	$(RM) $(OBJS)
	$(RM) $(NAME)

fclean:clean

re: fclean all