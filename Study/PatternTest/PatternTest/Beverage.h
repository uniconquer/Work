#pragma once
#include <string>

class Beverage
{
public:
	Beverage(void);
	virtual ~Beverage(void);
	
	virtual double Cost() = 0;

	virtual std::string GetDescription() = 0;
	
protected:
	std::string m_szDescription;
};



class Espresso : public Beverage
{
public:
	Espresso()
	{
		m_szDescription = "에스프레소";
	}
	virtual std::string GetDescription()
	{
		return m_szDescription;
	}
	virtual double Cost()
	{
		return 1.99;
	}
};

class HouseBlend : public Beverage
{
public:
	HouseBlend()
	{
		m_szDescription = "하우스 블렌드 커피";
	}

	virtual std::string GetDescription()
	{
		return m_szDescription;
	}

	virtual double Cost()
	{
		return 0.89;
	}
};

class DarkLost : public Beverage
{
public:
	DarkLost()
	{
		m_szDescription = "다크로스트 커피";
	}

	virtual std::string GetDescription()
	{
		return m_szDescription;
	}

	virtual double Cost()
	{
		return 0.99;
	}
};

class DeCaffein : public Beverage
{
public:
	DeCaffein()
	{
		m_szDescription = "디카페인 커피";
	}

	virtual std::string GetDescription()
	{
		return m_szDescription;
	}

	virtual double Cost()
	{
		return 1.05;
	}
};

