#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <algorithm>


using namespace std;

class Counter {
public:
    virtual void inc() = 0;
    virtual void dec() = 0;
    virtual operator int() = 0;
    virtual ~Counter() {};
};

class LimitedCounter:public Counter{
public:
    LimitedCounter(int lower = 0, int upper = 0);
    void inc() override{
        count++;
    }
    void dec() override{
        count--;
    }
    operator int () override {
        return count;
    }
private:
    int count;
    int limit;
};

LimitedCounter::LimitedCounter(int lower, int upper):Counter() {
 count = lower;
 limit = upper;
}

/*
class OverflowCounter :public Counter {
public:
    OverflowCounter (int lower = 0, int upper = 0);
    void inc() override{
        if (count < limit){
            count++;
        }

    else {
        count =0;
    }
private:
    int count;
    int limit;
};

OverflowCounter::OverflowCounter(int lower, int upper):Counter() {
    count = lower;
    limit = upper;
}
*/




void UseCounter(Counter& ctr, int num){

};

int main(int argc, char** argv) {
/*    LimitedCounter lc(0, 5);
    //OverflowCounter oc(5, 9);

    cout << oc << endl;
    UseCounter(2, 5);
    cout << oc << endl; // should display zero

    oc.dec();
    cout << oc << endl; // should display 8

    cout << lc << endl;
    lc.inc();
    cout << lc << endl;
    lc.dec();
    cout << lc << endl;
    for(int i = 0; i < 10; ++i) lc.inc();
    cout << lc << endl;
    UseCounter(lc, -9);
    cout << lc << endl;*/

    LimitedCounter lc(0, 5);

    lc.operator int();
    lc.inc();
    cout << lc << endl; // should display 9

    return 0;
}
