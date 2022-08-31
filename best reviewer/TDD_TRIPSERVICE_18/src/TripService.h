#pragma once
#include "Trip.h"
#include <list>
#include "UserNotLoggedInException.h"
#include "UserSession.h"
#include "TripDAO.h"
#include "iostream"
using namespace std;

/*
기이한 이름
중복 코드
긴 함수
긴 매개변수 목록
전역 데이터
가변 데이터
뒤엉킨 변경
산탄총 수술
기능 편애
데이터 뭉치
기본형 집착
반복되는 switch 문
반복문
*/

class User;


template<class T>
class TripService
{
private:

public:
	static std::list<Trip> GetTripsByUser(User user);

};

template<class T>
std::list<Trip> TripService<T>::GetTripsByUser(User user)
{
	std::list<Trip> triplist;
    user.setLoggedUser(UserSession::GetInstance()->GetLoggedUser());
	if (!user.getLoggedUser()) {
		throw UserNotLoggedInException();
	}
	
	if (user.findFriend()) {
		triplist = T::FindTripsByUser(user);
	}

	return triplist;
}