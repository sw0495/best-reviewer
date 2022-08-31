#ifndef PLAY_H
#define PLAY_H

#include <string>
#include <memory>
using std::string;


class PlayType;
class Play {
public:
    Play(string name, string type); 
    
    string name_;
    string type_;    

    float payAmount(int audience_);
    string getName(); 
    string getType();
    
private:
    std::shared_ptr<PlayType> m_type;
    void setType(string name, string type); 
          
};

#endif