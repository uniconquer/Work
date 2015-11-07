#pragma once
#include <iostream>

using namespace std;

class CQuackBehavior
{
public:
	CQuackBehavior(void);
	virtual ~CQuackBehavior(void);

	virtual void Quack() = 0;
};

class CQuack : public CQuackBehavior
{
public:
	CQuack();
	virtual ~CQuack();
	void Quack() {std::cout<< "Ва" <<std::endl;}
};