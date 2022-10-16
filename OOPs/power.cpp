#include<iostream>
using namespace std;

int power(int x, int n=2){
    int result = 1;
    for(int i=0; i<n; i++){
        result *= x;
    }
    return result;
}

int main(){
    int x,n;
    char choice;
    while(true){
    cout<<"\nDo you want to enter power? y/n : ";
    cin>>choice;
    if(choice=='y'){
        cout<<"Enter number : ";
        cin>>x;
        cout<<"Enter power : ";
        cin>>n;
        cout<<"Answer is "<<power(x,n);
    }
    else{
        cout<<"Enter number : ";
        cin>>x;
        cout<<"Square of number is "<<power(x);
    }
    }
    return 0;
}