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

	//ע��۲���
	void Attach(Observer* pOb);
	//��ע��۲���
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

