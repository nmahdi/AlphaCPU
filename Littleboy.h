#ifndef LITTLEBOY_H
#define LITTLEBOY_H

#include <iostream>
#include "ThemeObject.h"
#include "CPU.h"

class LittleBoy : public ThemeObject
{
	friend std::ostream& operator<<(std::ostream &cout, LittleBoy &littleboy);
    public:
    	LittleBoy() {}
    	LittleBoy(float otherValue)
    	{
    		this->address = MyMemory::LITTLEBOY_MEMORY.newAddress();
			myCPU.PUSH(MyMemory::LITTLEBOY_MEMORY, this->address, otherValue);	
		}
		LittleBoy(const LittleBoy &otherLittleboy)
		{
			this->address = MyMemory::LITTLEBOY_MEMORY.newAddress();
			myCPU.PUSH(MyMemory::LITTLEBOY_MEMORY, this->address, MyMemory::LITTLEBOY_MEMORY.read(otherLittleboy.address));
		}

        LittleBoy &operator=(float otherValue);
        LittleBoy &operator=(LittleBoy &other);
        
		bool operator==(float otherValue) const;
		bool operator!=(float otherValue) const;
		
        bool operator==(LittleBoy &other) const;
        bool operator!=(LittleBoy &other) const;
        
        bool operator<(float otherValue) const;
        bool operator<=(float otherValue) const;
        bool operator>(float otherValue) const;
        bool operator>=(float otherValue) const;
        
        bool operator<(LittleBoy &other) const;
        bool operator<=(LittleBoy &other) const;
        bool operator>(LittleBoy &other) const;
        bool operator>=(LittleBoy &other) const;
        
        LittleBoy &operator++();
        LittleBoy &operator--();
        
        LittleBoy &operator++(int);
        LittleBoy &operator--(int);
        
        LittleBoy &operator+=(float otherValue);
        LittleBoy &operator-=(float otherValue);
        LittleBoy &operator*=(float otherValue);
        LittleBoy &operator/=(float otherValue);
        
        LittleBoy &operator+=(LittleBoy &other);
        LittleBoy &operator-=(LittleBoy &other);
        LittleBoy &operator*=(LittleBoy &other);
        LittleBoy &operator/=(LittleBoy &other);
        
        LittleBoy operator+(float otherValue);
        LittleBoy operator-(float otherValue);
        LittleBoy operator*(float otherValue);
        LittleBoy operator/(float otherValue);
        
        LittleBoy operator+(LittleBoy &other);
        LittleBoy operator-(LittleBoy &other);
        LittleBoy operator*(LittleBoy &other);
        LittleBoy operator/(LittleBoy &other);
};

std::ostream& operator<<(std::ostream &cout, LittleBoy &littleboy);

#endif
