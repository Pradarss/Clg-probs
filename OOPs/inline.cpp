#include<iostream>
using namespace std;

class operation{
    int a,b;
    public:
        operation(int x, int y){
            a=x;
            b=y;
        }
        inline int add(){
            return a+b;
        }
        inline int sub(){
            return a-b;
        }
};

int main(){
    operation e(34,36);
    cout<<"Addition of a and b is \n"<<e.add()<<endl;
    cout<<"Subtraction of a and b is \n"<<e.sub()<<endl;
return 0;
}