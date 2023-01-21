NAME = ex03

SRCS = Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp  Intern.cpp main.cpp 
OBJS = ${SRCS:.cpp=.o}
CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98


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