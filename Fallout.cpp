#include "Fallout.h"

Fallout& Fallout::operator=(bool otherValue)
{
	this->address = MyMemory::FALLOUT_MEMORY.newAddress();
	myCPU.PUSH(MyMemory::FALLOUT_MEMORY, this->address, otherValue);
	return *this;
}

Fallout& Fallout::operator=(Fallout &other)
{
	this->address = MyMemory::FALLOUT_MEMORY.newAddress();
	myCPU.PUSH(MyMemory::FALLOUT_MEMORY, this->address, MyMemory::FALLOUT_MEMORY.read(other.address));
	return *this;
}

bool Fallout::operator==(bool otherValue) const
{
	Fallout *temp = new Fallout(otherValue);
	myCPU.CMP(myCPU.FALLOUT_REGISTER, MyMemory::FALLOUT_MEMORY, address, temp->address);
	delete temp;
	return myCPU.FALLOUT_REGISTER.getFlag() == 0;
}

bool Fallout::operator!=(bool otherValue) const
{
	Fallout *temp = new Fallout(otherValue);
	myCPU.CMP(myCPU.FALLOUT_REGISTER, MyMemory::FALLOUT_MEMORY, address, temp->address);
	delete temp;
	return myCPU.FALLOUT_REGISTER.getFlag() != 0;
}

bool Fallout::operator==(Fallout &other) const
{
	myCPU.CMP(myCPU.FALLOUT_REGISTER, MyMemory::FALLOUT_MEMORY, address, other.address);
	return myCPU.FALLOUT_REGISTER.getFlag() == 0;
}

bool Fallout::operator!=(Fallout &other) const
{
	myCPU.CMP(myCPU.FALLOUT_REGISTER, MyMemory::FALLOUT_MEMORY, address, other.address);
	return myCPU.FALLOUT_REGISTER.getFlag() != 0;
}

