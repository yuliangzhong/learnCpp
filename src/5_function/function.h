# ifndef FUNCTION_H
# define FUNCTION_H

size_t count_calls(); // declaration
void resetfp(int *);
void resetfr(int &);
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
intArray5 *chooseArray(int i);
int (*func(int i))[10]; // a function returns a pointer to a 10-int-array
auto func(int i) -> int(*)[10]; // trailing return type
extern int odd[5];
extern int even[5];
# endif