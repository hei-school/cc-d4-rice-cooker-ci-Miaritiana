#include "gtest/gtest.h"
#include "rice_cooker.hpp"

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

    EXPECT_EQ(riceCooker.getContent(), content);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}