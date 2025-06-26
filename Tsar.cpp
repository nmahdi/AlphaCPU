#include "Tsar.h"

/*
	Assignment overloads
*/
Tsar& Tsar::operator=(int otherValue)
{
	this->address = MyMemory::TSAR_MEMORY.newAddress();
	myCPU.PUSH(MyMemory::TSAR_MEMORY, this->address, otherValue);
	return *this;
}

Tsar& Tsar::operator=(Tsar &other)
{
	this->address = MyMemory::TSAR_MEMORY.newAddress();
	myCPU.PUSH(MyMemory::TSAR_MEMORY, this->address, MyMemory::TSAR_MEMORY.read(other.address));
	return *this;
}

/*
	Comparison overloads
*/
bool Tsar::operator==(int otherValue) const
{
	Tsar *temp = new Tsar(otherValue);
	myCPU.CMP(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, temp->address);
	delete temp;
	return myCPU.TSAR_REGISTER.getFlag() == 0;
}

bool Tsar::operator!=(int otherValue) const
{
	Tsar *temp = new Tsar(otherValue);
	myCPU.CMP(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, temp->address);
	delete temp;
	return myCPU.TSAR_REGISTER.getFlag() != 0;
}

bool Tsar::operator==(Tsar &other) const
{
	myCPU.CMP(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, other.address);
	return myCPU.TSAR_REGISTER.getFlag() == 0;
}

bool Tsar::operator!=(Tsar &other) const
{
	myCPU.CMP(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, other.address);
	return myCPU.TSAR_REGISTER.getFlag() != 0;
}

bool Tsar::operator<(int otherValue) const 
{
	Tsar *temp = new Tsar(otherValue);
	myCPU.CMP(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, temp->address);
	delete temp;
	return myCPU.TSAR_REGISTER.getFlag() < 0;
}

bool Tsar::operator<=(int otherValue) const 
{
	Tsar *temp = new Tsar(otherValue);
	myCPU.CMP(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, temp->address);
	delete temp;
	return myCPU.TSAR_REGISTER.getFlag() <= 0;
}

bool Tsar::operator>(int otherValue) const 
{
	Tsar *temp = new Tsar(otherValue);
	myCPU.CMP(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, temp->address);
	delete temp;
	return myCPU.TSAR_REGISTER.getFlag() > 0;
}

bool Tsar::operator>=(int otherValue) const 
{
	Tsar *temp = new Tsar(otherValue);
	myCPU.CMP(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, temp->address);
	delete temp;
	return myCPU.TSAR_REGISTER.getFlag() >= 0;
}

bool Tsar::operator<(Tsar &other) const 
{
	myCPU.CMP(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, other.address);
	return myCPU.TSAR_REGISTER.getFlag() < 0;
}

bool Tsar::operator<=(Tsar &other) const 
{
	myCPU.CMP(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, other.address);
	return myCPU.TSAR_REGISTER.getFlag() <= 0;
}

bool Tsar::operator>(Tsar &other) const 
{
	myCPU.CMP(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, other.address);
	return myCPU.TSAR_REGISTER.getFlag() > 0;
}

bool Tsar::operator>=(Tsar &other) const 
{
	myCPU.CMP(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, other.address);
	return myCPU.TSAR_REGISTER.getFlag() >= 0;
}

/*
	Modification overloads
*/
Tsar& Tsar::operator++()
{
	Tsar *temp = new Tsar(1);
	myCPU.ADD(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, temp->address);
	delete temp;
	return *this;
}

Tsar& Tsar::operator++(int)
{
	Tsar *temp = new Tsar(1);
	myCPU.ADD(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, temp->address);
	delete temp;
	return *this;
}

Tsar& Tsar::operator--()
{
	Tsar *temp = new Tsar(1);
	myCPU.SUB(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, temp->address);
	delete temp;
	return *this;
} 

Tsar& Tsar::operator--(int)
{
	Tsar *temp = new Tsar(1);
	myCPU.SUB(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, temp->address);
	delete temp;
	return *this;
}

Tsar& Tsar::operator+=(int otherValue)
{
	Tsar *temp = new Tsar(otherValue);
	myCPU.ADD(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, temp->address);
	delete temp;
	return *this;
}

Tsar& Tsar::operator-=(int otherValue)
{
	Tsar *temp = new Tsar(otherValue);
	myCPU.SUB(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, temp->address);
	delete temp;
	return *this;
}

Tsar& Tsar::operator*=(int otherValue)
{
	Tsar *temp = new Tsar(otherValue);
	myCPU.MUL(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, temp->address);
	delete temp;
	return *this;
}

Tsar& Tsar::operator/=(int otherValue)
{
	Tsar *temp = new Tsar(otherValue);
	myCPU.DIV(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, temp->address);
	delete temp;
	return *this;
}

Tsar& Tsar::operator+=(Tsar &other)
{
	myCPU.ADD(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, other.address);
	return *this;
}

Tsar& Tsar::operator-=(Tsar &other)
{
	myCPU.SUB(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, other.address);
	return *this;
}

Tsar& Tsar::operator*=(Tsar &other)
{
	myCPU.MUL(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, other.address);
	return *this;
}

Tsar& Tsar::operator/=(Tsar &other)
{
	myCPU.DIV(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, address, other.address);
	return *this;
}

/*
	Operation overloads
*/
Tsar Tsar::operator+(int otherValue)
{
	Tsar copy(MyMemory::TSAR_MEMORY.read(address));
	Tsar *temp = new Tsar(otherValue);
	myCPU.ADD(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, copy.address, temp->address);
	delete temp;
	return copy;	
}

Tsar Tsar::operator-(int otherValue)
{
	Tsar copy(MyMemory::TSAR_MEMORY.read(address));
	Tsar *temp = new Tsar(otherValue);
	myCPU.SUB(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, copy.address, temp->address);
	delete temp;
	return copy;	
}

Tsar Tsar::operator*(int otherValue)
{
	Tsar copy(MyMemory::TSAR_MEMORY.read(address));
	Tsar *temp = new Tsar(otherValue);
	myCPU.MUL(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, copy.address, temp->address);
	delete temp;
	return copy;	
}

Tsar Tsar::operator/(int otherValue)
{
	Tsar copy(MyMemory::TSAR_MEMORY.read(address));
	Tsar *temp = new Tsar(otherValue);
	myCPU.DIV(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, copy.address, temp->address);
	delete temp;
	return copy;	
}

Tsar Tsar::operator+(Tsar &other)
{
	Tsar copy(MyMemory::TSAR_MEMORY.read(address));
	myCPU.ADD(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, copy.address, other.address);
}

Tsar Tsar::operator-(Tsar &other)
{
	Tsar copy(MyMemory::TSAR_MEMORY.read(address));
	myCPU.SUB(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, copy.address, other.address);
}

Tsar Tsar::operator*(Tsar &other)
{
	Tsar copy(MyMemory::TSAR_MEMORY.read(address));
	myCPU.MUL(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, copy.address, other.address);
}

Tsar Tsar::operator/(Tsar &other)
{
	Tsar copy(MyMemory::TSAR_MEMORY.read(address));
	myCPU.DIV(myCPU.TSAR_REGISTER, MyMemory::TSAR_MEMORY, copy.address, other.address);
}

/*
	Functions
*/
std::ostream& operator<<(std::ostream &cout, Tsar &tsar)
{
	cout << MyMemory::TSAR_MEMORY.read(tsar.address);
	return cout;
}
