
#include <iostream>
#include "Singleton.h"
#include "MagicSingleton.h"
#include "Observer.h"
#include "Observerable.h"
using namespace std;

class User1 :public Observer
{
	virtual void Update(void* pArg)
	{
		cout << "User1 Got News:" << (char*) pArg << endl;
	}
};

class User2 :public Observer
{
	virtual void Update(void* pArg)
	{
		cout << "User2 Got News:" << (char*) pArg << endl;
	}
};

class News : public Observerable
{
public:
	void GetSomeNews(string str)
	{
		SetChange("News:" + str);
	}
};

int main()
{	
	//Singleton::getInstance()->DoSomething();
	//MagicSingleton::getInstance().DoSomething();

	User1 u1;
	User2 u2;

	News n1;
	n1.GetSomeNews("T0");

	n1.Attach(&u1);
	n1.Attach(&u2);
	n1.GetSomeNews("T1");

	n1.detach(&u2);
	n1.GetSomeNews("T2");

	return 0;
}

