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
        if (count < upper){
            count++;}
    }
    void dec() override{
        if (count > 0){
            count--;
        }
    }
    operator int() override{
        return count;
    }
private:
    int count;
    int upper;
};

LimitedCounter::LimitedCounter(int lower, int upperL):Counter() {
 count = lower;
 upper = upperL;
}

class OverflowCounter:public Counter{
public:
    OverflowCounter (int init = 0, int upperL = 0);
    void inc() override {
        if (count < upper)
            count++;

        else if (count == upper)
            count = 0;

        else if (count == 0)
            count++;}
void dec() override{
        if (count > 0)
            count--;

        else if (count == 0)
            count = upper;

        else if (count == upper)
            count--;
    }
    operator int() override {
            return count;
        }
private:
    int count;
    int upper;
};
    OverflowCounter::OverflowCounter(int init, int upperL): Counter(){
        count = init;
        upper = upperL;
    }

void UseCounter(Counter& ctr, int num) {
    int i = 0;
    if (num > 0) {
        while(i<num){
            ctr.inc();
            i++;
        }
    }
    else {
        while (i<-(num)){
            ctr.dec();
            i++; }
    }
}
int main(int argc, char** argv) {
    LimitedCounter lc(0, 5);
    OverflowCounter oc(5, 9);

    cout << oc << endl; //5
    UseCounter(oc, 5);
    cout << oc << endl;  //0
    UseCounter(oc, -1);
    cout << oc << endl; //9
    oc.dec();
    cout << oc << endl; //8

    cout << lc << endl; // 0
    lc.inc();
    cout << lc << endl; //1
    lc.dec();
    cout << lc << endl; //0
    for(int i = 0; i < 10; ++i) lc.inc();
    cout << lc << endl; //5
    UseCounter(lc, -9);
    cout << lc << endl; //0
    return 0;
}
