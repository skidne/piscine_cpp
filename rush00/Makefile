NAME = ft_retro
GC = g++ -Wall -Wextra -Werror
SRC = src/*.cpp
INCL = -I./incl/

all:
	$(GC) $(SRC) $(INCL) -lncurses -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all, fclean, re
