#pragma once
#include "../src/UserSession.h"

class UserSessionAccessor
{
public:
	static void Set(UserSession* other)
	{
		// Execute singleton at least once
		UserSession::GetInstance();
		delete UserSession::instance;
		UserSession::instance = other;
	}

	static void DeleteSession()
	{
		UserSession::instance = nullptr;        
	}
};
