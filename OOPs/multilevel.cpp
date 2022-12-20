#include<iostream>
using namespace std;

class MyClass {
  public:
    void myFunction() {
      cout << "\n\nSome content in parent class.\n\n" ;
    }
};

// Derived class (child)
class MyChild: public MyClass {
};

// Derived class (grandchild)
class MyGrandChild: public MyChild {
};

int main() {
  MyGrandChild myObj;
  myObj.myFunction();
  return 0;
}