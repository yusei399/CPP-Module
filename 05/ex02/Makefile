NAME = ex02

SRCS = Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp  main.cpp 
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
	${RM} PlanetExpress_shrubbery

re : fclean all