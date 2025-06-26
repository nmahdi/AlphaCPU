#include "Trinity.h"

/*
    Assignment overloads
*/
Trinity& Trinity::operator=(long otherValue)
{
    this->address = MyMemory::TRINITY_MEMORY.newAddress();
    myCPU.PUSH(MyMemory::TRINITY_MEMORY, this->address, otherValue);
    return *this;
}

Trinity& Trinity::operator=(Trinity &other)
{
    this->address = MyMemory::TRINITY_MEMORY.newAddress();
    myCPU.PUSH(MyMemory::TRINITY_MEMORY, this->address, MyMemory::TRINITY_MEMORY.read(other.address));
    return *this;
}

/*
    Comparison overloads
*/
bool Trinity::operator==(long otherValue) const
{
    Trinity *temp = new Trinity(otherValue);
    myCPU.CMP(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, temp->address);
    delete temp;
    return myCPU.TRINITY_REGISTER.getFlag() == 0;
}

bool Trinity::operator!=(long otherValue) const
{
    Trinity *temp = new Trinity(otherValue);
    myCPU.CMP(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, temp->address);
    delete temp;
    return myCPU.TRINITY_REGISTER.getFlag() != 0;
}

bool Trinity::operator==(Trinity &other) const
{
    myCPU.CMP(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, other.address);
    return myCPU.TRINITY_REGISTER.getFlag() == 0;
}

bool Trinity::operator!=(Trinity &other) const
{
    myCPU.CMP(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, other.address);
    return myCPU.TRINITY_REGISTER.getFlag() != 0;
}

bool Trinity::operator<(long otherValue) const 
{
    Trinity *temp = new Trinity(otherValue);
    myCPU.CMP(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, temp->address);
    delete temp;
    return myCPU.TRINITY_REGISTER.getFlag() < 0;
}

bool Trinity::operator<=(long otherValue) const 
{
    Trinity *temp = new Trinity(otherValue);
    myCPU.CMP(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, temp->address);
    delete temp;
    return myCPU.TRINITY_REGISTER.getFlag() <= 0;
}

bool Trinity::operator>(long otherValue) const 
{
    Trinity *temp = new Trinity(otherValue);
    myCPU.CMP(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, temp->address);
    delete temp;
    return myCPU.TRINITY_REGISTER.getFlag() > 0;
}

bool Trinity::operator>=(long otherValue) const 
{
    Trinity *temp = new Trinity(otherValue);
    myCPU.CMP(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, temp->address);
    delete temp;
    return myCPU.TRINITY_REGISTER.getFlag() >= 0;
}

bool Trinity::operator<(Trinity &other) const 
{
    myCPU.CMP(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, other.address);
    return myCPU.TRINITY_REGISTER.getFlag() < 0;
}

bool Trinity::operator<=(Trinity &other) const 
{
    myCPU.CMP(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, other.address);
    return myCPU.TRINITY_REGISTER.getFlag() <= 0;
}

bool Trinity::operator>(Trinity &other) const 
{
    myCPU.CMP(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, other.address);
    return myCPU.TRINITY_REGISTER.getFlag() > 0;
}

bool Trinity::operator>=(Trinity &other) const 
{
    myCPU.CMP(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, other.address);
    return myCPU.TRINITY_REGISTER.getFlag() >= 0;
}

/*
    Modification overloads
*/
Trinity& Trinity::operator++()
{
    Trinity *temp = new Trinity(1);
    myCPU.ADD(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, temp->address);
    delete temp;
    return *this;
}

Trinity& Trinity::operator++(int)
{
    Trinity *temp = new Trinity(1);
    myCPU.ADD(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, temp->address);
    delete temp;
    return *this;
}

Trinity& Trinity::operator--()
{
    Trinity *temp = new Trinity(1);
    myCPU.SUB(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, temp->address);
    delete temp;
    return *this;
}

Trinity& Trinity::operator--(int)
{
    Trinity *temp = new Trinity(1);
    myCPU.SUB(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, temp->address);
    delete temp;
    return *this;
}

Trinity& Trinity::operator+=(long otherValue)
{
    Trinity *temp = new Trinity(otherValue);
    myCPU.ADD(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, temp->address);
    delete temp;
    return *this;
}

Trinity& Trinity::operator-=(long otherValue)
{
    Trinity *temp = new Trinity(otherValue);
    myCPU.SUB(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, temp->address);
    delete temp;
    return *this;
}

Trinity& Trinity::operator*=(long otherValue)
{
    Trinity *temp = new Trinity(otherValue);
    myCPU.MUL(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, temp->address);
    delete temp;
    return *this;
}

Trinity& Trinity::operator/=(long otherValue)
{
    Trinity *temp = new Trinity(otherValue);
    myCPU.DIV(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, temp->address);
    delete temp;
    return *this;
}

Trinity& Trinity::operator+=(Trinity &other)
{
    myCPU.ADD(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, other.address);
    return *this;
}

Trinity& Trinity::operator-=(Trinity &other)
{
    myCPU.SUB(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, other.address);
    return *this;
}

Trinity& Trinity::operator*=(Trinity &other)
{
    myCPU.MUL(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, other.address);
    return *this;
}

Trinity& Trinity::operator/=(Trinity &other)
{
    myCPU.DIV(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, address, other.address);
    return *this;
}

/*
    Operation overloads
*/
Trinity Trinity::operator+(long otherValue)
{
    Trinity copy(MyMemory::TRINITY_MEMORY.read(address));
    Trinity *temp = new Trinity(otherValue);
    myCPU.ADD(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, copy.address, temp->address);
    delete temp;
    return copy;    
}

Trinity Trinity::operator-(long otherValue)
{
    Trinity copy(MyMemory::TRINITY_MEMORY.read(address));
    Trinity *temp = new Trinity(otherValue);
    myCPU.SUB(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, copy.address, temp->address);
    delete temp;
    return copy;    
}

Trinity Trinity::operator*(long otherValue)
{
    Trinity copy(MyMemory::TRINITY_MEMORY.read(address));
    Trinity *temp = new Trinity(otherValue);
    myCPU.MUL(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, copy.address, temp->address);
    delete temp;
    return copy;    
}

Trinity Trinity::operator/(long otherValue)
{
    Trinity copy(MyMemory::TRINITY_MEMORY.read(address));
    Trinity *temp = new Trinity(otherValue);
    myCPU.DIV(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, copy.address, temp->address);
    delete temp;
    return copy;    
}

Trinity Trinity::operator+(Trinity &other)
{
    Trinity copy(MyMemory::TRINITY_MEMORY.read(address));
    myCPU.ADD(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, copy.address, other.address);
    return copy;
}

Trinity Trinity::operator-(Trinity &other)
{
    Trinity copy(MyMemory::TRINITY_MEMORY.read(address));
    myCPU.SUB(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, copy.address, other.address);
    return copy;
}

Trinity Trinity::operator*(Trinity &other)
{
    Trinity copy(MyMemory::TRINITY_MEMORY.read(address));
    myCPU.MUL(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, copy.address, other.address);
    return copy;
}

Trinity Trinity::operator/(Trinity &other)
{
    Trinity copy(MyMemory::TRINITY_MEMORY.read(address));
    myCPU.DIV(myCPU.TRINITY_REGISTER, MyMemory::TRINITY_MEMORY, copy.address, other.address);
    return copy;
}

/*
    Functions
*/
std::ostream& operator<<(std::ostream &cout, Trinity &trinity)
{
    cout << MyMemory::TRINITY_MEMORY.read(trinity.address);
    return cout;
}
