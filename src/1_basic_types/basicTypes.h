# ifndef BASICTYPES_H
# define BASICTYPES_H

# include <string>

constexpr int factorial(int n);
extern int key = 5; // <-- cause warning

// how to use "extern"?
// 1. defined in main.cpp (outside main), declared in a.h, used in a.cpp
// 2. defined in main.cpp, declared and used in a.cpp
// 3. compiling doesn't care head files

# endif