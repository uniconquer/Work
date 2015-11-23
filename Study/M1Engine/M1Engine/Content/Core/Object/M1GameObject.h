#pragma once
ref class M1GameObject sealed
{
public:
	M1GameObject();
};


template<typename T>
T* M1GameObject::InsertComponent()
{
	UINT ComonentID = M1RTTI::GetTypeID<T>();
	if ( m_Components.find( ComonentID ) != m_Components.end() )
	{
		return nullptr;
	}

	T* pComponent = new T();
	m_Components.insert( std::make_pair( ComonentID, pComponent ) );
	pComponent->SetOwner( this );
	return pComponent;
}

template<typename T>
T* M1GameObject::InsertComponent( LPCWSTR FileName )
{
	UINT ComonentID = M1RTTI::GetTypeID<T>();
	if ( m_Components.find( ComonentID ) != m_Components.end() )
	{
		return nullptr;
	}

	T* pComponent = new T( FileName );
	m_Components.insert( std::make_pair( ComonentID, pComponent ) );
	pComponent->SetOwner( this );
	return pComponent;
}

template<typename T>
T* M1GameObject::GetComponent()
{
	auto FindIter = m_Components.find( M1RTTI::GetTypeID<T>() );
	if ( FindIter != m_Components.end() )
	{
		return static_cast<T*>( FindIter->second );
	}
	return nullptr;
}