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
	cout<<" 온도 : "<< m_Temperature <<endl;
	cout<<" 습도 : "<< m_Humidity <<endl;
	cout<<" 압력 : "<< m_Pressure <<endl;
	cout<<endl;
}
