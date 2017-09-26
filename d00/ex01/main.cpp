#include "Contact.class.hpp"

void			addContact(Contact *contact)
{
	int			i = -1;

	while (++i < 11)
	{
		std::cout << "Enter the " << contact->cv[i] << " : ";
		std::cin >> contact->info[i];
	}
}

std::string		trnc(std::string str)
{
	if (str.length() > 10)
		return (str.replace(9, std::string::npos, "."));
	return (str);
}

void			searchContact(Contact phonebook[], int index)
{
	int			i = -1;
	int			input;

	if (index == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}
	while (++i < index)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << trnc(phonebook[i].info[0]) << "|";
		std::cout << std::setw(10) << trnc(phonebook[i].info[1]) << "|";
		std::cout << std::setw(10) << trnc(phonebook[i].info[2]) << std::endl;
	}
	std::cout << "\nEnter the index of the contact: ";
	std::cin >> input;
	i = -1;
	if (input >= 0 && input < index)
		while (++i < 11)
			std::cout	<< phonebook[input].cv[i] << " : "
						<< phonebook[input].info[i] << std::endl;
	else
		std::cout << "Invalid index." << std::endl;
}

int				main(void)
{
	Contact		phonebook[8];
	std::string	comm;
	int			index = 0;

	std::cout	<< "This is your personal phonebook." << std::endl
				<< "Valid commands: ADD, SEARCH, EXIT." << std::endl;
	while (1)
	{
		std::cout << "\nEnter a valid command: ";
		std::cin >> comm;
		if (comm == "EXIT")
		{
			std::cout << "Have a nice day!" << std::endl;
			return (0);
		}
		else if (comm == "ADD")
		{
			if (index > 7)
			{
				std::cout << "Full phonebook." << std::endl;
				continue ;
			}
			addContact(&phonebook[index]);
			index++;
		}
		else if (comm == "SEARCH")
			searchContact(phonebook, index);
		else
			std::cout << "[ " << comm << " ] invalid command." << std::endl; 
	}
	return (1);
}