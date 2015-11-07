#pragma once
#include <iostream>

typedef void (*DelegateFunc)();
typedef void (*DelegateIntFunc)();

struct Delegate
{
	void (*FuncToCall)();
	Delegate( DelegateFunc Infunc = NULL ):FuncToCall( Infunc ){}
	virtual void operator()(){ if(FuncToCall)(*FuncToCall)();}
};

struct DelegateInt
{
	void (*FuncToCall)(int);
	DelegateInt( DelegateIntFunc Infunc = NULL ):FuncToCall( /*Infunc*/ ){}
	virtual void operator()( int p ){ if(FuncToCall)(*FuncToCall)(p);}
};


struct Menu
{
	Delegate Callback;
};

void DoOpen( void ){ std::cout << "DoOpen" << std::endl; }
void DoClose( void ){ std::cout << "DoClose" << std::endl; }