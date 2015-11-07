#pragma once
#include <iostream>

class CFlyBehavior
{
public:
	CFlyBehavior(void);
	virtual ~CFlyBehavior(void);

	virtual void Fly() = 0;
};

class CFlyWithWings : public CFlyBehavior
{
public:
	CFlyWithWings();
	virtual ~CFlyWithWings();
	void Fly() { std::cout<< "����." <<std::endl; }
};

class CFlyNoWay : public CFlyBehavior
{
public:
	CFlyNoWay();
	virtual ~CFlyNoWay();
	void Fly() { std::cout<< "�� ����." <<std::endl; }
};