#include "Observable.h"
#include "Observer.h"
Observable::Observable() = default;
Observable::~Observable() = default;

void Observable::notifyToObserver()
{
	auto it = m_obs.begin();
	while (it != m_obs.end())
	{
		auto shared = (*it).lock();
		if (shared)//test if the shared ptr is null
		{
			shared->notify();
			it++;
		}
		else
		{
			it = m_obs.erase(it);
			
		}
	}
}
void Observable::addObserver(ObserverWPtr obs)
{
	m_obs.push_back(obs);
}
