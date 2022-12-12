#include <iostream>
using namespace std;
class Serial
{
    int serialCode;
    char title[20];
    float duration;
    int noOfEpisodes;

public:
    Serial()
    {
        duration = 30;
        noOfEpisodes = 10;
    }
    void NewSerial(int serial_code, char title[])
    {
        serialCode = serial_code; //1
        for (int i = 0; (i < 20 && title[i] != '\0'); i++)    //2(n+1)
         //       1             n+1                     n                                             
        {
            this->title[i] = title[i]; //n
        }
    }
    void otherEntries(float duration, int noOfEpisodes)
    {
        duration = duration; //1
        noOfEpisodes = noOfEpisodes; //1
    }
    void dispData()
    {
        cout << "Serial Code : " << serialCode << endl;
        cout << "Title : " << title << endl;
        cout << "Duration : " << duration << endl;
        cout << "Number of Episodes : " << noOfEpisodes << endl;
    }
};
int main()
{
    char serial1[] = "Breaking Bad"; //1
    char serial2[] = "Better Call Saul";  //1
    Serial S1;
    S1.NewSerial(101, serial1); //2(n^2)+3
    S1.dispData();
    cout << endl;
    Serial S2;
    S2.NewSerial(102, serial2); //2(n^2)+3
    S2.otherEntries(40, 60); //1
    S2.dispData();
    return 0;
}

//f(n)=4(n^2)+9 => o(n^2)
