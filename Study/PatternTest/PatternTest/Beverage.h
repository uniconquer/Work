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
		m_szDescription = "����������";
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
		m_szDescription = "�Ͽ콺 ���� Ŀ��";
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
		m_szDescription = "��ũ�ν�Ʈ Ŀ��";
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
		m_szDescription = "��ī���� Ŀ��";
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

