#include "MyClass.h"
#include <string>
#include <unordered_map>
struct MyClass::Impl
{
	int m_0;
	std::string m_2;
	std::unordered_map<std::string, std::string> m_3;
};

MyClass::MyClass():m_impl(std::make_unique<Impl>())
{

}


MyClass::~MyClass() = default;//set the default implementation
MyClass::MyClass(MyClass&&) = default;
MyClass& MyClass::operator = (MyClass&&)=default;
MyClass::MyClass(const MyClass& rhs):m_impl(std::make_unique<Impl>(*rhs.m_impl))//using the generated Impl constructor
{}
MyClass& MyClass::operator = (const MyClass& rhs)
{
	*m_impl = *rhs.m_impl;
	return *this;
}

