

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "iostream"
#include "MockTurtle.h"
#include "Painter.h"



using testing::AtLeast; 
using testing::Return; 
using testing::_; 
using testing::Gt; 
using testing::Eq; 
using testing::Lt;
using testing::InSequence;
using testing::NiceMock;
using testing::StrictMock;
using testing::DefaultValue;
using testing::DoAll;
using testing::Invoke;
using testing::InvokeArgument;
using testing::Expectation;

//default
TEST(PainterTest, DrawsLineTest)
{
    MockTurtle turtle;

    EXPECT_CALL(turtle, PenDown()); 
    EXPECT_CALL(turtle, Forward(100));  
    EXPECT_CALL(turtle, PenUp());

    Painter painter(&turtle);
    painter.DrawLine(100);
}

//Times
TEST(PainterTest, DrawSquareTest) 
{ 
    MockTurtle turtle; 

    EXPECT_CALL(turtle, Forward(Gt(0))) 
        .Times(4); 
 
    EXPECT_CALL(turtle, Turn(90))
        .Times(4); 

    EXPECT_CALL(turtle, PenUp()); 
    EXPECT_CALL(turtle, PenDown());
 
    Painter painter(&turtle);
    painter.DrawSquare(10);
    painter.DrawSquare(0);  
} 

//uninteresting : NiceMock
TEST(PainterTest, test1) {

    //StrictMock<MockTurtle> turtle; 
    NiceMock<MockTurtle> turtle; 
    //MockTurtle turtle; 

    EXPECT_CALL(turtle, PenDown()) 
        .Times(AtLeast(1));

    Painter painter(&turtle); 
    EXPECT_TRUE(painter.DrawLine(10)); 
} 

//DefaultValue
TEST(PainterTest, test2) {

    DefaultValue<int>::Set(-1);

    NiceMock<MockTurtle> turtle; 

    EXPECT_CALL(turtle, GetX()); 

    Painter painter(&turtle); 
    EXPECT_EQ(-1, painter.fuc1()); 
} 

//ON_CALL.WillByDefault
TEST(PainterTest, test3) {

    NiceMock<MockTurtle> turtle; 

    ON_CALL(turtle, GetX())
        .WillByDefault(Return(-1));   

    EXPECT_CALL(turtle, GetX()); 

    Painter painter(&turtle); 

    EXPECT_EQ(-1, painter.fuc1()); 
} 

//WillRepeatedly
TEST(PainterTest, test4) {

    NiceMock<MockTurtle> turtle; 

    int n = 100;
    EXPECT_CALL(turtle, GetX())
        .Times(4)
        .WillRepeatedly(Return(n++));

    Painter painter(&turtle); 

    EXPECT_EQ(100, painter.fuc1()); 
    EXPECT_EQ(100, painter.fuc1()); 
    EXPECT_EQ(100, painter.fuc1()); 
    EXPECT_EQ(100, painter.fuc1()); 
} 

//Invoke
TEST(PainterTest, test5) {

    NiceMock<MockTurtle> turtle; 

    EXPECT_CALL(turtle, GetX())
        .Times(4)
        .WillRepeatedly(Invoke(GetXX));

    Painter painter(&turtle); 

    EXPECT_EQ(100, painter.fuc1()); 
    EXPECT_EQ(101, painter.fuc1()); 
    EXPECT_EQ(102, painter.fuc1()); 
    EXPECT_EQ(103, painter.fuc1()); 
} 

//.WillOnce
TEST(PainterTest, test6) {

    NiceMock<MockTurtle> turtle; 

    EXPECT_CALL(turtle, GetX())
        .WillOnce(Invoke(GetXX))
        .WillOnce(Invoke(GetYY))
        .WillOnce(DoAll(Invoke(GetXX), Invoke(GetYY))); 
        

    Painter painter(&turtle); 

    EXPECT_EQ(104, painter.fuc1()); 
    EXPECT_EQ(200, painter.fuc1()); 
    EXPECT_EQ(200, painter.fuc1()); 
} 

//MyMethod
TEST(PainterTest, test7)
{
    NiceMock<MockTurtle> turtle;

    // EXPECT_CALL(turtle, MyMethod(100))
    //     .WillRepeatedly(Return(false));
    EXPECT_CALL(turtle, MyMethod(_))
        .WillRepeatedly(Return(false));
    
    Painter painter(&turtle);
    EXPECT_FALSE(painter.fuc2());
    //EXPECT_TRUE(painter.fuc2());
    
}

//.With(Lt());
TEST(PainterTest, test8)
{
    NiceMock<MockTurtle> turtle;

    EXPECT_CALL(turtle, GoTo(_, _))
    .With(Lt());
    
    Painter painter(&turtle);
    painter.fuc3();

}

//.After
TEST(PainterTest, test9)
{
    MockTurtle turtle;

    Expectation PenDown = EXPECT_CALL(turtle, PenDown());
    Expectation Forward = EXPECT_CALL(turtle, Forward(100)); 
    EXPECT_CALL(turtle, PenUp())
        .After(PenDown, Forward);

    Painter painter(&turtle);
    painter.DrawLine(100);
}

//InSequence seq;
TEST(PainterTest, test10)
{
    MockTurtle turtle;

    InSequence seq;

    EXPECT_CALL(turtle, PenDown());
    EXPECT_CALL(turtle, Forward(100)); 
    EXPECT_CALL(turtle, PenUp());

    Painter painter(&turtle);
    painter.DrawLine(100);
}

//.RetiresOnSaturation();
TEST(PainterTest, test11)
{
    MockTurtle turtle;

    EXPECT_CALL(turtle, GetX()).WillOnce(Return(0));
    //EXPECT_CALL(turtle, GetX()).Times(1).WillOnce(Return(1));

    EXPECT_CALL(turtle, GetX())
        .Times(1)
        .WillOnce(Return(1))
        .RetiresOnSaturation();

    Painter painter(&turtle);
    painter.fuc4();
}

//matcher
TEST(PainterTest, test12)
{

    using testing::ElementsAre; 
    using testing::UnorderedElementsAre; 
 
    std::vector<std::string> result;
    result = {"John", "Jane", "Some"};

    EXPECT_EQ(3, result.size());
    EXPECT_EQ("John", result[0]);
    EXPECT_EQ("Jane", result[1]);
    EXPECT_EQ("Some", result[2]);

    ASSERT_THAT(result, ElementsAre("John", "Jane", "Some"));

    ASSERT_THAT(result, UnorderedElementsAre("Jane", "John",  "Some"));

}