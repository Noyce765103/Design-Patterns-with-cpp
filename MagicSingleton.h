#pragma once
#include<iostream>
using namespace std;
class MagicSingleton
{
public:
	static MagicSingleton& getInstance();
	void DoSomething() { cout << "do something" << endl; }
	
private:
	MagicSingleton();
	~MagicSingleton()
	{
		cout << "destructor called" << endl;
	}
};

