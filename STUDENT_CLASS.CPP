#include <bits/stdc++.h>
using namespace std;
class STUDENT
{
    string Sname;
    int Marks[6];
    float Total, TMax;

public:
    void Assign()
    {
        cout << "Enter Student Name: ";
        cin >> Sname;
        for (int i = 0; i < 6; i++)
        {
            cout << "Enter marks of subject " << i + 1 << ": ";
            cin >> Marks[i];
        }
        cout << "Enter maximum total marks: ";
        cin >> TMax;
    }
    void Compute()
    {
        Total = 0;
        for (int i = 0; i < 6; i++)
        {
            Total += Marks[i];
        }
    }

    
    void Display()
    {
        cout << "Student Name: " << Sname << endl;
        cout << "Marks are" << endl;
        for (int i = 0; i < 6; i++)
        {
            cout << "Subject " << i + 1 << " : " << Marks[i] << endl;
        }
        cout << "Total: " << Total << endl;
        cout << "Percentage: " << (Total / TMax) * 100 << endl;
    }
};
int main()
{
    STUDENT S1;
    S1.Assign();
    S1.Compute();
    S1.Display();
    return 0;
}