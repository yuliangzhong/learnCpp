# include "my_class.h" // priority
# include<iostream>
# include <string>

namespace my_name_space{

SalesData & SalesData::combine(const SalesData &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double SalesData::avg_price() const
{
    return units_sold ? revenue/units_sold : 0;
}

// i/o can't be copied; Pass them by &
std::istream & read(std::istream &is, SalesData &item)
{
    double price = 0;
    is>>item.bookNo>>item.units_sold>>price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream & print(std::ostream &os, const SalesData &item)
{
    os<<item.isbn()<<" "<<item.units_sold<<" "
      <<item.revenue<<" "<<item.avg_price();
    return os;
}

SalesData add(const SalesData &lhs, const SalesData &rhs)
{
    SalesData sum = lhs;
    sum.combine(rhs);
    return sum;
}

SalesData::SalesData(std::istream &is)
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

void WindowMgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = string(s.width*s.height, ' ');
}
// should add "WindowMgr::" before ScreenIndex
WindowMgr::ScreenIndex WindowMgr::addScreen(const Screen &s)
{
    screens.push_back(s);
    return screens.size() - 1; // minus default screen
}

//*****************************

// you need to define static members in cpp once!
double Account::interestRate = Account::initRate();
// double Account::interestRate = 0.0;
constexpr int Account::period; // should define again

void Account::rate(double newRate)
{
    interestRate = newRate;
}

} // namespace mynamespace