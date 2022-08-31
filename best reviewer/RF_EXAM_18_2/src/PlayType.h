#ifndef PLAYTYPE_H
#define PLAYTYPE_H

#include <sstream>
#include <cmath>
#include <map>
#include <iostream>
#include <memory>
#include <string>
using std::string;

class PlayType {
public:

    string name_;
    string type_;    

    static std::shared_ptr<PlayType> create(string name, string type);
    string getName();
    string getType();
    virtual float payAmount(int audience_);

};

#endif