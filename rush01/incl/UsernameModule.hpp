#ifndef USERNAMEMODULE_H
#define USERNAMEMODULE_H

#include "header.hpp"

class UsernameModule : public IMonitorModule {

public:

	UsernameModule();
	UsernameModule(UsernameModule & r);
	~UsernameModule();

	UsernameModule & operator=(UsernameModule & r);


	
};

#endif