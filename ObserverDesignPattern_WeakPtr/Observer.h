#pragma once
#include <string>
class Observer
{
public:
	Observer(const std::string& name);
	virtual ~Observer();
	void notify();
	std::string name();
private:
	std::string		m_name;

};

