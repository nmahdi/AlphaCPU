#ifndef FALLOUT_H
#define FALLOUT_H

#include <iostream>
#include "ThemeObject.h"
#include "CPU.h"

class Fallout : public ThemeObject
{
	friend std::ostream& operator<<(std::ostream &cout, Fallout &fallout);
public:
	Fallout() {}
	Fallout(bool otherValue)
	{
		this->address = MyMemory::FALLOUT_MEMORY.newAddress();
		myCPU.PUSH(MyMemory::FALLOUT_MEMORY, this->address, otherValue);	
	}
	Fallout(const Fallout &otherFallout)
	{
		this->address = MyMemory::FALLOUT_MEMORY.newAddress();
		myCPU.PUSH(MyMemory::FALLOUT_MEMORY, this->address, MyMemory::FALLOUT_MEMORY.read(otherFallout.address));
	}

	Fallout &operator=(bool otherValue);
	Fallout &operator=(Fallout &other);

	bool operator==(bool otherValue) const;
	bool operator!=(bool otherValue) const;

	bool operator==(Fallout &other) const;
	bool operator!=(Fallout &other) const;
};

std::ostream& operator<<(std::ostream &cout, Fallout &fallout);

#endif
