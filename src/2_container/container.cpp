# include <iostream>
# include <string>
# include <cctype> // i.e. "ctype.h"
# include <vector>
# include <array>
# include <stack>
# include "container.h"
using std::string;
using std::vector;
using std::array;
using std::stack;
using std::cin; using std::cout;
using std::begin; using std::end;

void PrintVector(const vector<int> &v)
{
    for (const auto &i : v) cout<<i<<' ';
    cout<<std::endl;
}

void PrintVector(const vector<string> &v)
{
    for (const auto &i : v) cout<<i<<' ';
    cout<<std::endl;
}

int main()
{
    // string
    string s1;
    string s2 = s1;
    string s3 = "c++";
    string s4(10,'c');
    string s5("hello");

    // string cin/cout/getline/size/empty/==,>,<
    // string.size() returns a "string::size_type"
    // it's unsigned and large enough
    // don't use int for +- if ".size()" applied

    // range for
    string s("Hello World!!!");
    decltype(s.size()) punct_cnt = 0;
    for (auto c : s)
        if(ispunct(c)) ++punct_cnt; // lots of is..() functions in <cctype>
    cout<<punct_cnt<<" punctuation characters in "<<s<<'\n';

    for (auto &c : s)
        c = toupper(c); // in <cctype>
    cout<<s<<'\n';

    // vector
    vector<int> ivec;
    vector<vector<string>> file; //a vector of string vectors
    vector<int> v1; vector<int> v2(v1); vector<int> v3 = v2;
    vector<int> v4(5,1); vector<int> v5(9); 
    vector<int> v6{1,2,3,4,5}; vector<int> v7 = {6,7,8,9,10};
    // difference of () and {}! 
    // v1(10) & v1{10}; v2(10,1) & v2{10,1}
    for (int i = 0; i < 10; ++i)
        ivec.push_back(i); // it's very efficient and recommended

    // iterator
    auto head = ivec.begin(), tail = ivec.end(); // off-the-end iterator
    cout<<"head = tail? "<<(head == tail)<<'\n';
    if(head != tail) // check if a vector is empty
        cout<<"it's not empty"<<'\n';
    auto chead = ivec.cbegin(), ctail = ivec.cend(); // const_iterator
    cout<<"first item = "<<*chead<<", last item = "<<*(--ctail)<<'\n';
    
    string ss("Hello World!!!");
    for (auto it = ss.begin(); it != ss.end() && !isspace(*it); ++it)
        *it = toupper(*it);
    cout<<ss<<'\n';

    // array
    int arr[10] = {1,2,4}, *pointer[10];
    *(arr+9) = 42;
    for (auto i : arr)
        cout<<i<<' ';
    cout<<'\n';
    int *beg = begin(arr);
    int *last = end(arr); // get the end of the array!
    cout<<"first item = "<<*beg<<", last item = "<<*(--last)<<'\n';
    
    // 2-dim array
    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia[rowCnt][colCnt];
    size_t cnt = 0;
    for (auto &row : ia)
        for (auto &col : row)
            {
                col = cnt;
                ++cnt;
            }
    for (auto &row : ia)
    {
        for (auto &col : row)
            cout<<col<<' ';
        cout<<'\n';
    }

    //************************************//
    // Sequential container
    // vector; string; (usually choose them)
    // list; forward_list; (if asked to insert in the middle)
    // deque; ( -> head / tail <-)
    // array;
    array<int,5> int_array{6,7,8}; // else: 0

    vector<int> test{1,3,5,7,9,2,4,6,8};
    for (auto it : test) {}
    for (auto it = test.begin(); it != test.end(); ++it) {} // [,) iterator range
    test.push_back(99); PrintVector(test); // push_back(): value copy
    test.insert(++test.begin(), 98); PrintVector(test); // can be slow
    test.insert(test.begin(), 3, 77); PrintVector(test);
    cout<<"The capacity of test is: "<<test.capacity()<<std::endl;
    cout<<"The size of test is: "<<test.size()<<std::endl;    
    test.pop_back(); PrintVector(test);
    while(test.begin() != test.end()) test.begin() = test.erase(test.begin()); // |_a1 a2 --> |_a2
    PrintVector(test); // output is empty

    vector<int> input;
    int tmp;
    auto it_input = input.begin();
    while (cin>>tmp) it_input = input.insert(it_input, tmp); // |_a2 --> |_a1 a2
    PrintVector(input);
    input.erase(input.begin(), input.end()); // erase a range

    // use "emplace" to construct objects
    vector<string> emp{"hello"};
    emp.emplace_back("hi"); PrintVector(emp); // emplace(), emplace_front()
    emp.clear(); // clear all items
    emp.resize(5,"nice"); PrintVector(emp);

    // container adaptor: stack, queue, priority_queue
    stack<int> int_stack;
    for (size_t ix = 0; ix != 10; ++ix) int_stack.push(ix);
    while (!int_stack.empty())
    {
        int value = int_stack.top();
        int_stack.pop();
    }
}
// use string, vector and iterator more! 
// In "for loop", use "!=" instead of "<,>" more! Because "<,>" may not be defined
// Do not add vector items in an iterator loop
// don't forget '\0' in string
// "hello" is a char array
// string s1 = "hi", s1 points to the head of char array ['h','i','\0']

// g++ -std=c++11 -o containeR container.cpp
