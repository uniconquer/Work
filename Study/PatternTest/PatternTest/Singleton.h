#pragma once
#include <iostream>
#include <string>

using namespace std;

#include <assert.h>

template <typename T> class Singleton
{
	static T* ms_pManager;

public:
	Singleton()
	{
		assert( !ms_pManager );
		int offset = (int)(T*)1 - (int)(Singleton<T>*)(T*)1;
		ms_pManager = (T*)((int)this + offset);
	}

	virtual ~Singleton()
	{
		assert( ms_pManager );
		ms_pManager = NULL;
	}

	static T& GetManager()
	{
		return ( *ms_pManager );
	}

	static T*GetManagerPtr()
	{
		return (ms_pManager);
	}
};

template <typename T>T* Singleton<T>::ms_pManager = 0;


class LogManager : public Singleton< LogManager >
{
public:
	void    Show( void ) { cout<<"저는 세상에서 하나뿐인 객체에요~"<<endl; }
};

inline LogManager* GetLogManager( void ) { return LogManager::GetManagerPtr(); }