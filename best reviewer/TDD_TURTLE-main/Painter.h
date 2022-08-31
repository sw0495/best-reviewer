#ifndef PAINTER_H_
#define PAINTER_H_

#include "Turtle.h"
#include "iostream"
using namespace std;

class Painter {
public:
    Painter(Turtle* turtle) :
            turtle_(turtle) {
    }

    bool DrawLine(int distance) 
    { 
        if(!turtle_ || distance <= 0) return false; 

        turtle_->PenDown(); 
        turtle_->Forward(distance);
        turtle_->PenUp();
                      
        return true;
    } 

    bool DrawSquare (int distance) 
    { 
        if(!turtle_ || distance <= 0) return false; 
        int degrees = 90;
        turtle_->PenDown(); 
        turtle_->Forward(distance); 
        turtle_->Turn(degrees); 
        turtle_->Forward(distance); 
        turtle_->Turn(degrees); 
        turtle_->Forward(distance); 
        turtle_->Turn(degrees); 
        turtle_->Forward(distance); 
        turtle_->Turn(degrees); 
        turtle_->PenUp(); 
        return true;
    } 


    int fuc1()
    {
        return turtle_->GetX();
    }

    bool fuc2()
    {
        bool ret;
        
        ret = turtle_->MyMethod(100);
        turtle_->MyMethod(200);
        return ret;
    }

    void fuc3()
    {
        turtle_->GoTo(2, 3);
    }

    void fuc4()
    {
        turtle_->GetX();
        turtle_->GetX();
    }

protected:
    Turtle* turtle_;
};

int GetXX() {static int x = 100; return x++;}
int GetYY() {return 200;}

#endif /* PAINTER_H_ */
