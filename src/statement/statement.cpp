# include <iostream>
# include <string>
# include <stdexcept>
using std::cout; 
using std::string;
using std::cerr; 
using std::runtime_error;

int main()
{
    // null statement
    ; // like "pass" in python
    {} // null block

    // if statement
    if(true)
    {

    }
    else if(true)
    {

    }
    else
    {

    }

    // switch statement and range-for statement
    int vowelCnt = 0;
    string str = "natural hazards";
    for (auto it : str)
    {
        switch(it)
        {
            case 'a': // case : integer const expression
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++vowelCnt;
                break; // do not omit "break" for last case
        }
    }
    cout<<"The vowel number of \""<<str<<"\" is "<<vowelCnt<<'\n';

    // goto 
    if(true)
        goto gotoTarget;
    gotoTarget: cout<<"Do not use goto unless necessary\n";

    // exception handler
    // throw and try

    double a = 4.2, b = -1.0;
    try
    {
        if(b == 0.0)
        {
            throw runtime_error("b should not be zero!");
        }
        if(b < 0)
        {
            throw "b should not be smaller than zero!";
        }
    }
    catch(runtime_error err)
    {
        cerr << err.what() << '\n';
    }
    catch(const char* msg)
    {
        cout<<msg<<'\n';
    }
    
    


}

// always be careful about "exception safe"!!!
// g++ -std=c++11 -o statemenT statement.cpp