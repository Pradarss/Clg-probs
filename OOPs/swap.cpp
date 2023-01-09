// C++ program to implement
// function templates
#include <iostream>
using namespace std;

// Function template to swap
// two numbers
template <class T>
int swap_numbers(T& x, T& y)
{
	T t;
	t = x;
	x = y;
	y = t;
	return 0;
}

// Driver code
int main()
{
	int a, b;
	a = 10, b = 20;
    cout <<"Before swaping:\na = "<< a << "\nb = " << b << endl;
	// Invoking the swap()
	swap_numbers(a, b);
	cout <<"\nAfter swaping:\na = "<< a << "\nb = " << b << endl;
	return 0;
}
