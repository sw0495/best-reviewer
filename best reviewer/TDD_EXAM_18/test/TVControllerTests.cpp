// TVControllerTests.cpp : Defines the entry point for the console application.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "MockTuner.h"
#include "../src/TVController.h"

using namespace testing;

//To-Do : 한자리 숫자 누르고 OK 누를때
TEST(TVControllerTests, press1digitAndPressOK)
{
	MockTuner tuner;
    TVController tv(&tuner);
    
    EXPECT_CALL(tuner, setCH("1")) 
        .Times(1);   

    tv.pushButton(remoteKey::KEY_1);
    tv.pushButton(remoteKey::KEY_OK);
}

//To-Do : 한자리 숫자 누르고 OK 누를때 (0, OK 눌렀을 때)
TEST(TVControllerTests, press1digit0AndPressOK)
{
    MockTuner tuner;
    TVController tv(&tuner);
    
    EXPECT_CALL(tuner, setCH("0 pushed")) 
        .Times(1);      

    tv.pushButton(remoteKey::KEY_0);
    tv.pushButton(remoteKey::KEY_OK);

}

//To-Do : 두자리 숫자 누를때
TEST(TVControllerTests, press2digits)
{
    MockTuner tuner;
    TVController tv(&tuner);
    
    EXPECT_CALL(tuner, setCH("12")) 
        .Times(1);        

    tv.pushButton(remoteKey::KEY_1);
    tv.pushButton(remoteKey::KEY_2);
}

//To-Do : 두자리 숫자 누를때 (0,0 눌렀을 때)
TEST(TVControllerTests, press2digits0)
{
    MockTuner tuner;
    TVController tv(&tuner);
    
    EXPECT_CALL(tuner, setCH("0 pushed")) 
        .Times(1);      

    tv.pushButton(remoteKey::KEY_0);
    tv.pushButton(remoteKey::KEY_0);
}

//To-Do : 이전채널 누를때 이전 채널 X
TEST(TVControllerTests, pressPrevButtonIsNotPrevCH)
{
    MockTuner tuner;
    TVController tv(&tuner);

    tv.pushButton(remoteKey::KEY_PREVIOUS);
}


//To-Do : 이전채널 누를때 이전 채널 O
TEST(TVControllerTests, pressPrevButtonIsPrevCH)
{
    MockTuner tuner;
    TVController tv(&tuner);

    EXPECT_CALL(tuner, setCH("12")) 
        .Times(1);  

    tv.setPrevCh(12);
    tv.pushButton(remoteKey::KEY_PREVIOUS);
}


//To-Do : 선호채널 누를때 - 선호 채널이 아닐 경우 추가, 선호 채널인 경우 삭제
TEST(TVControllerTests, pressFavoriteButtonAddCh)
{
    MockTuner tuner;
    TVController tv(&tuner);

    EXPECT_CALL(tuner, getCurrentCH())
        .WillRepeatedly(Return(1));  

    tv.addPreferChs(2);
    tv.pushButton(remoteKey::KEY_PREFER);

    EXPECT_TRUE(tv.checkPreferCh(1)); 
}

TEST(TVControllerTests, pressFavoriteButtonDelCh)
{
    MockTuner tuner;
    TVController tv(&tuner);

    EXPECT_CALL(tuner, getCurrentCH())
        .WillRepeatedly(Return(1));   

    tv.addPreferChs(1);
    tv.pushButton(remoteKey::KEY_PREFER);

    EXPECT_FALSE(tv.checkPreferCh(1));
}

//To-Do : 다음 선호 채널 누를때 - UP 방향으로 가까운 선호 채널, 끝인 경우 처음으로
TEST(TVControllerTests, pressNextFavoriteButton)
{
    MockTuner tuner;
    TVController tv(&tuner);

    EXPECT_CALL(tuner, setCH("1")) 
        .Times(1); 
    EXPECT_CALL(tuner, getCurrentCH())
        .WillOnce(Return(98));   

    tv.addPreferChs(1);
    tv.pushButton(remoteKey::KEY_NEXTPREFER);
}

//To-Do : 저장 채널이 없을 때 UP, 다음 번호
TEST(TVControllerTests, pressUpButtonWithoutSearchedChannelList)
{
    MockTuner tuner;
    TVController tv(&tuner);

    EXPECT_CALL(tuner, getCurrentCH())
        .WillOnce(Return(98));
    EXPECT_CALL(tuner, setCH("99")) 
        .Times(1); 

    tv.pushButton(remoteKey::KEY_UP);
}


//To-Do : 저장 채널이 없을 때 DOWN, 이전 번호
TEST(TVControllerTests, pressDownButtonWithoutSearchedChannelList)
{
    MockTuner tuner;
    TVController tv(&tuner);

    EXPECT_CALL(tuner, getCurrentCH())
        .WillOnce(Return(98));  
    EXPECT_CALL(tuner, setCH("97")) 
        .Times(1); 

    tv.pushButton(remoteKey::KEY_DOWN);

}

//To-Do : 채널 검색을 누를때 : 모든 채널을 검색하여 유효한 채널 저장
TEST(TVControllerTests, pressSearchChannelButton)
{
    MockTuner tuner;
    TVController tv(&tuner);

    EXPECT_CALL(tuner, seekCH())
        .WillRepeatedly(Return("98"));        

    tv.pushButton(remoteKey::KEY_SEARCH);

    EXPECT_TRUE(tv.checkSaveCh(98)); 
}

//To-Do : 저장 채널이 있을 때 UP, 가까운 저장 채널 
TEST(TVControllerTests, pressUpButtonWithSearchedChannelList)
{
    MockTuner tuner;
    TVController tv(&tuner);

    EXPECT_CALL(tuner, getCurrentCH())
        .WillOnce(Return(15));
    EXPECT_CALL(tuner, setCH("4")) 
        .Times(1); 

    tv.addSaveChs(4);
    tv.addSaveChs(6);
    tv.addSaveChs(14);
    tv.pushButton(remoteKey::KEY_UP);
}


//To-Do : 저장 채널이 있을 때 DOWN, 가까운 저장 채널
TEST(TVControllerTests, pressDownButtonWithSearchedChannelList)
{
    MockTuner tuner;
    TVController tv(&tuner);

    EXPECT_CALL(tuner, getCurrentCH())
        .WillOnce(Return(15));  
    EXPECT_CALL(tuner, setCH("14")) 
        .Times(1); 

    tv.addSaveChs(4);
    tv.addSaveChs(6);
    tv.addSaveChs(14);
    tv.pushButton(remoteKey::KEY_DOWN);
}

int main(int argc, char** argv)
{
	InitGoogleMock(&argc, argv);

	return RUN_ALL_TESTS();
}