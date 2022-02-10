# include <iostream>
# include <vector>
using std::cout; using std::endl;
using std::vector; using std::string;

int main()
{
    // overflow error
    short short_value = 32767;
    ++short_value;
    cout<<"short_value: "<<short_value<<endl; // output may be -32768

    // truncate error
    int ival1 = 21/6;
    cout<<"int 21 / int 6 = "<<ival1<<endl; // output is 3
    int ival2 = -21/6;
    cout<<"int -21 / int 6 = "<<ival2<<endl; // cut off decimals (c++11)
    
    int a,b,c;
    a = b = c = 42;

    // usage of "*iterator++" = *(it++)
    vector<int> vc = {1,2,3,4,5,6,7,-7,-6,-5};
    auto pbeg = vc.begin();
    while(pbeg != vc.end() && *pbeg >= 0)
        cout<<*pbeg++<<' ';
    cout<<endl;
    
    // ptr->item = (*ptr).item

    // * ? * : *
    int grade = 59;
    string finalgrade = (grade < 60)? "fail": "pass";
    cout<<"Your final grade is "<<finalgrade<<'\n';

    // sizeof -> size_t
    cout<<"Size of vc is "<<sizeof(vc)<<'\n'; // 24 (fixed)

    // conversion, cast
    // static_cast<type>(variable)
    int i = 2, j = 3;
    double slope = static_cast<double>(j) / i;
    // const_cast<>()
    char ex = 'A';
    const char *pc = &ex;
    char *p = const_cast<char*>(pc); // changes low-level const
    // reinterpret_cast<>() DANGER!
    int *ip;
    char *cip = reinterpret_cast<char*>(ip); // cast an int* to a char*
    // dynamic_cast<>()
    
}

// cast should not be used unless necessary
// g++ -std=c++11 -o expressioN expression.cpp