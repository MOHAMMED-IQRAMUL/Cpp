#include <bits/stdc++.h>
using namespace std;
class ARRAY
{
    int ARR[20];
    int LENGTH;

public:
    ARRAY() {}
    ARRAY(int AR[], int L)
    {
        LENGTH = L;
        for (int I = 0; I < L; I++)
            ARR[I] = AR[I];
    }

    void DISP()
    {

        for (int i = 0; i < LENGTH; i++)
        {
            cout << ARR[i] << "  ";
        }
        cout << endl;
    }

    void DISP2()
    {

        for (int i = LENGTH - 1; i >= 0; i--)
        {
            cout << ARR[i] << "  ";
        }
        cout << endl;
    }

    void INSERT(int IN, int EL)
    {    
        for (int i = LENGTH; i < IN; i++)
        {
            ARR[i] = ARR[i - 1];
        }
        ARR[IN] = EL;
    }

    void DELETE(int IN)
    {

        for (int i = IN; i < LENGTH; i++)
        {
            ARR[i] = ARR[i + 1];
        }
        LENGTH--;
    }

    string SEARCH(int EL)
    {
        int FLG = 0, IND;
        for (int i = 0; i < LENGTH; i++)
        {
            if (ARR[i] == EL)
            {
                IND = i;
                FLG = 1;
                break;
            }
        }

        if (FLG == 1)
        {
            string L = "ELEMENT FOUND AT INDEX " + to_string(IND + 1);
            return L;
        }
        else
        {
            string L = "ELEMENT NOT FOUND AT ANY INDEX ";
            return L;
        }
    }
};
int main()
{
    int M = 6, A1[M] = {1, 3, 4, 5, 6, 3};
    ARRAY AR(A1, M);
    cout << "ARRAY ELEMENTS ARE ";
    AR.DISP();
    cout << "ARRAY ELEMENTS IN REVERSE ARE ";
    AR.DISP2();

    cout << "ARRAY ELEMENTS AFTER DELETETING AT INDEX 3(I=2) ";
    AR.DELETE(2);
    AR.DISP();

    cout << "ARRAY ELEMENTS AFTER INSERTING AT INDEX 2(I=1) ";
    AR.INSERT(1, 2);
    AR.DISP();

    cout << "ARRAY ELEMENT  5 IS AT INDEX 4(I=3) ";
    cout << AR.SEARCH(5); 

    return 0;
}                                                                                  