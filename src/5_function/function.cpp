# include <iostream>
# include <vector>
# include "function.h"
using std::cout; using std::endl;

// local static object
size_t count_calls()
{
    static size_t ctr = 0; // ctr still alive after func. calling
    return ++ctr;
}

void resetfp(int *p)
{
    *p = 0; // use pointer or reference to change variables outside functions
} // using reference is better (avoid copying)

void resetfr(int &p)
{
    p = 5;
}

int sumIntArray(const int *b, const int *e)
{
    int sum = 0;
    while(b != e)
        sum += *b++;
    return sum;
}

int sumIntArray(const int (&arr)[10])
{
    int sum = 0;
    for(auto a : arr)
        sum += a;
    return sum;
}

int sumIntArray(const int (*p)[10])
{
    int sum = 0;
    for(auto a : *p)
        sum += a;
    return sum;
}

void error_msg(std::initializer_list<std::string> il)
{
    for(auto beg = il.begin(); beg != il.end(); ++beg)
        cout<<*beg<<' ';
    cout<<endl;
}
