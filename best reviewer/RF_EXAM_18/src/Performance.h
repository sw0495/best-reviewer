#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include <string>

class Performance {
public:
    Performance(std::string playID, int audience)
        : playID_(playID), audience_(audience) {
    }

    std::string playID_;
    int audience_;    
};

#endif