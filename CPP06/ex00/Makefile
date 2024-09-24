CC = c++ -std=c++98
FLAG = -Wall -Wextra -Werror 
NAME = Convert
SRC = Convert.cpp ScalarConverter.cpp Print.cpp main.cpp

all: $(NAME)

$(NAME): $(SRC)
	@echo "Compiling..."
	@$(CC) $(FLAG) $(SRC) -o $(NAME)

clean:
	@echo "Cleaning..."

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re