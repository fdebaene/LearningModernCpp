#pragma once
#include <memory>
#include <vector>
class Observer;
class Observable
{
public:
	using ObserverWPtr = std::weak_ptr<Observer>;
	Observable();
	~Observable();
	void notifyToObserver();
	void addObserver(ObserverWPtr obs);

private:
	std::vector<ObserverWPtr>	m_obs;
};

