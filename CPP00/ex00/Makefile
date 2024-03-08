NAME = Megaphone
CC = c++
CFLAGS = -Wall -Werror -Wextra --std=c++98
RM = rm -rf
SRC = megaphone.cpp

all:	$(NAME)

$(NAME) :
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@$(RM) $(NAME)

fclean: clean
	@$(RM) $(NAME)

re: fclean all