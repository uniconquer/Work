#pragma once
#include <iostream>
#include "FlyBehavior.h"
#include "QuackBehavior.h"
#include <string>
class CFlyBehavior;
class CQuackBehavior;
class Duck
{
public:
	Duck(void);
	virtual ~Duck(void);

	virtual void Swim() {std::cout<< std::string("수영") <<std::endl;}
	virtual void Display() {std::cout<< m_DuckName <<std::endl;}

	void PerformFly() {m_FlyBehavior->Fly();}
	void PerformQuack() {m_QuackBehavior->Quack();}
	
	void SetFlyBehavior(CFlyBehavior* Fb);
	void SetQuackBehavior(CQuackBehavior* Qb);
protected:
	std::string		m_DuckName;
	CFlyBehavior*	m_FlyBehavior;
	CQuackBehavior* m_QuackBehavior;
};

class MallardDuck : public Duck
{
public:
	MallardDuck();
	virtual ~MallardDuck();

	virtual void Swim() {std::cout<< "수영" <<std::endl;}
	virtual void Display() {std::cout<< m_DuckName <<std::endl;}
};

class RubberDuck : public Duck
{
public:
	RubberDuck();
	virtual ~RubberDuck();

	virtual void Swim() {std::cout << "수영" << std::endl;}
	virtual void Display() {std::cout << m_DuckName << std::endl;}
};
