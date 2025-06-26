#include "Littleboy.h"

/*
	Assignment overloads
*/
LittleBoy& LittleBoy::operator=(float otherValue)
{
	this->address = MyMemory::LITTLEBOY_MEMORY.newAddress();
	myCPU.PUSH(MyMemory::LITTLEBOY_MEMORY, this->address, otherValue);
	return *this;
}

LittleBoy& LittleBoy::operator=(LittleBoy &other)
{
	this->address = MyMemory::LITTLEBOY_MEMORY.newAddress();
	myCPU.PUSH(MyMemory::LITTLEBOY_MEMORY, this->address, MyMemory::LITTLEBOY_MEMORY.read(other.address));
	return *this;
}

/*
	Comparison overloads
*/
bool LittleBoy::operator==(float otherValue) const
{
	LittleBoy *temp = new LittleBoy(otherValue);
	myCPU.CMP(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, temp->address);
	delete temp;
	return myCPU.LITTLEBOY_REGISTER.getFlag() == 0;
}

bool LittleBoy::operator!=(float otherValue) const
{
	LittleBoy *temp = new LittleBoy(otherValue);
	myCPU.CMP(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, temp->address);
	delete temp;
	return myCPU.LITTLEBOY_REGISTER.getFlag() != 0;
}

bool LittleBoy::operator==(LittleBoy &other) const
{
	myCPU.CMP(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, other.address);
	return myCPU.LITTLEBOY_REGISTER.getFlag() == 0;
}

bool LittleBoy::operator!=(LittleBoy &other) const
{
	myCPU.CMP(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, other.address);
	return myCPU.LITTLEBOY_REGISTER.getFlag() != 0;
}

bool LittleBoy::operator<(float otherValue) const 
{
	LittleBoy *temp = new LittleBoy(otherValue);
	myCPU.CMP(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, temp->address);
	delete temp;
	return myCPU.LITTLEBOY_REGISTER.getFlag() < 0;
}

bool LittleBoy::operator<=(float otherValue) const 
{
	LittleBoy *temp = new LittleBoy(otherValue);
	myCPU.CMP(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, temp->address);
	delete temp;
	return myCPU.LITTLEBOY_REGISTER.getFlag() <= 0;
}

bool LittleBoy::operator>(float otherValue) const 
{
	LittleBoy *temp = new LittleBoy(otherValue);
	myCPU.CMP(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, temp->address);
	delete temp;
	return myCPU.LITTLEBOY_REGISTER.getFlag() > 0;
}

bool LittleBoy::operator>=(float otherValue) const 
{
	LittleBoy *temp = new LittleBoy(otherValue);
	myCPU.CMP(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, temp->address);
	delete temp;
	return myCPU.LITTLEBOY_REGISTER.getFlag() >= 0;
}

bool LittleBoy::operator<(LittleBoy &other) const 
{
	myCPU.CMP(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, other.address);
	return myCPU.LITTLEBOY_REGISTER.getFlag() < 0;
}

bool LittleBoy::operator<=(LittleBoy &other) const 
{
	myCPU.CMP(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, other.address);
	return myCPU.LITTLEBOY_REGISTER.getFlag() <= 0;
}

bool LittleBoy::operator>(LittleBoy &other) const 
{
	myCPU.CMP(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, other.address);
	return myCPU.LITTLEBOY_REGISTER.getFlag() > 0;
}

bool LittleBoy::operator>=(LittleBoy &other) const 
{
	myCPU.CMP(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, other.address);
	return myCPU.LITTLEBOY_REGISTER.getFlag() >= 0;
}

/*
	Modification overloads
*/
LittleBoy& LittleBoy::operator++()
{
	LittleBoy *temp = new LittleBoy(1.0f);
	myCPU.ADD(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, temp->address);
	delete temp;
	return *this;
}

LittleBoy& LittleBoy::operator++(int)
{
	LittleBoy *temp = new LittleBoy(1.0f);
	myCPU.ADD(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, temp->address);
	delete temp;
	return *this;
}

LittleBoy& LittleBoy::operator--()
{
	LittleBoy *temp = new LittleBoy(1.0f);
	myCPU.SUB(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, temp->address);
	delete temp;
	return *this;
}

LittleBoy& LittleBoy::operator--(int)
{
	LittleBoy *temp = new LittleBoy(1.0f);
	myCPU.SUB(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, temp->address);
	delete temp;
	return *this;
}

LittleBoy& LittleBoy::operator+=(float otherValue)
{
	LittleBoy *temp = new LittleBoy(otherValue);
	myCPU.ADD(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, temp->address);
	delete temp;
	return *this;
}

LittleBoy& LittleBoy::operator-=(float otherValue)
{
	LittleBoy *temp = new LittleBoy(otherValue);
	myCPU.SUB(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, temp->address);
	delete temp;
	return *this;
}

LittleBoy& LittleBoy::operator*=(float otherValue)
{
	LittleBoy *temp = new LittleBoy(otherValue);
	myCPU.MUL(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, temp->address);
	delete temp;
	return *this;
}

LittleBoy& LittleBoy::operator/=(float otherValue)
{
	LittleBoy *temp = new LittleBoy(otherValue);
	myCPU.DIV(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, temp->address);
	delete temp;
	return *this;
}

LittleBoy& LittleBoy::operator+=(LittleBoy &other)
{
	myCPU.ADD(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, other.address);
	return *this;
}

LittleBoy& LittleBoy::operator-=(LittleBoy &other)
{
	myCPU.SUB(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, other.address);
	return *this;
}

LittleBoy& LittleBoy::operator*=(LittleBoy &other)
{
	myCPU.MUL(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, other.address);
	return *this;
}

LittleBoy& LittleBoy::operator/=(LittleBoy &other)
{
	myCPU.DIV(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, address, other.address);
	return *this;
}

/*
	Operation overloads
*/
LittleBoy LittleBoy::operator+(float otherValue)
{
	LittleBoy copy(MyMemory::LITTLEBOY_MEMORY.read(address));
	LittleBoy *temp = new LittleBoy(otherValue);
	myCPU.ADD(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, copy.address, temp->address);
	delete temp;
	return copy;	
}

LittleBoy LittleBoy::operator-(float otherValue)
{
	LittleBoy copy(MyMemory::LITTLEBOY_MEMORY.read(address));
	LittleBoy *temp = new LittleBoy(otherValue);
	myCPU.SUB(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, copy.address, temp->address);
	delete temp;
	return copy;	
}

LittleBoy LittleBoy::operator*(float otherValue)
{
	LittleBoy copy(MyMemory::LITTLEBOY_MEMORY.read(address));
	LittleBoy *temp = new LittleBoy(otherValue);
	myCPU.MUL(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, copy.address, temp->address);
	delete temp;
	return copy;	
}

LittleBoy LittleBoy::operator/(float otherValue)
{
	LittleBoy copy(MyMemory::LITTLEBOY_MEMORY.read(address));
	LittleBoy *temp = new LittleBoy(otherValue);
	myCPU.DIV(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, copy.address, temp->address);
	delete temp;
	return copy;	
}

LittleBoy LittleBoy::operator+(LittleBoy &other)
{
	LittleBoy copy(MyMemory::LITTLEBOY_MEMORY.read(address));
	myCPU.ADD(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, copy.address, other.address);
	return copy;
}

LittleBoy LittleBoy::operator-(LittleBoy &other)
{
	LittleBoy copy(MyMemory::LITTLEBOY_MEMORY.read(address));
	myCPU.SUB(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, copy.address, other.address);
	return copy;
}

LittleBoy LittleBoy::operator*(LittleBoy &other)
{
	LittleBoy copy(MyMemory::LITTLEBOY_MEMORY.read(address));
	myCPU.MUL(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, copy.address, other.address);
	return copy;
}

LittleBoy LittleBoy::operator/(LittleBoy &other)
{
	LittleBoy copy(MyMemory::LITTLEBOY_MEMORY.read(address));
	myCPU.DIV(myCPU.LITTLEBOY_REGISTER, MyMemory::LITTLEBOY_MEMORY, copy.address, other.address);
	return copy;
}

/*
	Functions
*/
std::ostream& operator<<(std::ostream &cout, LittleBoy &littleboy)
{
	cout << MyMemory::LITTLEBOY_MEMORY.read(littleboy.address);
	return cout;
}
