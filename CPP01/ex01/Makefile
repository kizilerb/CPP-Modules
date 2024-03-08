CC = c++ -std=c++98
FLAG = -Wall -Wextra -Werror
Name = zombieHorde
SRC = zombie.cpp main.cpp zombieHorde.cpp

all: $(Name)

$(Name): $(SRC)
	@echo "Compiling..."
	@$(CC) $(FLAG) $(SRC) -o $(Name)

clean:
	@echo "Cleaning..."
	@rm -rf $(Name)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
