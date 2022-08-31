#include <string>
#include <vector>

using namespace std;

#include <memory>

class Item
{
public:
    string name;
    int sellIn;
    int quality;

    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) {};

    static shared_ptr<Item> create(string name, int sellIn, int quality);

    virtual void calculateQuality() = 0; 
};

class GildedRose
{
public:
    vector<shared_ptr<Item>> & items;
    GildedRose(vector<shared_ptr<Item>> & items);
   
    void updateQuality();
};

class AgedBrie : public Item
{
public:    
    AgedBrie(string name, int sellIn, int quality) : Item(name, sellIn, quality) {};
    void calculateQuality() override;
};

class BackStagePassesToATAFKAL80ETCConcert : public Item
{
public:      
    BackStagePassesToATAFKAL80ETCConcert(string name, int sellIn, int quality) : Item(name, sellIn, quality) {};
    void calculateQuality() override;
};

class SulfurasHandOfRagnaros : public Item
{
public:      
    SulfurasHandOfRagnaros(string name, int sellIn, int quality) : Item(name, sellIn, quality) {};
    void calculateQuality() override;
};

class Others : public Item
{
public:      
    Others(string name, int sellIn, int quality) : Item(name, sellIn, quality) {};
    void calculateQuality() override;
};



