#include <iostream>
#include "EventObserver.h"

void xd(int a) {
	std::cout << "Xd !" << std::endl;
}

class To {
public:
	void hi(int a) { std::cout << "Hi !" << std::endl; }
	void hi2(int a) { std::cout << "Hi2 !" << std::endl; }
};

int main() {
	To x;
	EventObserver<int> on_load;
	
	on_load.addSubscriber(&x, &To::hi);	// class
	on_load.addSubscriber(&x, &To::hi2);// class
	on_load.addSubscriber(&xd);			// global

	on_load.removeSubscriber(&x);		// remove all from "class To" for "object x"

	on_load.notify(5);

	std::cout << std::endl;
	std::cin.ignore();
	return 0;
}

