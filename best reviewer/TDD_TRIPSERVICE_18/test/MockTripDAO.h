#pragma once
#include "../src/Trip.h"
#include <list>
#include "../src/User.h"


class MockTripsDAO
{
public:
	static std::list<Trip> FindTripsByUser(User user)
	{
		return user.Trips();
	}
};
