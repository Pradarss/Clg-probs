#include<iostream>
using namespace std;

class Complex{
    private: 
        int a;
        int b;
    public:
        Complex(int x, int y){
            a = x;
            b = y;
        }
        void display(){
            cout << a << " + i " << b << endl;
        }
        friend Complex add(Complex A, Complex B);
};
Complex add(Complex A, Complex B){
    Complex X((A.a + B.a), (A.b + B.b));
    return X;
}

int main(){
    int a,b,c,d;
    cout<<"Enter real part of first complex number : ";
    cin>>a;
    cout<<"Enter complex part of first complex number : ";
    cin>>b;
    cout<<"Enter real part of second complex number : ";
    cin>>c;
    cout<<"Enter complex part of second complex number : ";
    cin>>d;
    Complex A(a,b), B(c,d);
    A.display();
    B.display();
    add(A,B).display();
    return 0;
}