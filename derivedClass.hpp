#pragma once
#pragma once
#include <iostream>
#include "baseClass.hpp"
class Dog : public Mammal
{
public:
	Dog(void);
	~Dog(void);
	void Move() const;
	void Speak() const;
protected:
	int itsAge;
};