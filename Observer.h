#pragma once
class Observer
{
public:
	Observer(){}
	virtual ~Observer(){}

	//�����۲�������仯ʱ��֪ͨ���۲��ߵ����������
	virtual void Update(void* pArg) = 0;
};

