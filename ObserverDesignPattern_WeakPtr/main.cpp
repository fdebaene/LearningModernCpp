#include "Observable.h"
#include "Observer.h"
#include <iostream>
int main(int argc, char** argv)
{
	Observable observable;
	using ObserverSPtr = std::shared_ptr<Observer>;
	std::vector<ObserverSPtr> nephew{ std::make_shared<Observer>("riri") ,std::make_shared<Observer>("fifi") ,std::make_shared<Observer>("loulou") };

	for (auto i = 0; i < nephew.size(); i++)
	{
		std::cout << "adding " << nephew[i]->name()<<" as observer." << std::endl;
		observable.addObserver(nephew[i]);
	}
	std::cout << "notifying 1" << std::endl;
	observable.notifyToObserver();
	nephew.erase(nephew.begin());
	std::cout << "notifying 2" << std::endl;
	observable.notifyToObserver();
	
	std::cin.get();
	return 0;
}