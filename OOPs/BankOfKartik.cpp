#include<iostream>
using namespace std;

class Bank{
    private:
        const long long prefixAccNo = 101212000;
        static int AccNo;
        string name;
        string type;
        int balance;
    public:
        Bank(string name, string type){
            this->name = name;
            this->type = type;
            balance = 0;
            AccNo++;
        }
        void deposit(int money){
            balance += money;
            cout<<"\nAmount deposited : "<<money;
            cout<<"\nCurrent balance : "<<balance;
        }
        void withdraw(int money){
            if(money<=balance){
                balance-=money;
                cout<<"\nAmount withdrawn : "<<money;
                cout<<"\nAmount Left : "<<balance;
            }
            else{
                cout << "Insufficient balance!!!" << endl;
            }
        }
        void checkBalance(){
            cout <<"\n\nBalance is : " << balance << endl;
        }
        void checkDetails(){
            cout << "\n\nAccount Number : " << prefixAccNo+AccNo << endl;
            cout << "Account Holder : " << name << endl;
            cout << "Account Type : " << type << endl;
        }
};
int Bank::AccNo = 1021021200;

int main(){
    Bank User1("Rahul","Savings");
    User1.checkDetails();
    User1.deposit(10000);
    User1.withdraw(900);
    User1.checkBalance();

    Bank User2("Anil","Current");
    User2.checkDetails();
    return 0;
}