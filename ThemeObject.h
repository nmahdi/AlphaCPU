#ifndef THEMEOBJECT_H
#define THEMEOBJECT_H

#include "CPU.h"

class ThemeObject
{
	friend class CPU;
	protected:
		int address;
		
		void setAddress(int address);
		int getAddress();
	public:
		ThemeObject() {}
};



#endif
