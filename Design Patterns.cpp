
#include <iostream>
#include "Singleton.h"
#include "MagicSingleton.h"
#include "Observer.h"
#include "Observerable.h"
using namespace std;

#define ADAPTER

//------------------------------------观察者模式------------------------------------------------------------------------------------
#ifdef OBSERVER
class User1 :public Observer
{
	virtual void Update(void* pArg)
	{
		cout << "User1 Got News:" << reinterpret_cast<char*>(pArg) << endl;
	}
};

class User2 :public Observer
{
	virtual void Update(void* pArg)
	{
		cout << "User2 Got News:" << reinterpret_cast<char*>(pArg) << endl;
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
#endif // OBSERVER
//---------------------------------------------------------------------------------------------------------------------------------

#ifdef ADAPTER

class LegacyRectangle
{
public:
	LegacyRectangle(double x1, double y1, double x2, double y2)
	{
		_x1 = x1;
		_y1 = y1;
		_x2 = x2;
		_y2 = y2;
		
		
	}
	void LegacyDraw()
	{
		cout << "LegacyRectangle::LegacyDraw()" << endl;
	}

private:
	double _x1;
	double _y1;
	double _x2;
	double _y2;
};

class Rectangle
{
public:
	virtual void Draw(string str) = 0;
};

//第一种适配的方式：使用多重继承
class RectangleAdapter : public Rectangle, public LegacyRectangle
{
public:
	RectangleAdapter(double x, double y, double w, double h) :LegacyRectangle(x, y, x + w, y + h)
	{
		cout << "RectangleAdapter(int x, int y, int w, int h)" << endl;
	}
	virtual void Draw(string str)
	{
		cout << "RectangleAdapter::Draw()" << endl;
		LegacyDraw();
	}

};

//组合方式的Adapter
class RectangleAdapter2 :public Rectangle
{
public:
	RectangleAdapter2(double x, double y, double w, double h) :_IRect(x, y, x + w, y + h)
	{
		cout << "RectangleAdapter(int x, int y, int w, int h)" << endl;
	}
	virtual void Draw(string str)
	{
		cout << "RectangleAdapter::Draw()" << endl;
		_IRect.LegacyDraw();
	}
private:
	LegacyRectangle _IRect;
};

#endif // ADAPTER

int main()
{	
	//Singleton::getInstance()->DoSomething();
	//MagicSingleton::getInstance().DoSomething();
#ifdef OBSERVER
#endif // OBSERVER

#ifdef ADAPTER
	double x = 20.0, y = 50.0, w = 300.0, h = 200.0;
	RectangleAdapter ra(x, y, w, h);
	Rectangle* pR = &ra;
	pR->Draw("Testing Adapter");
	cout << endl;
	RectangleAdapter2 rb(x, y, w, h);
	Rectangle* pR2 = &rb;
	pR2->Draw("Testing Adapter");

#endif // ADAPTER


	return 0;
}

