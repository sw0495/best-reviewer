#pragma once

#include "../src/UserSession.h"
#include <gmock/gmock.h>


class MockUserSession : public UserSession
{
public:
    // MockUserSession(){};
    // ~MockUserSession(){};

    MOCK_METHOD(bool, IsUserLoggedIn, (User), (override));
    MOCK_METHOD(User*, GetLoggedUser, (), (override));

};