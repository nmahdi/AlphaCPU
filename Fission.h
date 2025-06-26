#ifndef FISSION_H
#define FISSION_H

#include <iostream>
#include "ThemeObject.h"
#include "CPU.h"

class Fission : public ThemeObject
{
	friend std::ostream& operator<<(std::ostream &cout, Fission &fission);
public:
	Fission() {}
	Fission(char otherValue)
	{
		this->address = MyMemory::FISSION_MEMORY.newAddress();
		myCPU.PUSH(MyMemory::FISSION_MEMORY, this->address, otherValue);	
	}
	Fission(const Fission &otherFission)
	{
		this->address = MyMemory::FISSION_MEMORY.newAddress();
		myCPU.PUSH(MyMemory::FISSION_MEMORY, this->address, MyMemory::FISSION_MEMORY.read(otherFission.address));
	}

	Fission &operator=(char otherValue);
	Fission &operator=(Fission &other);

	bool operator==(char otherValue) const;
	bool operator!=(char otherValue) const;

	bool operator==(Fission &other) const;
	bool operator!=(Fission &other) const;
	
	bool operator<(char otherValue) const;
	bool operator<=(char otherValue) const;
	bool operator>(char otherValue) const;
	bool operator>=(char otherValue) const;
	
	bool operator<(Fission &other) const;
	bool operator<=(Fission &other) const;
	bool operator>(Fission &other) const;
	bool operator>=(Fission &other) const;


	Fission &operator++();
	Fission &operator--();

	Fission &operator++(int);
	Fission &operator--(int);

	Fission &operator+=(char otherValue);
	Fission &operator-=(char otherValue);
	Fission &operator*=(char otherValue);
	Fission &operator/=(char otherValue);

	Fission &operator+=(Fission &other);
	Fission &operator-=(Fission &other);
	Fission &operator*=(Fission &other);
	Fission &operator/=(Fission &other);

	Fission operator+(char otherValue);
	Fission operator-(char otherValue);
	Fission operator*(char otherValue);
	Fission operator/(char otherValue);

	Fission operator+(Fission &other);
	Fission operator-(Fission &other);
	Fission operator*(Fission &other);
	Fission operator/(Fission &other);
};

std::ostream& operator<<(std::ostream &cout, Fission &fission);

#endif
