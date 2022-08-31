#include "PlayType.h"

std::shared_ptr<PlayType> PlayType::create(string name, string type)
{
    if (type == "tragedy") {
        std::shared_ptr<PlayType> plyaType = std::make_shared<Tragedy>();
        plyaType -> name_ = name;
        plyaType -> type_ = type;
        return plyaType;
    }

    if (type == "comedy") {
        std::shared_ptr<PlayType> plyaType = std::make_shared<Comedy>();
        plyaType -> name_ = name;
        plyaType -> type_ = type;
        return plyaType;
    }

    return std::make_shared<Unknown>();
}

string PlayType::getName()
{
    return name_;
}

string PlayType::getType()
{
    return type_;
}

class Tragedy : public PlayType {
public:
    float payAmount(int audience_) {
        float thisAmount = 40000;
        if (audience_ > 30) {
            thisAmount += 1000 * (audience_ - 30);
        }

        return thisAmount;
    }
};


class Comedy : public PlayType {
public:
    float payAmount(int audience_) {
        float thisAmount = 30000;
        if (audience_ > 20) {
            thisAmount += 10000 + 500 * (audience_ - 20);
        }
        thisAmount += 300 * audience_;  
    
        return thisAmount;
    }
};


class Unknown : public PlayType {
public:
    float payAmount(int audience_) {
        throw std::domain_error("unknown type: " + type_);
    }

};
