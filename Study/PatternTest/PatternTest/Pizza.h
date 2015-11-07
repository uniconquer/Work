#pragma once
#include <iostream>
#include <string>


enum PIZZA_TYPE
{
	PIZZA_TYPE_NONE = 0,
	PIZZA_TYPE_CHEESE,
	PIZZA_TYPE_PEPPERONI,
};

class CPizza
{
public:
	CPizza(){}
	virtual ~CPizza(){}
	void Bake();
	void Cut();
	void Box();
	void ShowName(){ std::cout<< m_szName <<std::endl; }
protected:
	std::string m_szName;
};

class CMrPizzaStyleCheese : public CPizza
{
public:
	CMrPizzaStyleCheese(){ m_szName = "�̽������� : ġ��"; }
};

class CMrPizzaStylePepperoni : public CPizza
{
public:
	CMrPizzaStylePepperoni(){ m_szName = "�̽������� : ����δ�"; }
};

class CDominosPizzaStyleCheese : public CPizza
{
public:
	CDominosPizzaStyleCheese(){ m_szName = "���̳����� : ġ��"; }
};

class CDominosPizzaStylePepperoni : public CPizza
{
public:
	CDominosPizzaStylePepperoni(){ m_szName = "���̳����� : ����δ�"; }
};

class CPizzaStore
{
public:
	virtual CPizza* CreatePizza( PIZZA_TYPE ) = 0;
	CPizza* OrderPizza( PIZZA_TYPE eType )
	{
		CPizza* pOrderPizza = CreatePizza( eType );
		pOrderPizza->Bake();
		pOrderPizza->Cut();
		pOrderPizza->Box();
		return pOrderPizza;
	}
};

class CMrPizzaStore : public CPizzaStore
{
	virtual CPizza* CreatePizza( PIZZA_TYPE eType )
	{
		switch( eType )
		{
		case PIZZA_TYPE_CHEESE:
			{
				return new CMrPizzaStyleCheese;
			}			
			break;
		case PIZZA_TYPE_PEPPERONI:
			{
				return new CMrPizzaStylePepperoni;
			}			
			break;
		default:
			return NULL;
			break;
		}
	}
};

class CDominosPizzaStore : public CPizzaStore
{
	virtual CPizza* CreatePizza( PIZZA_TYPE eType )
	{
		switch( eType )
		{
		case PIZZA_TYPE_CHEESE:
			{
				return new CDominosPizzaStyleCheese;
			}			
			break;
		case PIZZA_TYPE_PEPPERONI:
			{
				return new CDominosPizzaStylePepperoni;
			}			
			break;
		default:
			return NULL;
			break;
		}
	}
};
