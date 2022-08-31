#include <random>
#include "HelloWorld.h"

using namespace std;

void HelloWorld::printHelloWorld(const string &arg){
    cout << "Hello World!!!!!\nThis is JUNIT Test program.";
}

string HelloWorld::printNum(int num){
    return "Hello "+num;
}

bool HelloWorld::isGreater(int num1, int num2){
    return num1 > num2;
}

string HelloWorld::getClassName(){
    return "HelloWorld";
}

int HelloWorld::rollDice(){
    default_random_engine random_engine(time(nullptr));
	uniform_int_distribution<unsigned int> score_range(1, 6);
    return score_range(random_engine);
}
