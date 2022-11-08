#include <iostream>
using namespace std;
class Student
{
    string name;
    int roll, m1 = 0, m2 = 0, m3 = 0, total = 0;

public:
    void inputData(string name, int roll, int m1, int m2, int m3)
    {
        this->name = name;
        this->roll = roll;
        this->m1 = m1;
        this->m2 = m2;
        this->m3 = m3;
    }
    void displayData()
    {
        cout << "\nName : " << name << endl;
        cout << "Roll N0. : " << roll << endl;
        cout << "Marks are : " << m1 << ", " << m2 << ", " << m3 << endl;
        cout << "Total Marks : " << total << endl;
    }
    void calculate()
    {
        total = m1 + m2 + m3;
    }
    int returntotal()
    {
        return total;
    }
    friend void highest(Student, Student);
};
void highest(Student S1, Student S2)
{
    int s1 = S1.returntotal();
    int s2 = S2.returntotal();
    if (s1 > s2){
        cout<<"\nHighest marks is \n";
        S1.displayData();
    }
    else if (s2 > s1){
        cout<<"\nHighest marks is \n";
        S2.displayData();
    }
    else
    {
        cout << "\nBoth have same marks!" << endl;
        S1.displayData();
        S2.displayData();
    }
}
int main()
{
    Student S1, S2;
    S1.inputData("Rahul", 12, 78, 89, 90);
    S2.inputData("Mohit", 13, 91, 88, 83);
    S1.calculate();
    S2.calculate();
    S1.displayData();
    S2.displayData();
    highest(S1, S2);
    return 0;
}