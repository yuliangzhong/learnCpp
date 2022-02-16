# include "generic_algo.hpp"

using namespace generic_algorithm;

int main()
{
    vector<int> t1{1,2,3,42,5,42,5,7,8,0,6,5,4,3};
    vector<int> t2{1,2,3,42,5,42,5};

    Find(t1,42);
    Accumulate(t1);
    Equal(t2, t1);
    Fill(t1, 3, 6);
    FillInsert(t2,5,99);

    vector<string> story{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    ElimDups(story);

    LambdaEx1();
    LambdaEx2();
    
    return 0;
}

// use "container" + "generic algorithms" to solve problems