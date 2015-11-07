#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "Subject.h"

class CSubject;
class CObserver
{
public:
	CObserver(void);
	virtual ~CObserver(void);

	virtual void Update( float Temp, float Humidity, float Pressure ) = 0;

public:
	std::string m_szName;
};

class CConditionDisplay : public CObserver
{
public:
	CConditionDisplay( CSubject* pSubject );
	virtual ~CConditionDisplay();

	virtual void Update( float Temp, float Humidity, float Pressure );
	void Display();
private:
	CSubject* m_pSubject;

	float m_Temperature;	// 온도
	float m_Humidity;		// 습도
	float m_Pressure;		// 압력
};

