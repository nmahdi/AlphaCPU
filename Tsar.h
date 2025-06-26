#ifndef TSAR_H
#define TSAR_H

#include <iostream>
#include "ThemeObject.h"
#include "CPU.h"

class Tsar : public ThemeObject
{
	friend std::ostream& operator<<(std::ostream &cout, Tsar &tsar);
    public:
    	Tsar() {}
    	Tsar(int otherValue)
    	{
    		this->address = MyMemory::TSAR_MEMORY.newAddress();
			myCPU.PUSH(MyMemory::TSAR_MEMORY, this->address, otherValue);	
		}
		Tsar(const Tsar &otherTsar)
		{
			this->address = MyMemory::TSAR_MEMORY.newAddress();
			myCPU.PUSH(MyMemory::TSAR_MEMORY, this->address, MyMemory::TSAR_MEMORY.read(otherTsar.address));
		}

        Tsar &operator=(int otherValue);
        Tsar &operator=(Tsar &other);
        
		bool operator==(int otherValue) const;
		bool operator!=(int otherValue) const;
		
        bool operator==(Tsar &other) const;
        bool operator!=(Tsar &other) const;
        
        bool operator<(int otherValue) const;
        bool operator<=(int otherValue) const;
        bool operator>(int otherValue) const;
        bool operator>=(int otherValue) const;
        
        bool operator<(Tsar &other) const;
        bool operator<=(Tsar &other) const;
        bool operator>(Tsar &other) const;
        bool operator>=(Tsar &other) const;
        
        Tsar &operator++();
        Tsar &operator--();
        
        Tsar &operator++(int);
        Tsar &operator--(int);
        
        Tsar &operator+=(int otherValue);
        Tsar &operator-=(int otherValue);
        Tsar &operator*=(int otherValue);
        Tsar &operator/=(int otherValue);
        
        Tsar &operator+=(Tsar &other);
        Tsar &operator-=(Tsar &other);
        Tsar &operator*=(Tsar &other);
        Tsar &operator/=(Tsar &other);
        
        Tsar operator+(int otherValue);
        Tsar operator-(int otherValue);
        Tsar operator*(int otherValue);
        Tsar operator/(int otherValue);
        
        Tsar operator+(Tsar &other);
        Tsar operator-(Tsar &other);
        Tsar operator*(Tsar &other);
        Tsar operator/(Tsar &other);
};

std::ostream& operator<<(std::ostream &cout, Tsar &tsar);


#endif 
