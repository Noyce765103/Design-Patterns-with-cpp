#pragma once
class Observer
{
public:
	Observer(){}
	virtual ~Observer(){}

	//当被观察对象发生变化时，通知被观察者调用这个方法
	virtual void Update(void* pArg) = 0;
};

