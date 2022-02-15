# ifndef _MY_CLASS_H_
# define _MY_CLASS_H_ // headfile should be protected by #define
// or: # pragma once

# include <iostream>
# include <string>
# include <vector>

namespace my_name_space{

using std::string;
using std::vector;

class SalesData
{
    // friend
    friend std::istream &read(std::istream &, SalesData &);
    friend std::ostream &print(std::ostream &, const SalesData &);
    friend SalesData add(const SalesData &, const SalesData &);
    public:
        // constructor
        SalesData() = default; // default constructor
        // list initialization is recomended!
        SalesData(const std::string &s): bookNo(s){/* blank */} // always make it "explicit"
        SalesData(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n){}
        // delegating constructor
        SalesData(const std::string &s, unsigned n): SalesData(s, n, 0){} // just for an example
        explicit SalesData(std::istream &); // explicit: No converting constructor

        // interface
        string isbn() const {return this->bookNo;} // --> It's an implicit inline function
        SalesData &combine(const SalesData &);
    private:
        double avg_price() const; // const: "const member function"
        // type(this): SalesData *const
        // const member function: const SalesData *const
        // that means you can't change class members from this function
        string bookNo = "\0";
        unsigned units_sold = 0;
        double revenue = 0.0;
};

// had better declare friend functions again
std::istream &read(std::istream &, SalesData &);
std::ostream &print(std::ostream &, const SalesData &);
SalesData add(const SalesData &, const SalesData &);

//*****************************

class Screen
{
    friend class WindowMgr;
    public:
        typedef string::size_type pos;
        Screen() = default;
        Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht*wd, c){}
        char get() const {return contents[cursor];}
        inline char get(pos r, pos c) const;
        Screen &move(pos r, pos c); // ~= void move(pos r, pos c);
        void some_mumber() const;
        Screen &set(char);
        Screen &set(pos, pos, char);
        Screen &display(std::ostream &os){do_display(os); return *this;} // not const "this"
        const Screen &display(std::ostream &os) const {do_display(os); return *this;} // const "this"
        
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        string contents = "\0";
        // mutable data number
        mutable size_t access_ctr = 0;
        void do_display(std::ostream &os) const {os<<contents;}
};

inline char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

inline Screen & Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline Screen & Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen & Screen::set(pos r, pos col, char ch)
{
    contents[r*width + col] = ch;
    return *this;
}

//*****************************

class WindowMgr
{
    // friend func. (declare before)
    // friend overload function: declare seperately
    friend Screen &set(char);
    friend Screen &set(Screen::pos, Screen::pos, char);
    public:
        using ScreenIndex = std::vector<Screen>::size_type; // size_type: for string/vector, show length of s/v
        void clear(ScreenIndex);
        ScreenIndex addScreen(const Screen &);
    private:
        vector<Screen> screens{Screen(24,80,' ')};
};

//*****************************
// static members
class Account
{
    public:
        void calculate() {amount += amount * interestRate;}
        static double rate() {return interestRate;} // static return
        static void rate(double newRate);
    private:
        string owner = "\0";
        double amount = 0.0;
        static double interestRate;
        static double initRate() {return 0.0;}
        //initialize static members in class
        static constexpr int period = 30; // must add "constexpr"
        double daily_tbl[period];
        
        // static members and pointers can be incomplete
        static Account a1;
        Account *pa = nullptr;
};

} // namespace: my_name_space

# endif

// inline functions: less than 10 rows
// written in .h