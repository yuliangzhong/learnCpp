# include <iostream>
# include "basicTypes.h"
# include <string>



constexpr int factorial(int n)
{
    return n <= 1? 1 : (n * factorial(n - 1));
}

int main()
{
    bool ifHappy = true;
    char letter = 'A';
    int number = 5;
    extern int key;
    const int bufSize = 512;    
    long long money = 1e9;
    double ratio = 0.95;
    
    // do not mix use signed types and unsigned types
    // List Initialization: prevent data loss
    // declaration & definition

    // reference
    int &refnum = number;
    const int &crefnum = number;
    // right: refnum = 6;
    // wrong: crefnum = 6;

    // pointer
    int *p1 = nullptr, *p2 = 0; // null pointer
    int *pNum = &number;
    std::cout<<"number is "<< *pNum <<'\n';
    int **ppNum = &pNum; // pointer of pointer
    int *&rpNum = pNum; // reference of a pointer
    std::cout<<"number is "<< *rpNum <<'\n';
    // pointer to const
    const int *pbufSize = &bufSize;
    const int *readNum = &number;
    // const pointer
    int *const numPointer = &number; // always points number
    const int *const ccPointer = &number;
    
    // constexpr
    constexpr int result = factorial(5);
    std::cout<<"factorial 5 = "<<result<<'\n';

    // type def
    typedef double ciclePI;
    using SI = double;
    ciclePI pi = 3.14, *point = nullptr;
    SI pii = 6.28;
    
    // auto
    auto item = number + bufSize, *pnum = &number;
    const int i = 42;
    auto j = i; j = 43; // sometimes it ignores high level const
    const auto &k = i; // k is "const int"
    
    // decltype
    decltype(factorial(6)) frac;
    decltype(key + number) password;
    
    // struct
    struct salesData
    {
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
    };

}



// add "-std=c++11" for c++11 when compiling
// g++ -std=c++11 -o basicTypes basicTypes.cpp
// how to solve red waves of c++11: https://juejin.cn/post/6994430039966089223