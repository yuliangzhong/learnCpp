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

    // converting constructor
    salesData item;
    string null_book = "9-999-99999-9";
    item.combine(null_book); // string ---trans---> salesData object
    item.combine(static_cast<string>("9-999-99999-9"));
    item.combine(salesData("9-999-99999-9")); // only change once

    double r;
    r = Account::rate(); // get static variables of a class
    Account ac1;            r = ac1.rate();
    Account *pac1 = &ac1;   r = pac1->rate(); // same as above





}

// about stream: https://www.zhihu.com/question/26508880
// link error about static members: https://www.jianshu.com/p/14ed355da301
// g++ -std=c++11 -o test main.cpp myClass.cpp
