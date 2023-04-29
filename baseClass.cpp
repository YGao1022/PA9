#include "derivedClass.hpp"
Dog::Dog(void) :itsAge(1)
{
	cout << "Dog constructor..." << endl;
}
Dog::~Dog(void)
{
	cout << "Dog destructor..." << endl;
}
void Dog::Move() const
{
	cout << "Dog moves a step!" << endl;
}
void Dog::Speak() const
{
	cout << "What does a Dog speak? Dogilian!" << endl;
}




