#include<iostream>
using namespace std;

void countStatically(){
    static int count = 1;
    cout << count << endl;
    count ++;
}
void countNonStatically(){
    int count = 1;
    cout << count << endl;
    count ++;
}


int main(){
    cout << "Without using Static keyword" << endl;
    countNonStatically();
    countNonStatically();
    countNonStatically();
    cout << endl << "With Static keyword" << endl;
    countStatically();
    countStatically();
    countStatically();
    return 0;
}