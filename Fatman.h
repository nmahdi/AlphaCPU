#ifndef FATMAN_H
#define FATMAN_H

#include <iostream>
#include "ThemeObject.h"
#include "CPU.h"

class Fatman : public ThemeObject
{
	friend std::ostream& operator<<(std::ostream &cout, Fatman &fatman);
public:
	Fatman() {}
	Fatman(double otherValue)
	{
		this->address = MyMemory::FATMAN_MEMORY.newAddress();
		myCPU.PUSH(MyMemory::FATMAN_MEMORY, this->address, otherValue);
	}
	Fatman(const Fatman &otherFatman)
	{
		this->address = MyMemory::FATMAN_MEMORY.newAddress();
		myCPU.PUSH(MyMemory::FATMAN_MEMORY, this->address, MyMemory::FATMAN_MEMORY.read(otherFatman.address));
	}

	Fatman &operator=(double otherValue);
	Fatman &operator=(Fatman &other);

	bool operator==(double otherValue) const;
	bool operator!=(double otherValue) const;

	bool operator==(Fatman &other) const;
	bool operator!=(Fatman &other) const;

	bool operator<(double otherValue) const;
	bool operator<=(double otherValue) const;
	bool operator>(double otherValue) const;
	bool operator>=(double otherValue) const;

	bool operator<(Fatman &other) const;
	bool operator<=(Fatman &other) const;
	bool operator>(Fatman &other) const;
	bool operator>=(Fatman &other) const;

	Fatman &operator++();
	Fatman &operator--();

	Fatman &operator++(int);
	Fatman &operator--(int);

	Fatman &operator+=(double otherValue);
	Fatman &operator-=(double otherValue);
	Fatman &operator*=(double otherValue);
	Fatman &operator/=(double otherValue);

	Fatman &operator+=(Fatman &other);
	Fatman &operator-=(Fatman &other);
	Fatman &operator*=(Fatman &other);
	Fatman &operator/=(Fatman &other);

	Fatman operator+(double otherValue);
	Fatman operator-(double otherValue);
	Fatman operator*(double otherValue);
	Fatman operator/(double otherValue);

	Fatman operator+(Fatman &other);
	Fatman operator-(Fatman &other);
	Fatman operator*(Fatman &other);
	Fatman operator/(Fatman &other);
};

std::ostream& operator<<(std::ostream &cout, Fatman &fatman);

#endif
