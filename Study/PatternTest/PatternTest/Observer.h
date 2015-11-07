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

	float m_Temperature;	// �µ�
	float m_Humidity;		// ����
	float m_Pressure;		// �з�
};

