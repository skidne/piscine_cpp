#ifndef IMONITORMODULE_H
#define IMONITORMODULE_H

class IMonitorModule {

public:

	virtual ~IMonitorModule() {}

	virtual std::string &	output() = 0;

	virtual	void			draw(int, int) = 0;

	virtual void			hide() = 0;
	
	virtual bool			visible() = 0;

};

#endif