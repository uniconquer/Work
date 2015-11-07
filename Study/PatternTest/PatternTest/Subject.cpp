#include "Subject.h"


CSubject::CSubject(void)
{
}


CSubject::~CSubject(void)
{
}

WeatherData::WeatherData()
{
}


WeatherData::~WeatherData()
{

}


void WeatherData::RegisterObserver( CObserver* pOb )
{
	// <- 같은 방법 Test해보자
	m_ObserverList.insert( STL_MAP_OBSERVERS::value_type( pOb->m_szName, pOb ) );
	//m_ObserverList[pOb->m_szName] = pOb;
	//m_ObserverList.insert( pair<std::string,CObserver*>( pOb->m_szName, pOb ) );
	// ->
}

void WeatherData::RemoveObserver( CObserver* pOb )
{
	m_ObserverList.erase( pOb->m_szName );
}

void WeatherData::NotifyObserver()
{
	STL_MAP_OBSERVERS::iterator It = m_ObserverList.begin();

	while ( It != m_ObserverList.end() )
	{
		CObserver* pObserver = It->second;
		pObserver->Update( m_Temperature, m_Humidity, m_Pressure );
		++It;
	}

}

void WeatherData::MeasurementsChanged()
{
	NotifyObserver();
}

void WeatherData::SetMeasurements( float Temp, float Humidity, float Pressure )
{
	m_Temperature = Temp;
	m_Humidity = Humidity;
	m_Pressure = Pressure;

	MeasurementsChanged();
}
