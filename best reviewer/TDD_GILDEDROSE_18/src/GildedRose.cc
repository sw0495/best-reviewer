#include "GildedRose.h"

GildedRose::GildedRose(vector<shared_ptr<Item>> & items) : items(items)
{}
    
void GildedRose::updateQuality() 
{
    for (int i = 0; i < items.size(); i++)
    {
        items[i]->calculateQuality();

        // if (items[i].name == "Aged Brie")
        // {
        //     if (items[i].quality < 50)
        //     {
        //         items[i].quality = items[i].quality + 1;
        //     }

        //     items[i].sellIn = items[i].sellIn - 1;
        //     if (items[i].sellIn < 0)
        //     {
        //         if (items[i].quality < 50)
        //         {
        //             items[i].quality = items[i].quality + 1;
        //         }
        //     }
        // }
        // else if (items[i].name == "Backstage passes to a TAFKAL80ETC concert")
        // {
        //     if (items[i].quality < 50)
        //     {
        //         items[i].quality = items[i].quality + 1;

        //         if (items[i].sellIn < 11)
        //         {
        //             if (items[i].quality < 50)
        //             {
        //                 items[i].quality = items[i].quality + 1;
        //             }
        //         }

        //         if (items[i].sellIn < 6)
        //         {
        //             if (items[i].quality < 50)
        //             {
        //                 items[i].quality = items[i].quality + 1;
        //             }
        //         }
                
        //     }

        //     items[i].sellIn = items[i].sellIn - 1;

        //     if (items[i].sellIn < 0)
        //     {
        //         items[i].quality = items[i].quality - items[i].quality;
        //     }
        // }
        // else if(items[i].name == "Sulfuras, Hand of Ragnaros")
        // {

        // }
        // else
        // {
        //     if (items[i].quality > 0)
        //     {
        //         items[i].quality = items[i].quality - 1;
        //     }

        //     items[i].sellIn = items[i].sellIn - 1;
        //     if (items[i].sellIn < 0)
        //     {
        //         if (items[i].quality > 0)
        //         {
        //             items[i].quality = items[i].quality - 1;
        //         }
        //     }
        // }

    }
}



shared_ptr<Item> Item::create(string name, int sellIn, int quality) {
    if(name == "Aged Brie") {
        return make_shared<AgedBrie>(name, sellIn, quality);
    }
    else if(name == "Backstage passes to a TAFKAL80ETC concert") {
        return make_shared<BackStagePassesToATAFKAL80ETCConcert>(name, sellIn, quality);
    }
    else if(name == "Sulfuras, Hand of Ragnaros") {
        return make_shared<SulfurasHandOfRagnaros>(name, sellIn, quality);
    }
    else {
        return make_shared<Others>(name, sellIn, quality);
    }
}


void AgedBrie::calculateQuality() {
    if (quality < 50)
    {
        quality = quality + 1;
    }

    sellIn = sellIn - 1;
    if (sellIn < 0)
    {
        if (quality < 50)
        {
            quality = quality + 1;
        }
    }
}

void BackStagePassesToATAFKAL80ETCConcert::calculateQuality() {
        if (quality < 50)
        {
            quality = quality + 1;

            if (sellIn < 11)
            {
                if (quality < 50)
                {
                    quality = quality + 1;               
                }
            }

                if (sellIn < 6)
                {
                    if (quality < 50)
                    {
                        quality = quality + 1;
                    }
                }
                
        }

        sellIn = sellIn - 1;

        if (sellIn < 0)
        {
            quality = quality - quality;
        }

}

void SulfurasHandOfRagnaros::calculateQuality() {

}

void Others::calculateQuality() {
        if (quality > 0)
        {
            quality = quality - 1;
        }

        sellIn = sellIn - 1;
        if (sellIn < 0)
        {
            if (quality > 0)
            {
                quality = quality - 1;
            }
        }    
}