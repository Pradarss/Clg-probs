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
        serialCode = serial_code;
        for (int i = 0; (i < 20 && title[i] != '\0'); i++)
        {
            this->title[i] = title[i];
        }
    }
    void otherEntries(float duration, int noOfEpisodes)
    {
        duration = duration;
        noOfEpisodes = noOfEpisodes;
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
    char serial1[] = "Breaking Bad";
    char serial2[] = "Better Call Saul";
    Serial S1;
    S1.NewSerial(101, serial1);
    S1.dispData();
    cout << endl;
    Serial S2;
    S2.NewSerial(102, serial2);
    S2.otherEntries(40, 60);
    S2.dispData();
    return 0;
}
