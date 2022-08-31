#include <gtest/gtest.h>

#include "../src/GildedRose.h"

TEST(GildedRoseTest, testAgedBrieOver50) {
    vector<shared_ptr<Item>> items;
    items.push_back(Item::create("Aged Brie", 10, 50));
    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ("Aged Brie", app.items[0]->name);
    EXPECT_EQ(9, app.items[0]->sellIn);
    EXPECT_EQ(50, app.items[0]->quality);


    // vector<Item> items;
    // items.push_back(Item("Aged Brie", 10, 50));
    // GildedRose app(items);
    // app.updateQuality();
    // EXPECT_EQ("Aged Brie", app.items[0].name);
    // EXPECT_EQ(9, app.items[0].sellIn);
    // EXPECT_EQ(50, app.items[0].quality);
}

TEST(GildedRoseTest, testAgedBrieOverDay) {
    vector<shared_ptr<Item>> items;
    items.push_back(Item::create("Aged Brie", 0, 48));
    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(50, app.items[0]->quality);
}

TEST(GildedRoseTest, testAgedBrieInDay) {
    vector<shared_ptr<Item>> items;
    items.push_back(Item::create("Aged Brie", 10, 49));
    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(50, app.items[0]->quality);
}

TEST(GildedRoseTest, testIncreaseBackStagePassQualityWithin11days) { 
    vector<shared_ptr<Item>> items;
    items.push_back(Item::create("Backstage passes to a TAFKAL80ETC concert", 11, 44));
    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(45, app.items[0]->quality);
}

TEST(GildedRoseTest, testIncreaseBackStagePassQualityWithin10days) { 
    vector<shared_ptr<Item>> items;
    items.push_back(Item::create("Backstage passes to a TAFKAL80ETC concert", 10, 44));
    GildedRose app(items);
    app.updateQuality(); 
    
    EXPECT_EQ(46, app.items[0]->quality);
}

TEST(GildedRoseTest, testIncreaseBackStagePassQualityWithin5days) { 
    vector<shared_ptr<Item>> items;
    items.push_back(Item::create("Backstage passes to a TAFKAL80ETC concert", 5, 44));
    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(47, app.items[0]->quality);
}

TEST(GildedRoseTest, testIncreaseBackStagePassQualityOverConcertDay) {
    vector<shared_ptr<Item>> items;
    items.push_back(Item::create("Backstage passes to a TAFKAL80ETC concert", 0, 44));
    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(0, app.items[0]->quality);
}

TEST(GildedRoseTest, testIncreaseBackStagePassQualityOver50) { 
    vector<shared_ptr<Item>> items;
    items.push_back(Item::create("Backstage passes to a TAFKAL80ETC concert", 11, 50));
    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(50, app.items[0]->quality);
}

TEST(GildedRoseTest, testSulfurasQualityWithInDay) {
    vector<shared_ptr<Item>> items;
    items.push_back(Item::create("Sulfuras, Hand of Ragnaros", 1, 80));
    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(80, app.items[0]->quality);
}

TEST(GildedRoseTest, testSulfurasQualityOverDay) {
    vector<shared_ptr<Item>> items;
    items.push_back(Item::create("Sulfuras, Hand of Ragnaros", 0, 80));
    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(80, app.items[0]->quality);
}

class GildedRoseTestFixture : public ::testing::Test {
    protected:
     void SetUp()override {
        items.push_back(Item::create("Sulfuras, Hand of Ragnaros", 0, 80));
        app = new GildedRose(items);
        app->updateQuality();
     }

     void TearDown() override {
        delete app;
     }

    vector<shared_ptr<Item>> items;
    GildedRose* app;
};

TEST_F(GildedRoseTestFixture, testSulfurasQuality) {
    EXPECT_EQ(80, app->items[0]->quality);
}

class BackStagePassTest : public testing::TestWithParam<std::tuple<int, std::string, int, int>> { 

};

TEST_P(BackStagePassTest, parameterizedTestNotIncreaseBackStagePassQualityAbove50) {
    vector<shared_ptr<Item>> items;
    int expected = std::get<0>(GetParam());
    std::string name = std::get<1>(GetParam());
    int sellin = std::get<2>(GetParam());
    int quality = std::get<3>(GetParam());

    items.push_back(Item::create(name, sellin, quality));
    GildedRose app(items);
    app.updateQuality();   

    EXPECT_EQ(expected, app.items[0]->quality);
}

INSTANTIATE_TEST_SUITE_P(
    GildedRoseTest,
    BackStagePassTest,
    testing::Values(
        std::make_tuple(50, "Backstage passes to a TAFKAL80ETC concert", 5, 48),
        std::make_tuple(50, "Backstage passes to a TAFKAL80ETC concert", 10, 49),
        std::make_tuple(50, "Backstage passes to a TAFKAL80ETC concert", 11, 50)
    )
);
