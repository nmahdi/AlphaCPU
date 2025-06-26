#ifndef TRINITY_H
#define TRINITY_H

#include <iostream>
#include "ThemeObject.h"
#include "CPU.h"

class Trinity : public ThemeObject
{
	friend std::ostream& operator<<(std::ostream &cout, Trinity &trinity);
public:
	Trinity() {}
	Trinity(long otherValue)
	{
		this->address = MyMemory::TRINITY_MEMORY.newAddress();
		myCPU.PUSH(MyMemory::TRINITY_MEMORY, this->address, otherValue);
	}
	Trinity(const Trinity &otherTrinity)
	{
		this->address = MyMemory::TRINITY_MEMORY.newAddress();
		myCPU.PUSH(MyMemory::TRINITY_MEMORY, this->address, MyMemory::TRINITY_MEMORY.read(otherTrinity.address));
	}

	Trinity &operator=(long otherValue);
	Trinity &operator=(Trinity &other);

	bool operator==(long otherValue) const;
	bool operator!=(long otherValue) const;

	bool operator==(Trinity &other) const;
	bool operator!=(Trinity &other) const;

	bool operator<(long otherValue) const;
	bool operator<=(long otherValue) const;
	bool operator>(long otherValue) const;
	bool operator>=(long otherValue) const;

	bool operator<(Trinity &other) const;
	bool operator<=(Trinity &other) const;
	bool operator>(Trinity &other) const;
	bool operator>=(Trinity &other) const;

	Trinity &operator++();
	Trinity &operator--();

	Trinity &operator++(int);
	Trinity &operator--(int);

	Trinity &operator+=(long otherValue);
	Trinity &operator-=(long otherValue);
	Trinity &operator*=(long otherValue);
	Trinity &operator/=(long otherValue);

	Trinity &operator+=(Trinity &other);
	Trinity &operator-=(Trinity &other);
	Trinity &operator*=(Trinity &other);
	Trinity &operator/=(Trinity &other);

	Trinity operator+(long otherValue);
	Trinity operator-(long otherValue);
	Trinity operator*(long otherValue);
	Trinity operator/(long otherValue);

	Trinity operator+(Trinity &other);
	Trinity operator-(Trinity &other);
	Trinity operator*(Trinity &other);
	Trinity operator/(Trinity &other);
};

std::ostream& operator<<(std::ostream &cout, Trinity &trinity);

#endif
