#include "Fatman.h"

/*
    Assignment overloads
*/
Fatman& Fatman::operator=(double otherValue)
{
    this->address = MyMemory::FATMAN_MEMORY.newAddress();
    myCPU.PUSH(MyMemory::FATMAN_MEMORY, this->address, otherValue);
    return *this;
}

Fatman& Fatman::operator=(Fatman &other)
{
    this->address = MyMemory::FATMAN_MEMORY.newAddress();
    myCPU.PUSH(MyMemory::FATMAN_MEMORY, this->address, MyMemory::FATMAN_MEMORY.read(other.address));
    return *this;
}

/*
    Comparison overloads
*/
bool Fatman::operator==(double otherValue) const
{
    Fatman *temp = new Fatman(otherValue);
    myCPU.CMP(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, temp->address);
    delete temp;
    return myCPU.FATMAN_REGISTER.getFlag() == 0;
}

bool Fatman::operator!=(double otherValue) const
{
    Fatman *temp = new Fatman(otherValue);
    myCPU.CMP(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, temp->address);
    delete temp;
    return myCPU.FATMAN_REGISTER.getFlag() != 0;
}

bool Fatman::operator==(Fatman &other) const
{
    myCPU.CMP(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, other.address);
    return myCPU.FATMAN_REGISTER.getFlag() == 0;
}

bool Fatman::operator!=(Fatman &other) const
{
    myCPU.CMP(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, other.address);
    return myCPU.FATMAN_REGISTER.getFlag() != 0;
}

bool Fatman::operator<(double otherValue) const 
{
    Fatman *temp = new Fatman(otherValue);
    myCPU.CMP(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, temp->address);
    delete temp;
    return myCPU.FATMAN_REGISTER.getFlag() < 0;
}

bool Fatman::operator<=(double otherValue) const 
{
    Fatman *temp = new Fatman(otherValue);
    myCPU.CMP(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, temp->address);
    delete temp;
    return myCPU.FATMAN_REGISTER.getFlag() <= 0;
}

bool Fatman::operator>(double otherValue) const 
{
    Fatman *temp = new Fatman(otherValue);
    myCPU.CMP(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, temp->address);
    delete temp;
    return myCPU.FATMAN_REGISTER.getFlag() > 0;
}

bool Fatman::operator>=(double otherValue) const 
{
    Fatman *temp = new Fatman(otherValue);
    myCPU.CMP(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, temp->address);
    delete temp;
    return myCPU.FATMAN_REGISTER.getFlag() >= 0;
}

bool Fatman::operator<(Fatman &other) const 
{
    myCPU.CMP(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, other.address);
    return myCPU.FATMAN_REGISTER.getFlag() < 0;
}

bool Fatman::operator<=(Fatman &other) const 
{
    myCPU.CMP(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, other.address);
    return myCPU.FATMAN_REGISTER.getFlag() <= 0;
}

bool Fatman::operator>(Fatman &other) const 
{
    myCPU.CMP(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, other.address);
    return myCPU.FATMAN_REGISTER.getFlag() > 0;
}

bool Fatman::operator>=(Fatman &other) const 
{
    myCPU.CMP(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, other.address);
    return myCPU.FATMAN_REGISTER.getFlag() >= 0;
}

/*
    Modification overloads
*/
Fatman& Fatman::operator++()
{
    Fatman *temp = new Fatman(1.0);
    myCPU.ADD(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, temp->address);
    delete temp;
    return *this;
}

Fatman& Fatman::operator++(int)
{
    Fatman *temp = new Fatman(1.0);
    myCPU.ADD(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, temp->address);
    delete temp;
    return *this;
}

Fatman& Fatman::operator--()
{
    Fatman *temp = new Fatman(1.0);
    myCPU.SUB(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, temp->address);
    delete temp;
    return *this;
} 

Fatman& Fatman::operator--(int)
{
    Fatman *temp = new Fatman(1.0);
    myCPU.SUB(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, temp->address);
    delete temp;
    return *this;
}

Fatman& Fatman::operator+=(double otherValue)
{
    Fatman *temp = new Fatman(otherValue);
    myCPU.ADD(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, temp->address);
    delete temp;
    return *this;
}

Fatman& Fatman::operator-=(double otherValue)
{
    Fatman *temp = new Fatman(otherValue);
    myCPU.SUB(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, temp->address);
    delete temp;
    return *this;
}

Fatman& Fatman::operator*=(double otherValue)
{
    Fatman *temp = new Fatman(otherValue);
    myCPU.MUL(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, temp->address);
    delete temp;
    return *this;
}

Fatman& Fatman::operator/=(double otherValue)
{
    Fatman *temp = new Fatman(otherValue);
    myCPU.DIV(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, temp->address);
    delete temp;
    return *this;
}

Fatman& Fatman::operator+=(Fatman &other)
{
    myCPU.ADD(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, other.address);
    return *this;
}

Fatman& Fatman::operator-=(Fatman &other)
{
    myCPU.SUB(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, other.address);
    return *this;
}

Fatman& Fatman::operator*=(Fatman &other)
{
    myCPU.MUL(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, other.address);
    return *this;
}

Fatman& Fatman::operator/=(Fatman &other)
{
    myCPU.DIV(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, address, other.address);
    return *this;
}

/*
    Operation overloads
*/
Fatman Fatman::operator+(double otherValue)
{
    Fatman copy(MyMemory::FATMAN_MEMORY.read(address));
    Fatman *temp = new Fatman(otherValue);
    myCPU.ADD(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, copy.address, temp->address);
    delete temp;
    return copy;    
}

Fatman Fatman::operator-(double otherValue)
{
    Fatman copy(MyMemory::FATMAN_MEMORY.read(address));
    Fatman *temp = new Fatman(otherValue);
    myCPU.SUB(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, copy.address, temp->address);
    delete temp;
    return copy;    
}

Fatman Fatman::operator*(double otherValue)
{
    Fatman copy(MyMemory::FATMAN_MEMORY.read(address));
    Fatman *temp = new Fatman(otherValue);
    myCPU.MUL(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, copy.address, temp->address);
    delete temp;
    return copy;    
}

Fatman Fatman::operator/(double otherValue)
{
    Fatman copy(MyMemory::FATMAN_MEMORY.read(address));
    Fatman *temp = new Fatman(otherValue);
    myCPU.DIV(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, copy.address, temp->address);
    delete temp;
    return copy;    
}

Fatman Fatman::operator+(Fatman &other)
{
    Fatman copy(MyMemory::FATMAN_MEMORY.read(address));
    myCPU.ADD(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, copy.address, other.address);
    return copy;
}

Fatman Fatman::operator-(Fatman &other)
{
    Fatman copy(MyMemory::FATMAN_MEMORY.read(address));
    myCPU.SUB(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, copy.address, other.address);
    return copy;
}

Fatman Fatman::operator*(Fatman &other)
{
    Fatman copy(MyMemory::FATMAN_MEMORY.read(address));
    myCPU.MUL(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, copy.address, other.address);
    return copy;
}

Fatman Fatman::operator/(Fatman &other)
{
    Fatman copy(MyMemory::FATMAN_MEMORY.read(address));
    myCPU.DIV(myCPU.FATMAN_REGISTER, MyMemory::FATMAN_MEMORY, copy.address, other.address);
    return copy;
}

/*
    Functions
*/
std::ostream& operator<<(std::ostream &cout, Fatman &fatman)
{
    cout << MyMemory::FATMAN_MEMORY.read(fatman.address);
    return cout;
}
