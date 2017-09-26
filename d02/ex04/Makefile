NAME = eval_expr
GC = g++ -Wall -Wextra -Werror
SRC =	main.cpp \
		Fixed.cpp

all:
	$(GC) $(SRC) $(INCL) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all, fclean, re
