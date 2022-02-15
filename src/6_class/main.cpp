// class
// for data abstraction (interface, implementation) and encapsulation
# include <iostream>
# include <string>
# include "my_class.h"

using std::cin; using std::cout; using std::endl;
using namespace my_name_space;

int main()
{    
    SalesData testData(cin); // "38324" 989 65
    Screen myScreen(24, 80, ' ');
    myScreen.move(4,0).set('#');

    Screen myScr(5,3,'c');
    const Screen blank(5,3,'c');
    myScr.set('#').display(cout);
    blank.display(cout);

    // converting constructor
    SalesData item;
    string null_book = "9-999-99999-9";
    item.combine(null_book); // string ---trans---> SalesData object
    item.combine(static_cast<string>("9-999-99999-9"));
    item.combine(SalesData("9-999-99999-9")); // only change once

    double r;
    r = Account::rate(); // get static variables of a class
    Account ac1;            r = ac1.rate();
    Account *pac1 = &ac1;   r = pac1->rate(); // same as above

    return 0;
}


// about stream: https://www.zhihu.com/question/26508880
// link error about static members: https://www.jianshu.com/p/14ed355da301
// g++ -std=c++11 -o test main.cpp myClass.cpp
// put main() outside my_name_space{}

// pass "const &" or "value" in func()
// variable name: a_local_variable, a_struct_data_member, a_class_data_member_
// const int kDaysInAWeek = 7; start from "k" for const or constexpr
// void FuncListMpc(int, int);