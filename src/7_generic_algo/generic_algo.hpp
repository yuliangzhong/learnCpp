# ifndef _GENERIC_ALGO_HPP_
# define _GENERIC_ALGO_HPP_

# include <iostream>
# include <algorithm>
# include <numeric>
# include <vector>
# include <string>
# include <iterator>
# include <functional>

using CVint = const std::vector<int>;
using Vint = std::vector<int>;

namespace generic_algorithm
{

using std::string; using std::vector;
using std::cout; using std::endl;
using std::placeholders::_1;

void PrintVectorInt(CVint &v)
{
    for (const auto &i : v) cout<<i<<' ';
    cout<<endl;
}

void PrintVectorStr(const vector<string> &v)
{
    for (const auto &i : v) cout<<i<<' ';
    cout<<endl;
}

// find(v.begin(), v.end(), item)
void Find(CVint &v, int item)
{
    auto result = find(v.cbegin(), v.cend(), item);
    cout<<"The value "<<item
        << (result==v.end() ? " is not present" : " is present")
        <<endl;
}

// accumulate
void Accumulate(CVint &v)
{
    cout<<"Total sum: "<<accumulate(v.cbegin(), v.cend(), 0)<<endl;
}

// if [v1.begin, v1.end) = [v2.begin, ... )
void Equal(CVint &v1, CVint &v2)
{
    cout<<equal(v1.cbegin(), v1.cend(), v2.cbegin())<<endl;
}

void Fill(Vint &v, vector<int>::size_type step, int num)
{
    fill(v.begin(), v.begin() + step, num);
    PrintVectorInt(v);
}

void FillInsert(Vint &v, vector<int>::size_type step, int num)
{
    auto it = back_inserter(v); // insert iterator
    fill_n(it, step, num);
    PrintVectorInt(v);
}

inline bool IsShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

inline bool CheckSize(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

void ElimDups(vector<string> &words, vector<string>::size_type sz = 5)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end()); // same size after unique
    words.erase(end_unique, words.end()); // delete here
    PrintVectorStr(words);

    auto words_cp = words;
    // predicate = {unary predicate, binary predicate}
    sort(words_cp.begin(), words_cp.end(), IsShorter);
    PrintVectorStr(words_cp); // sort by length

    // lambda expression
    // [capture list](param list)-> return type {func body}
    auto f = [](double a) -> double {return 42 + a;};
    auto f42 = [] {return 42;};
    cout<<f(5)<<' '<<f42()<<endl;

    auto LIsShorter = [](const string &s1, const string &s2) {return s1.size() < s2.size();};
    stable_sort(words.begin(), words.end(), LIsShorter); // sort by length, if same, keep original sort
    PrintVectorStr(words);

    // (value/ref) catch local unstatic variable sz in lambda
    auto wc = find_if(words.begin(), words.end(), [sz](const string &a) {return a.size() >= sz;});
    // or
    auto wc1 = find_if(words.begin(), words.end(), bind(CheckSize, _1, sz+1));
    auto count = words.end() - wc;
    cout<<count<<" "<<(count>1?"word":"words")<<" of length "<<sz<<" or longer. They are: ";
    for_each(wc, words.end(), [](const string &s){cout<<s<<' ';});
    cout<<endl;

    auto count1 = words.end() - wc1;
    cout<<count1<<" "<<(count1>1?"words":"word")<<" of length "<<(sz+1)<<" or longer. They are: ";
    for_each(wc1, words.end(), [](const string &s){cout<<s<<' ';});
    cout<<endl;
}

void LambdaEx1()
{
    int v = 42;
    auto f = [v]() mutable {return ++v;}; // "mutable"
    v = 1;
    cout<<"v is "<<f()<<endl;
}

void LambdaEx2()
{
    int v = 42;
    auto f = [&v]() mutable {return ++v;};
    v = 1;
    cout<<"v is "<<f()<<endl;
}

} // namespace generic_algorithm

# endif