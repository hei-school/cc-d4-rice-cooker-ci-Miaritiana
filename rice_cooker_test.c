#include "rice_cooker.h"
#include "gtest/gtest.h"

TEST(ContentTest, GetName) {
  struct Content c;
  setName(&c, "Rice");
  EXPECT_STREQ("Rice", getName(&c));
}

TEST(ContentTest, GetQuantity) {
  struct Content c;
  setQuantity(&c, 2.5);
  EXPECT_DOUBLE_EQ(2.5, getQuantity(&c));
}

TEST(RiceCookerTest, SetAndGetCapacity) {
  struct RiceCooker rc;
  setCapacity(&rc, 5.0);
  EXPECT_DOUBLE_EQ(5.0, getCapacity(&rc));
}

TEST(RiceCookerTest, SetAndGetContent) {
  struct RiceCooker rc;
  struct Content contents;
  setName(&contents, "Rice");
  setCapacity(&rc, 4.0);
  setQuantity(&contents, 2.0);
  setContent(&rc, contents);

  struct Content retrievedContent = getContent(&rc);
  EXPECT_STREQ("Rice", getName(&retrievedContent));
  EXPECT_DOUBLE_EQ(2.0, getQuantity(&retrievedContent));
}

TEST(RiceCookerTest, SetAndGetTimer) {
  struct RiceCooker rc;
  setTimer(&rc, 30);

  EXPECT_EQ(getTimer(&rc), 30);
}

TEST(RiceCookerTest, SetAndGetCookingDuration) {
  struct RiceCooker rc;
  setCookingDuration(&rc, 30);

  EXPECT_EQ(getCookingDuration(&rc), 30);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
