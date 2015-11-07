#pragma once
#include <iostream>

typedef void (*DelegateFunc)();
typedef void (*DelegateIntFunc)();

struct Delegate
{
	void (*FuncToCall)();
	
	Delegate(DelegateFunc Infunc = nullptr)
		: FuncToCall(Infunc)
	{}
	
	virtual void operator()()
	{
		if(FuncToCall)
			(*FuncToCall)();
	}
};

struct DelegateInt
{
	void (*FuncToCall)(int);
	DelegateInt(DelegateIntFunc Infunc = nullptr)
		: FuncToCall(0)
	{}

	virtual void operator()(int p)
	{
		if(FuncToCall)
			(*FuncToCall)(p);
	}
};


class Menu
{
public:
	Menu();
	virtual ~Menu();
	Delegate Callback;
};

Menu::Menu()
{}
Menu::~Menu()
{}

void DoOpen(void){std::cout << "DoOpen" << std::endl;}
void DoClose(void){std::cout << "DoClose" << std::endl;}