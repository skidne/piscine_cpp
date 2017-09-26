#include "Fixed.hpp"

Fixed		nrStack[100];
char		opStack[100];
int			nrPeek = 0;
int			opPeek = 0;

void	ft_exit(std::string const & str)
{
	std::cout << str << std::endl;
	exit(1);
}

int		priority(char opo)
{
	if (opo == '+' || opo == '-')
		return 1;
	if (opo == '*' || opo == '/')
		return 2;
	return 0;
}

void	pushNr(Fixed nr)
{
	nrStack[nrPeek++] = nr;
}

Fixed	popNr()
{
	return nrStack[--nrPeek];
}

char	popOp()
{
	return opStack[--opPeek];
}

Fixed	solve(Fixed a, char op, Fixed b)
{
	if (op == '+')
		return b + a;
	if (op == '-')
		return a - b;
	if (op == '*')
		return a * b;
	if (op == '/' && b != Fixed(0))
		return a / b;
	if (op == '/' && b == Fixed(0))
		ft_exit("Division by zero");
	return Fixed(0);
}

void	pushOp(char op, bool * openParent)
{
	if (opPeek == 0 || priority(op) > priority(opStack[opPeek - 1]) ||
		op == '(')
	{
		if (op == '(')
			*openParent = true;
		opStack[opPeek++] = op;
		return ;
	}
	else if (priority(op) <= priority(opStack[opPeek - 1]))
	{
		pushNr(solve(popNr(), popOp(), popNr()));
		pushOp(op, openParent);
	}
}

bool	is_op(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(')
		return true;
	return false;
}

void	eval_expr(char *str)
{
	char	s[100];
	int		j;
	bool	openParent = false;

	for (int i = 0; str[i]; i++)
	{
		memset(s, 0, sizeof(s));
		if (str[i] == ' ')
			continue ;
		j = 0;
		if (isdigit(str[i]))
		{
			while ((str[i] && isdigit(str[i])) || (str[i] == '.' && str[i - 1] &&
				isdigit(str[i - 1]) && str[i + 1] && isdigit(str[i + 1])))
				s[j++] = str[i++];
			pushNr(Fixed(atof(s)));
			i--;
		}
		else if(is_op(str[i]))
			pushOp(str[i], &openParent);
		else if (str[i] == ')')
		{
			openParent = false;
			while (opPeek - 1 > -1 && opStack[opPeek - 1] != '(')
				pushNr(solve(popNr(), popOp(), popNr()));
			if (opStack[opPeek - 1] != '(')
				ft_exit("Parsing parentheses failed");
			popOp();
		}
		else
			ft_exit("Something went wrong");
	}
	if (openParent || !nrPeek)
		ft_exit("Error parsing");
	while (opPeek > 0)
		pushNr(solve(popNr(), popOp(), popNr()));
	std::cout << nrStack[0] << std::endl;
}

int		main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "Usage: ./eval_expr \"math expression\"" << std::endl;
	else
		eval_expr(av[1]);
	return 1;
}