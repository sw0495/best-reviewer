#ifndef MOCKTUNER_H_
#define MOCKTUNER_H_

#include "gmock/gmock.h" // Brings in Google Mock.
#include "../src/Tuner.h"

#include <iostream>

class MockTuner : public Tuner{
public:
	//마지막으로 설정된 채널의 값을 반환한다.
	MOCK_METHOD(int, getCurrentCH, (), (override));

	//입력된 문자열에 해당되는 채널로 현재 채널값을 변경한다.
	//입력된 채널 문자열의 형식이 맞지 않을 경우, std::invalid_argument exception을 발생시킨다.
    MOCK_METHOD(void, setCH, (std::string), (override));

	//현재 설정된 채널로부터 유효한 채널을 검색하여 채널 번호 문자열을 반환한다.
	//현재 설정된 채널값으로부터 번호가 증가하는 방향으로 검색한다.
	//하나의 유효한 채널값을 번호 문자열로 반환한다.
    MOCK_METHOD(std::string, seekCH, (), (override));
};

#endif