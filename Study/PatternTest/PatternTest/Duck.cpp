#include "Duck.h"


Duck::Duck(void)
{
	m_DuckName = "¿À¸® Á¶»ó´Ô";
}


Duck::~Duck(void)
{
}

void Duck::SetFlyBehavior(CFlyBehavior* Fb)
{
	m_FlyBehavior = Fb;
}

void Duck::SetQuackBehavior(CQuackBehavior* Qb)
{
	m_QuackBehavior = Qb;
}

MallardDuck::MallardDuck()
{
	m_FlyBehavior = new CFlyWithWings;
	m_QuackBehavior = new CQuack;
	m_DuckName = "MallardDuck";
}

MallardDuck::~MallardDuck()
{
	delete m_FlyBehavior;
	delete m_QuackBehavior;
}

RubberDuck::RubberDuck(void)
{
	m_FlyBehavior = new CFlyWithWings;
	m_QuackBehavior = new CQuack;
	m_DuckName  = "RubberDuck";
}

RubberDuck::~RubberDuck(void)
{
	delete m_FlyBehavior;
	delete m_QuackBehavior;
}