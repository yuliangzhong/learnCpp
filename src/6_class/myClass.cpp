# include<iostream>
# include <string>
# include "myClass.h"
using std::string;

salesData & salesData::combine(const salesData &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double salesData::avg_price() const
{
    return units_sold ? revenue/units_sold : 0;
}

// i/o can't be copied; Pass them by &
std::istream & read(std::istream &is, salesData &item)
{
    double price = 0;
    is>>item.bookNo>>item.units_sold>>price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream & print(std::ostream &os, const salesData &item)
{
    os<<item.isbn()<<" "<<item.units_sold<<" "
      <<item.revenue<<" "<<item.avg_price();
    return os;
}

salesData add(const salesData &lhs, const salesData &rhs)
{
    salesData sum = lhs;
    sum.combine(rhs);
    return sum;
}

salesData::salesData(std::istream &is)
{
    std::istream &iss = read(is, *this); // ???
    // read(is, *this); ???
}

//*****************************

void Screen::some_mumber() const
{
    ++access_ctr;
}

//*****************************

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = string(s.width*s.height, ' ');
}
// should add "Window_mgr::" before ScreenIndex
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
    screens.push_back(s);
    return screens.size() - 1; // minus default screen
}