NAME = ex00

SRCS = Bureaucrat.cpp main.cpp
OBJS = ${SRCS:.cpp=.o}
CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98


all : ${NAME}

.cpp.o:
	@${CC} ${CFLAGS} -c $< -o $(<:.cpp=.o)

${NAME} : ${OBJS}
	@${CC} ${OBJS} ${CFLAGS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean :clean
	${RM} ${NAME}

re : fclean all
