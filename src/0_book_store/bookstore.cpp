# include <iostream>

int main()
{
    int sum = 0;
    std::cin>>sum;
    std::cout<<"Sum is: "<<sum<<std::endl;
    for(int i=0;i<3;++i)
    {
        std::cout<<"Using ++i is better"<<std::endl;
    }
    std::cerr<<"We are testing Cerror"<<std::endl;
    return 0;
}

// 1. compile code
// $ g++ -o bookstorE bookstore.cpp

// 2. run code
// $ ./bookstorE

// 3. using file as input and output
// $ ./bookstorE <infile.txt >outfile.txt
// errors are printed in terminal, outputs are printed in files

// using ++i is better than i++