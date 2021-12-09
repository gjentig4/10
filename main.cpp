#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <algorithm>


using namespace std;

//class LimitedCounter{
public:
    explicit LimitedCounter(int lower = 0, int upper = 0);
protected:
    int low;
    int up;
};

LimitedCounter::LimitedCounter(int lower, int upper) {
 low = lower;
 up = upper;
}

class OverflowCounter {
public:
    explicit OverflowCounter (int lower = 0, int upper = 0);

protected:
    int lowO;
    int upO;
};

OverflowCounter::OverflowCounter(int lower, int upper) {
    lowO = lower;
    upO=upper;
}


class Counter {
public:
    virtual void inc() = 0;
    virtual void dec() = 0;
    virtual operator int() = 0;
    virtual ~Counter() {};
};

void UseCounter(Counter& ctr, int num){

};

int main(int argc, char** argv) {
    LimitedCounter lc(0, 5);
    OverflowCounter oc(5, 9);

    cout << oc << endl;
    UseCounter(oc, 5);
    cout << oc << endl; // should display zero
    UseCounter(oc, -1);
    cout << oc << endl; // should display 9
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
    cout << lc << endl;

    return 0;
}
