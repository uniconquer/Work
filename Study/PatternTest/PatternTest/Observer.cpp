#include "Observer.h"


CObserver::CObserver(void)
{
}


CObserver::~CObserver(void)
{
}

CConditionDisplay::CConditionDisplay( CSubject* pSubject )
{
	pSubject->RegisterObserver( this );
	m_pSubject = pSubject;
}

CConditionDisplay::~CConditionDisplay()
{

}

void CConditionDisplay::Update( float Temp, float Humidity, float Pressure )
{
	m_Temperature = Temp;
	m_Humidity = Humidity;
	m_Pressure = Pressure;
}

void CConditionDisplay::Display()
{
	cout<<" �µ� : "<< m_Temperature <<endl;
	cout<<" ���� : "<< m_Humidity <<endl;
	cout<<" �з� : "<< m_Pressure <<endl;
	cout<<endl;
}
