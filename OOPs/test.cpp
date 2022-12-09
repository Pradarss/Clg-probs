#include<iostream>
using namespace std;

class complex{
    int x;
    int y;
    public:
        complex(int r, int i){
            x=r;
            y=i;
        }
        friend complex add(complex c1,complex c2);
};
complex add(complex c1,complex c2){
            cout<<c1.x+c2.x<<"+ i"<<c1.y+c2.y<<endl;
        }

int main(){
    complex c1(1,1);
    complex c2(1,1);
    add(c1,c2);
return 0;
}