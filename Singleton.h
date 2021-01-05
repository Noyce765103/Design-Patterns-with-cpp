#pragma once
#include<iostream>
using namespace std;
class Singleton
{
public:
	static const Singleton* getInstance();
	static void DoSomething() { cout << "do something" << endl; }
//将构造函数私有化，防止外部访问
private:
	Singleton();
	~Singleton();

	static Singleton* This; //使用静态变量来帮助解决资源的分配和释放
};

