#include "Common.h"
#include <iostream>
#include <string>
#include <memory>

void Strategy();
void Observer();
void Delegation();
void DecoratorPattern();
void FactoryMethod();
void SingletonPattern();

int main()
{
	int num = 0;
	while (1)
	{
		printf("1. 함수포인터위임 2. 스트레티지 3. 옵저버 4. 데코레이터 5. 팩토리메소드 6. 싱글톤 \n");
		printf("골라잡아 : ");
		scanf_s("%d", &num);

		switch (num)
		{
		case 1:
			Delegation();
			break;
		case 2:
			Strategy();
			break;
		case 3:
			Observer();
			break;
		case 4:
			DecoratorPattern();
			break;
		case 5:
			FactoryMethod();
			break;
		case 6:
			SingletonPattern();
			break;
		default:
			exit(0);
			break;
		}
	}
	return 0;
}

void Delegation()
{
	Menu menu;
	menu.Callback = Delegate(DoOpen);
	menu.Callback();
	menu.Callback = Delegate(DoClose);
	menu.Callback();
}

void Strategy()
{
	Duck* pDuck = new MallardDuck;

	pDuck->Display();
	pDuck->PerformFly();
	pDuck->PerformQuack();
	pDuck->SetFlyBehavior(new CFlyNoWay);
	pDuck->PerformFly();

	delete pDuck;
}
// push 방식, pool방식이 더 옳은것으로 간주된다. 겟터와 셋터를 사용.
void Observer()
{
	WeatherData* pWeatherData = new WeatherData;
	CConditionDisplay* pConditionDisplay = new CConditionDisplay(pWeatherData);

	pWeatherData->SetMeasurements(10.5f, 20.5f, 30.5f);
	pConditionDisplay->Display();
	
	delete pWeatherData;
	delete pConditionDisplay;

}

void ShowCost( std::string szDesc, double fCost )
{
	std::cout<< szDesc <<":$"<<fCost<<std::endl;
}

void DecoratorPattern()
{
	Beverage* pBeverage = new Espresso;
	ShowCost(pBeverage->GetDescription(), pBeverage->Cost());

	Beverage* pBeverage2 = new HouseBlend;
	pBeverage2 = new Mocha(pBeverage2);
	ShowCost(pBeverage2->GetDescription(), pBeverage2->Cost());

	Beverage* pBeverage3 = new DarkLost;
	pBeverage3 = new Whip(pBeverage3);
	pBeverage3 = new SteamMilk(pBeverage3);
	ShowCost(pBeverage3->GetDescription(), pBeverage3->Cost());

	
}

void FactoryMethod()
{
	shared_ptr<CPizzaStore> pMrStore(new CMrPizzaStore); // 참조카운터를 사용하는 스마트 포인터 아닌놈은 unique_ptr<>
	CPizza* pMrPizza = pMrStore->OrderPizza(PIZZA_TYPE_CHEESE);
	pMrPizza->ShowName();
	

	CPizzaStore* pDominosStore = new CDominosPizzaStore;
	CPizza* pDominosPizza = pDominosStore->OrderPizza(PIZZA_TYPE_CHEESE);
	pDominosPizza->ShowName();
}

void SingletonPattern()
{
	new LogManager;

	GetLogManager()->Show();

	delete GetLogManager();
};
