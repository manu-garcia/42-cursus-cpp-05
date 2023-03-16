NAME 		= bureaucrat
SRC_DIR		= ./
SRC 		= 	$(SRC_DIR)/main.cpp \
				$(SRC_DIR)/Bureaucrat.cpp \
				$(SRC_DIR)/AForm.cpp \
				$(SRC_DIR)/ShrubberyCreationForm.cpp \
				$(SRC_DIR)/RobotomyRequestForm.cpp \
				$(SRC_DIR)/PresidentialPardonForm.cpp \

CC 			= c++
INCLUDES	= 
CFLAGS 		= -Wall -Werror -Wextra -std=c++98 -Wshadow $(INCLUDES)
OBJECTS		= 	$(SRC:.cpp=.o)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CFLAGS) -o $@ $^

$(NAME): $(OBJECTS)
	@clear
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "\n\033[92m"-------------\\n👌 COMPILED 👌\\n-------------\\n"\033[0m\n"

all: $(NAME)

clean:
	@clear
	@echo "\n\033[31m"-------------------\\n💣 DELETED FILES 💣\\n-------------------\\n"\033[0m\n"
	@rm -f $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean re test
