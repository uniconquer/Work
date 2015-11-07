#pragma once
#include "Beverage.h"

class CondimentDecorator : public Beverage
{
	virtual std::string GetDescription(){ return m_szDescription; }
};

class Mocha : public CondimentDecorator
{
public:
	Mocha(Beverage* pBeverage)
	{
		m_pBeverage = pBeverage;
	}

	virtual std::string GetDescription()
	{
		return m_pBeverage->GetDescription() + ", 모카";
	}
	virtual double Cost(){ return m_pBeverage->Cost() + 0.2; }
	
private:
	Beverage* m_pBeverage;
};

class Soy : public CondimentDecorator
{
public:
	Soy(Beverage* pBeverage)
	{
		m_pBeverage = pBeverage;
	}

	virtual std::string GetDescription()
	{
		return m_pBeverage->GetDescription() + ", 두유";
	}
	virtual double Cost(){ return m_pBeverage->Cost() + 0.15; }

private:
	Beverage* m_pBeverage;
};

class Whip : public CondimentDecorator
{
public:
	Whip(Beverage* pBeverage)
	{
		m_pBeverage = pBeverage;
	}

	virtual std::string GetDescription()
	{
		return m_pBeverage->GetDescription() + ", 휘핑크림";
	}
	virtual double Cost(){ return m_pBeverage->Cost() + 0.1; }

private:
	Beverage* m_pBeverage;
};

class SteamMilk : public CondimentDecorator
{
public:
	SteamMilk(Beverage* pBeverage)
	{
		m_pBeverage = pBeverage;
	}

	virtual std::string GetDescription()
	{
		return m_pBeverage->GetDescription() + ", 스팀 밀크";
	}
	virtual double Cost(){ return m_pBeverage->Cost() + 0.1; }

private:
	Beverage* m_pBeverage;
};