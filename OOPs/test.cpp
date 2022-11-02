#include <iostream>
using namespace std;
string operator+(string A, string B)
{
    return A.append(B);
}
int main()
{
    string X = "Hello There ";
    string Y = "I am the C++ Compiler.";
    string Z = X + Y;
    cout << Z << endl;
    return 0;
}