# ifndef FUNCTION_H
# define FUNCTION_H

size_t count_calls(); // declaration
void resetfp(int *);
void resetfr(int &);
// overloaded function
int sumIntArray(const int *begin, const int *end);
int sumIntArray(const int (&arr)[10]);
int sumIntArray(const int (*p)[10]);
// Attention! "int (&arr)[10]" means the reference of a 10-int-array!
// Attention! "int &arr[10]" means a 10-array of int-reference! [-> error]
// Attention! Only accept arrays of 10 elements!
// also: "int (*arr)[10]" means a pointer to a 10-int-array
//       "int *arr[10]" means a 10-int*-array of pointers

void error_msg(std::initializer_list<std::string> il);

// return a list
std::vector<std::string> Process();

// using typedef can return a pointer/reference of an array
typedef int intArray10[10];
using intArray5 = int[5];
intArray5 *chooseArray(int i = 5);
int (*func(int i))[10]; // a function returns a pointer to a 10-int-array
auto func(int i) -> int(*)[10]; // trailing return type
extern int odd[5];
extern int even[5];

// inline function (should be defined in headfiles)
inline const std::string &shorterString(const std::string &s1, const std::string &s2)
{
    return s1.size()<= s2.size() ? s1 : s2;
}
// also constexpr func. --implicitly --> inline func.
// should be defined in headfiles
constexpr int factorial(int a)
{
    return a<=1 ? 1 : a * factorial(a-1);
}

// function pointer as param
typedef std::vector<std::string> (*Pro3)();   // Pro3 is a function pointer
typedef std::vector<std::string> (process)(); // process is a function type
using F = std::vector<std::string>(int, int); // F is a function type
using PF = std::vector<std::string>(*)(int, int); // PF is a function pointer

void funcPointer(int, std::vector<std::string> (*Pro)()); // explicit define
void funcPointer(int, int, std::vector<std::string> Pro()); // implicit define
void funcPointer(int, int, int, Pro3); // use typedef

// function pointer as return
Pro3 funcReturn(int); // return must be a function pointer
auto autoFuncReturn(int) -> std::vector<std::string>(*)(int, int);

// decltype returns a function type
typedef decltype(Process) *Pro4; // Pro4 is a function pointer

# endif