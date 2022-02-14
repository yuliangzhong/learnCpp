// class
// for data abstraction (interface, implementation) and encapsulation
# include <iostream>
# include <string>
# include "myClass.h"
using std::string;
using std::cin; using std::cout; using std::endl;

int main()
{    
    // salesData testData(cin); // "38324" 989 65
    Screen myScreen(24, 80, ' ');
    myScreen.move(4,0).set('#');

    Screen myScr(5,3,'c');
    const Screen blank(5,3,'c');
    myScr.set('#').display(cout);
    blank.display(cout);







}

// about stream: https://www.zhihu.com/question/26508880
// g++ -std=c++11 -o test main.cpp myClass.cpp
