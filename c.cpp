#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main(void)
{
    
// C++ version info.
long cpp17 = 201703L;
long cpp14 = 201402L;
long cpp11 = 201103L;
long cpp98 = 199711L;
    
// long type → string type.
string cpp_ver = to_string(__cplusplus);
    
if (cpp_ver.compare(to_string(cpp17)) == 0)
    cout << "現在の C++ : C++17" << endl;
else if (cpp_ver.compare(to_string(cpp14)) == 0)
    cout << "現在の C++ : C++14" << endl;
else if (cpp_ver.compare(to_string(cpp11)) == 0)
    cout << "現在の C++ : C++11" << endl;
else if (cpp_ver.compare(to_string(cpp98)) == 0)
    cout << "現在の C++ : C++98" << endl;
else
    cout << "現在の C++ : pre-standard C++" << endl;
    
    return 0;
}