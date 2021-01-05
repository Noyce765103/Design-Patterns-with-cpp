#include "Singleton.h"


Singleton* Singleton::This = nullptr;
Singleton::Singleton()
{

}

const Singleton* Singleton::getInstance()
{
	if (!This)
	{
		This = new Singleton();
	}
	return This;
}

Singleton::~Singleton()
{

}