
#include <iostream>
#include "Singleton.h"
#include "MagicSingleton.h"
using namespace std;

int main()
{	
	Singleton::getInstance()->DoSomething();
	MagicSingleton::getInstance().DoSomething();
	return 0;
}

