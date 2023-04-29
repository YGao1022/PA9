#pragma once
#include <iostream>
#include "derivedClass.hpp"
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