NAME = ex03

SRCS = AMateria.cpp Character.cpp Ice.cpp  MateriaSource.cpp Cure.cpp main.cpp
OBJS = ${SRCS:.cpp=.o}
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: ${NAME}

.cpp.o:
	@${CXX} ${CXXFLAGS} -c $< -o $(<:.cpp=.o)

${NAME} : ${OBJS}
	@${CXX} ${OBJS} ${CXXFLAGS} -o ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all