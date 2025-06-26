#include "Fission.h"

Fission& Fission::operator=(char otherValue)
{
	this->address = MyMemory::FISSION_MEMORY.newAddress();
	myCPU.PUSH(MyMemory::FISSION_MEMORY, this->address, otherValue);
	return *this;
}

Fission& Fission::operator=(Fission &other)
{
	this->address = MyMemory::FISSION_MEMORY.newAddress();
	myCPU.PUSH(MyMemory::FISSION_MEMORY, this->address, MyMemory::FISSION_MEMORY.read(other.address));
	return *this;
}

bool Fission::operator==(char otherValue) const
{
	Fission *temp = new Fission(otherValue);
	myCPU.CMP(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, temp->address);
	delete temp;
	return myCPU.FISSION_REGISTER.getFlag() == 0;
}

bool Fission::operator!=(char otherValue) const
{
	Fission *temp = new Fission(otherValue);
	myCPU.CMP(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, temp->address);
	delete temp;
	return myCPU.FISSION_REGISTER.getFlag() != 0;
}

bool Fission::operator==(Fission &other) const
{
	myCPU.CMP(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, other.address);
	return myCPU.FISSION_REGISTER.getFlag() == 0;
}

bool Fission::operator!=(Fission &other) const
{
	myCPU.CMP(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, other.address);
	return myCPU.FISSION_REGISTER.getFlag() != 0;
}

bool Fission::operator<(char otherValue) const
{
	Fission *temp = new Fission(otherValue);
	myCPU.CMP(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, temp->address);
	delete temp;
	return myCPU.FISSION_REGISTER.getFlag() < 0;
}

bool Fission::operator<=(char otherValue) const
{
	Fission *temp = new Fission(otherValue);
	myCPU.CMP(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, temp->address);
	delete temp;
	return myCPU.FISSION_REGISTER.getFlag() <= 0;
}

bool Fission::operator>(char otherValue) const
{
	Fission *temp = new Fission(otherValue);
	myCPU.CMP(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, temp->address);
	delete temp;
	return myCPU.FISSION_REGISTER.getFlag() > 0;
}

bool Fission::operator>=(char otherValue) const
{
	Fission *temp = new Fission(otherValue);
	myCPU.CMP(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, temp->address);
	delete temp;
	return myCPU.FISSION_REGISTER.getFlag() >= 0;
}

bool Fission::operator<(Fission &other) const
{
	myCPU.CMP(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, other.address);
	return myCPU.FISSION_REGISTER.getFlag() < 0;
}

bool Fission::operator<=(Fission &other) const
{
	myCPU.CMP(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, other.address);
	return myCPU.FISSION_REGISTER.getFlag() <= 0;
}

bool Fission::operator>(Fission &other) const
{
	myCPU.CMP(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, other.address);
	return myCPU.FISSION_REGISTER.getFlag() > 0;
}

bool Fission::operator>=(Fission &other) const
{
	myCPU.CMP(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, other.address);
	return myCPU.FISSION_REGISTER.getFlag() >= 0;
}

Fission& Fission::operator++()
{
	myCPU.ADD(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, 1);
	return *this;
}

Fission& Fission::operator--()
{
	myCPU.SUB(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, 1);
	return *this;
}

Fission& Fission::operator++(int)
{
	myCPU.ADD(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, 1);
	return *this;
}

Fission& Fission::operator--(int)
{
	myCPU.SUB(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, 1);
	return *this;
}

Fission& Fission::operator+=(char otherValue)
{
	myCPU.ADD(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, otherValue);
	return *this;
}

Fission& Fission::operator-=(char otherValue)
{
	myCPU.SUB(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, otherValue);
	return *this;
}

Fission& Fission::operator*=(char otherValue)
{
	myCPU.MUL(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, otherValue);
	return *this;
}

Fission& Fission::operator/=(char otherValue)
{
	myCPU.DIV(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, otherValue);
	return *this;
}

Fission& Fission::operator+=(Fission &other)
{
	myCPU.ADD(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, other.address);
	return *this;
}

Fission& Fission::operator-=(Fission &other)
{
	myCPU.SUB(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, other.address);
	return *this;
}

Fission& Fission::operator*=(Fission &other)
{
	myCPU.MUL(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, other.address);
	return *this;
}

Fission& Fission::operator/=(Fission &other)
{
	myCPU.DIV(myCPU.FISSION_REGISTER, MyMemory::FISSION_MEMORY, address, other.address);
	return *this;
}

Fission Fission::operator+(char otherValue)
{
	Fission result(MyMemory::FISSION_MEMORY.read(address));
	result += otherValue;
	return result;
}

Fission Fission::operator-(char otherValue)
{
	Fission result(MyMemory::FISSION_MEMORY.read(address));
	result -= otherValue;
	return result;
}

Fission Fission::operator*(char otherValue)
{
	Fission result(MyMemory::FISSION_MEMORY.read(address));
	result *= otherValue;
	return result;
}

Fission Fission::operator/(char otherValue)
{
	Fission result(MyMemory::FISSION_MEMORY.read(address));
	result /= otherValue;
	return result;
}

Fission Fission::operator+(Fission &other)
{
	Fission result(MyMemory::FISSION_MEMORY.read(address));
	result += other;
	return result;
}

Fission Fission::operator-(Fission &other)
{
	Fission result(MyMemory::FISSION_MEMORY.read(address));
	result -= other;
	return result;
}

Fission Fission::operator*(Fission &other)
{
	Fission result(MyMemory::FISSION_MEMORY.read(address));
	result *= other;
	return result;
}

Fission Fission::operator/(Fission &other)
{
	Fission result(MyMemory::FISSION_MEMORY.read(address));
	result /= other;
	return result;
}

std::ostream& operator<<(std::ostream &cout, Fission &fission)
{
	cout << MyMemory::FISSION_MEMORY.read(fission.address);
	return cout;
}
