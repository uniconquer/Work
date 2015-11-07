#pragma once
#include <string>
#include <map>
#include "Observer.h"

class CObserver;
class CSubject
{
public:
	CSubject(void);
	virtual ~CSubject(void);

	virtual void RegisterObserver( CObserver* pOb ) = 0;
	virtual void RemoveObserver( CObserver* pOb ) = 0;
	virtual void NotifyObserver() = 0;
};

class WeatherData : public CSubject
{
public:
	WeatherData();
	virtual ~WeatherData();

	void RegisterObserver( CObserver* pOb );
	void RemoveObserver( CObserver* pOb );
	void NotifyObserver();

	float GetTemperature() { return m_Temperature; }
	float GetHumidity() { return m_Humidity; }
	float GetPressure() { return m_Pressure; }

	void MeasurementsChanged();

	void SetMeasurements( float Temp, float Humidity, float Pressure );

private:
	typedef std::map< std::string, CObserver* > STL_MAP_OBSERVERS;
	STL_MAP_OBSERVERS	m_ObserverList;

	float m_Temperature;	// 온도
	float m_Humidity;		// 습도
	float m_Pressure;		// 압력
};