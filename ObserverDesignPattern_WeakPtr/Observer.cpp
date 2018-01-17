#include "Observer.h"
#include <iostream>


Observer::Observer(const std::string& name):m_name(name)
{
}
Observer::~Observer() = default;
void Observer::notify()
{
	std::cout << m_name << " has been notified"<<std::endl;
}
std::string Observer::name()
{
	return m_name;
}