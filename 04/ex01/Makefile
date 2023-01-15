NAME = ex01

SRCS = Animal.cpp Cat.cpp WrongAnimal.cpp  Brain.cpp WrongCat.cpp Dog.cpp main.cpp
OBJS = ${SRCS:.cpp=.o}
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98


all : ${NAME}

.cpp.o:
	@${CXX} ${CXXFLAGS} -c $< -o $(<:.cpp=.o)

${NAME} : ${OBJS}
	@${CXX} ${OBJS} ${CXXFLAGS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean :clean
	${RM} ${NAME}

re : fclean all
