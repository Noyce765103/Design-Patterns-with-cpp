#include "Observerable.h"
#include "Observer.h"

Observerable::Observerable()
{

}

Observerable::~Observerable()
{

}


void Observerable::Attach(Observer* pOb)
{
	if (!pOb)	return;
	auto it = _Obs.begin();
	for (; it != _Obs.end(); it++)
	{
		if (*it == pOb)
		{
			return;
		}
	}
	_Obs.push_back(pOb);
}

void Observerable::detach(Observer* pOb)
{
	if (!pOb || _Obs.empty())
		return;
	_Obs.remove(pOb);
}

void Observerable::SetChange(string news)
{
	bChange = true;
	Notify((void*)news.c_str());
}


void Observerable::Notify(void* pArg)
{
	if (!bChange)	return;
	auto it = _Obs.begin();
	for (; it != _Obs.end(); it++)
	{
		(*it)->Update(pArg);
	}
	bChange = false;
	
}