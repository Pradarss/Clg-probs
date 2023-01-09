#include<iostream>
using namespace std;

class base{
    public:
        void display(){
            cout<<"Display Base\n";
        }
        virtual void show(){
            cout<<"Display show\n";
        }
};

class derived:public base{
    public:
        void display(){
            cout<<"Display Derived\n";
        }
        void show(){
            cout<<"show derived\n";
        }
};

int main(){
    base b;
    derived d;
    base* bptr;
    bptr=&b;
    bptr->display();
    bptr->show();
    bptr=&d;
    bptr->display();
    bptr->show();
return 0;
}