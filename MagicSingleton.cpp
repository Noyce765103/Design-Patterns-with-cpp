#include "MagicSingleton.h"

MagicSingleton& MagicSingleton::getInstance()
{
	static MagicSingleton singleton;
	return singleton;

}

MagicSingleton::MagicSingleton()
{
	std::cout << "constructor called" << std::endl;
}