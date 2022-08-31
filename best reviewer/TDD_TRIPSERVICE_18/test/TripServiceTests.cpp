// TripServiceTests.cpp : Defines the entry point for the console application.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include "../src/User.h"
#include "../src/TripService.h"
#include "../src/UserNotLoggedInException.h"
#include "UserSessionAccessor.h"
#include "MockUserSession.h"
#include "MockTripDAO.h"

using namespace testing;

//로그인한 사용자가 없을 때 exception
TEST(TripServiceTests, ShouldThrowExceptionWhenUserNotLoggedIn)
{
	User* notLoggedUser = nullptr;

	MockUserSession* mockUserSession = new MockUserSession();
	UserSessionAccessor::Set(mockUserSession);

	EXPECT_CALL(*mockUserSession, GetLoggedUser())
		.WillOnce(Return(notLoggedUser));

	TripService<MockTripsDAO> tripService;

	User user(1);

	EXPECT_THROW(tripService.GetTripsByUser(user), UserNotLoggedInException);

	UserSessionAccessor::DeleteSession();
	delete mockUserSession;
}

//유저에게 친구가 없을 때 빈 여행 정보 리턴
TEST(TripServiceTests, ShouldReturnNoTripsWhenUserHasNoFriend)
{
	MockUserSession* mockUserSession = new MockUserSession();
	UserSessionAccessor::Set(mockUserSession);

	User loggedUser(1);
	EXPECT_CALL(*mockUserSession, GetLoggedUser())
		.WillRepeatedly(Return(&loggedUser));

	TripService<MockTripsDAO> tripService;

	User user(2);
	auto trips = tripService.GetTripsByUser(user);

	ASSERT_EQ(0, trips.size());

	UserSessionAccessor::DeleteSession();
	delete mockUserSession;

}

//유저의 친구가 로그인한 사용자가 아닐 때 빈 여행정보 리턴
TEST(TripServiceTests, ShouldReturnNoTripsWhenLoggedUserIsNotFriend)
{
	User loggedUser(1);

	MockUserSession* mockUserSession = new MockUserSession();
	UserSessionAccessor::Set(mockUserSession);

	EXPECT_CALL(*mockUserSession, GetLoggedUser())
		.WillRepeatedly(Return(&loggedUser));

	TripService<MockTripsDAO> tripService;

	User user(2);
	user.AddFriend(User(3));
	auto trips = tripService.GetTripsByUser(user);

	ASSERT_EQ(0, trips.size());

	UserSessionAccessor::DeleteSession();
	delete mockUserSession;

}

//유저가 로그인한 친구가 있을 때 유저의 여행 정보 리턴
TEST(TripServiceTests, ShouldReturnTripsWhenUserHasLoggedFriend)
{
	User loggedUser(1);

	MockUserSession* mockUserSession = new MockUserSession();
	UserSessionAccessor::Set(mockUserSession);

	EXPECT_CALL(*mockUserSession, GetLoggedUser())
		.WillRepeatedly(Return(&loggedUser));

	TripService<MockTripsDAO> tripService;

	User user(2);
	user.AddFriend(loggedUser);
	user.AddTrip(Trip(1));
	user.AddTrip(Trip(2));

	EXPECT_THAT(tripService.GetTripsByUser(user), ContainerEq(user.Trips()));

	UserSessionAccessor::DeleteSession();
	delete mockUserSession;

}


int main(int argc, char** argv)
{
	InitGoogleMock(&argc, argv);

	return RUN_ALL_TESTS();
}
