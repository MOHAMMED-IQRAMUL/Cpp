#include <bits/stdc++.h>
using namespace std;

class Students
{
protected:
    float Roll, M1, M2, M3, M4, M5, TOTAL = 500, TOTAL1 = 0, Percentage = 0;

    string Name;

public:
    void PROCESS();
    void GetData();
    float GetRoll() { return Roll; }
};

class MarkSheet : public Students
{
public:
    void Disp();
};

int main()
{
    MarkSheet S1[10];

    // S1.GetData();
    // S1.Disp();

    int OPT, INDEX = 0, ROOL;
STEP_1:
    cout << "PLEASE SELECT ANY OPTION\n"
         << "1.ADD STUDENT RECORD \n"
         << "2.VIEW STUDENT RECORD  \n"
         << "3.GENERATE MARKSHEET \n"
         << "4.TO EXIT \n";
    cin >> OPT;

    switch (OPT)
    {
    case 1:
        S1[INDEX].GetData();
        goto STEP_1;
        break;

    case 2:
        cout << "ENTER STUDENT ROLL NUMBER ";
        cin >> ROOL;
        for (int i = 0; i < 10; i++)
        {
            if (ROOL == S1[i].GetRoll())
            {
                S1[i].Disp();
            }
        }

        goto STEP_1;
        break;

    case 3:
        cout << "ENTER STUDENT ROLL NUMBER ";
        cin >> ROOL;
        for (int i = 0; i < 10; i++)
        {
            if (ROOL == S1[i].GetRoll())
            {
                S1[i].Disp();
            }
        }
        goto STEP_1;
        break;

    case 4:
        return 1;
        break;

    default:
        cout << "ERROR!!! ENTER VALID OPTION ";

        goto STEP_1;
        break;
    }

    return 0;
}
void Students ::GetData()
{
    cout << "Enter The Name ";
    cin >> Name;
    cout << "Enter zzthe Roll Number ";
    cin >> Roll;
    cout << "Enter 5 Subjects Marks ";
    cin >> M1 >> M2 >> M3 >> M4 >> M5;
    PROCESS();
}
void Students ::PROCESS()
{
    TOTAL1 = M1 + M2 + M3 + M4 + M5;
    Percentage = (TOTAL1 / TOTAL) * 100;
}
void MarkSheet ::Disp()
{
    cout << "MARKSHEET " << endl;
    cout << "NAME " << Name << "    ROLL NUMBER " << Roll << endl;
    cout << "MARKS : " << endl
         << "SUBJECT 1 " << M1 << endl
         << "SUBJECT 2 " << M2 << endl
         << "SUBJECT 3 " << M3 << endl
         << "SUBJECT 4 " << M4 << endl
         << "SUBJECT 5 " << M5 << endl
         << "TOTAL MARKS " << TOTAL1 << " / " << TOTAL << endl
         << "PERCENTAGE " << setprecision(4) << Percentage << " % " << endl;
}