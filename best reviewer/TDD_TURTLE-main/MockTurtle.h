#ifndef MOCKTURTLE_H_
#define MOCKTURTLE_H_

#include "gmock/gmock.h" // Brings in Google Mock.
#include "Turtle.h"

class MockTurtle: public Turtle {

public:
 MOCK_METHOD(void, PenUp, (), (override));
 MOCK_METHOD(void, PenDown, (), (override));
 MOCK_METHOD(void, Forward, (int), (override));
 MOCK_METHOD(void, Turn, (int), (override));
 MOCK_METHOD(void, GoTo, (int, int), (override));
 MOCK_METHOD(int, GetX, (), (const, override));
 MOCK_METHOD(int, GetY, (), (const, override));

 MOCK_METHOD(bool, MyMethod, (int), (override));
 
};

#endif /* MOCKTURTLE_H_ */
