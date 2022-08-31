#include "PlayType.h"
#include "Play.h"

Play::Play(string name, string type) {
    setType(name, type);
} 

void Play::setType(string name, string type) {
    m_type = PlayType::create(name, type);
}

float Play::payAmount(int audience_) {
    return m_type -> payAmount(audience_);
}

string Play::getName() {
    return m_type -> getName();
}

string Play::getType() {
    return m_type -> getType();
}