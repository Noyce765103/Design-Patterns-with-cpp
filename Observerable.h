#pragma once
#include<list>
#include<string>
using namespace std;
class Observer;

class Observerable
{
public:
	Observerable();
	virtual ~Observerable();

	//注册观察者
	void Attach(Observer* pOb);
	//反注册观察者
	void detach(Observer* pOb);

	virtual void GetSomeNews(string str)
	{
		SetChange(str);
	}
protected:
	void SetChange(string nes);

private:
	void Notify(void* pArg);
	bool bChange = false;
	std::list<Observer*> _Obs;
};

