extern "C"
{
#include "LightDriver.h"
#include "MemMappedLightDriver.h"
}

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

static void null(LightDriver self) { self = self ;}

LightDriverInterfaceStruct doNothing =
{
       null, null, null
};

LightDriverStruct testDriver =
{
        &doNothing,
        "testDriver",
        13
};

TEST(LightDriver, NullDriverDoesNoHarm)
{
    LightDriver_TurnOn(NULL);
    LightDriver_TurnOff(NULL);
    LightDriver_Destroy(NULL);
}


TEST(LightDriver, Accessors)
{
    ASSERT_EQ(13, LightDriver_GetId(&testDriver));
    ASSERT_STREQ("testDriver", LightDriver_GetType(&testDriver));
}


TEST(LightDriver, MemMappedLight)
{
    LightDriver memdriver = MemMappedLightDriver_Create(10, 0);
    LightDriver_TurnOn(memdriver);
    ASSERT_EQ(10, LightDriver_GetId(memdriver));
    ASSERT_STREQ("Memory mapped", LightDriver_GetType(memdriver));
}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
