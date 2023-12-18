#include "gtest/gtest.h"
#include "rice_cooker.hpp"
#include <string>

using namespace std;

TEST(RiceCookerTest, SetCapacity)
{
    RiceCooker riceCooker;
    riceCooker.setCapacity(5.0);

    EXPECT_EQ(riceCooker.getCapacity(), 5.0);
}

TEST(RiceCookerTest, SetContent)
{
    RiceCooker riceCooker;
    Content content;

    riceCooker.setCapacity(4.0);
    content.setName("Vegetable");
    content.setQuantity(2.0);
    riceCooker.setContent(content);

    EXPECT_EQ(content.getName(), "Vegetable");
    EXPECT_EQ(content.getQuantity(), 2.0);
    EXPECT_EQ(riceCooker.getContent(), content);
}

TEST(RiceCookerTest, SetTimer)
{
    RiceCooker riceCooker;
    riceCooker.setTimer(30);

    EXPECT_EQ(riceCooker.getTimer(), 30);
}

TEST(RiceCookerTest, SetTemperature)
{
    RiceCooker riceCooker;
    riceCooker.setTemperature("Hight");

    EXPECT_EQ(riceCooker.getTemperature(), "Hight");
}

TEST(RiceCookerTest, SetCookingduration)
{
    RiceCooker riceCooker;
    riceCooker.setCookingDuration(20);

    EXPECT_EQ(riceCooker.getCookingDuration(), 20);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}