#include "Contact.class.hpp"

Contact::Contact(void)
{
	this->cv[0] = "first name";
	this->cv[1] = "last name";
	this->cv[2] = "nickname";
	this->cv[3] = "login";
	this->cv[4] = "postal address";
	this->cv[5] = "email address";
	this->cv[6] = "phone number";
	this->cv[7] = "birthday date";
	this->cv[8] = "favorite meal";
	this->cv[9] = "underwear color";
	this->cv[10] = "darkest secret";
	return;
}

Contact::~Contact(void)
{ return; }
