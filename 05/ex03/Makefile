NAME = ex03

SRCS = Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp  Intern.cpp main.cpp 
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
	${RM} home_shrubbery

fclean :clean
	${RM} ${NAME}

re : fclean all