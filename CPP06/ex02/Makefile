CC = c++ -std=c++98
FLAG = -Wall -Wextra -Werror 
NAME = Base
SRC = A.cpp B.cpp C.cpp Base.cpp Identify.cpp main.cpp

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