# include <iostream>
# include <vector>
# include <string>
# include <cstdlib>
# include <cassert>
# include "function.h"
using std::cout; using std::endl;
using std::vector; using std::string;
using std::begin; using std::end;

// global variables
int odd[5] = {1,3,5,7,9};
int even[5] = {2,4,6,8,10};

int main(int argc, char **argv) 
// or int main(int argc, char *argv[])
{
    for(size_t i=0; i!=10; ++i)
        cout<<count_calls()<<' ';
    cout<<endl;

    int a = 5;
    int *pa = &a;
    resetfp(pa);
    cout<<"Now a is "<<a<<endl;
    resetfr(a);
    cout<<"Now a is "<<a<<endl;

    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int (*p)[10] = &array;
    cout<<"The sum is "<<sumIntArray(begin(array), end(array))<<endl;
    cout<<"The sum is "<<sumIntArray(array)<<endl;
    cout<<"The sum is "<<sumIntArray(p)<<endl;

    string info;
    for(char **p = argv; *p != 0; ++p)
        info += *p;
    cout<<"The info from cmd line is: "<<info<<endl;
    cout<<"argc = "<<argc<<endl;

    // use initializer_list<>
    // for same type, uncertain number formal parameters
    string e1 = "holy", e2 = "shift!", e3 = "god!";
    error_msg({e1, e2, e3}); // use {...} to pass initializer_list
    
    // return a list
    for(const auto s : Process())
        cout<<s<<' ';
    cout<<endl;

    // using typedef can return a pointer/reference of an array
    intArray5 *p5 = chooseArray(5);
    for(const int *b = begin(*p5); b != end(*p5); ++b)
        cout<<*b<<' ';
    cout<<endl;

    //inline function (generally, < 10 lines, no loop/switch)
    string str1 = "I am a good man.";
    string str2 = "I am a bad man.";
    cout<<shorterString(str1, str2)<<endl; 
    // constexpr
    constexpr int A = 5;
    cout<<"The factorial of "<<A<<" is "<<factorial(A)<<endl; 

    // define a function pointer
    vector<string> (*Pro1)() = Process; // <-- don't leave ()
    vector<string> (*Pro2)() = &Process; // <-- don't leave ()
    // use a function pointer (auto cast)
    vector<string> v1 = Pro1();
    vector<string> v2 = (*Pro2)();
    vector<string> v3 = Process(); // same
    // function pointer as parameters (use function name)
    // go to .h for definition
    funcPointer(1, Process);
    funcPointer(1, 2, Process);
    funcPointer(1, 2, 3, Process);


    // assert #include <cassert>, only used in DEBUG mode
    assert(A < 100);

    return EXIT_SUCCESS; // "EXIT_SUCCESS" and "EXIT_FAILURE" in <cstdlib>
}

// separate compilation:
// g++ -std=c++11 -c main.cpp
// g++ -std=c++11 -c function.cpp
// g++ -std=c++11 main.o function.o
// g++ -std=c++11 main.o function.o -o functioN

// or //
// g++ -std=c++11 main.cpp function.cpp
// g++ -std=c++11 main.cpp function.cpp -o functioN
// ./functioN

// or //
// g++ -std=c++11 -o functioN main.cpp function.cpp

// ./functioN -d -o ofile data0 0 hello