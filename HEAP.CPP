#include <bits/stdc++.h>
using namespace std;

class HEAP
{
    int *ARR;
    int N;

public:
    HEAP()
    {
        ARR = new int[10];
        N = 0;
        ARR[0] = 0;
        N++;
    }
    HEAP(int X)
    {
        ARR = new int[10];
        N = 0;
        ARR[0] = 0;
        N++;
        ARR[1] = X;
        N++;
    }
    void DISP()
    {
        for (int i = 0; i < N; i++)
        {
            cout << ARR[i] << "  ";
        }
    }
    void INSERT(int X)
    {
        int TEMP, I = N;
        ARR[N] = X;
        N++;
        TEMP = X;
        while (I > 1 && TEMP > ARR[(I / 2)])
        {
            ARR[I] = ARR[I / 2];
            I = I / 2;
        }
        ARR[I] = TEMP;
    }
    void DELETE(int NA)
    {
        int X, I, J, temp;
        X = ARR[1];
        ARR[1] = ARR[NA];
        I = 1;
        J = 2 * 1;
        while (J < (NA - 1))
        {
            if (ARR[J + 1] > ARR[J])
                J = J + 1;

            if (ARR[I] < ARR[J])
            {
                temp = ARR[I];
                ARR[I] = ARR[J];
                ARR[J] = temp;
                I = J;
                J = 2 * J;
            }
            else
            {
                break;
            }
        }
        ARR[NA] = X;
    }
    void HEAPIFY(int X[])
    {
        for (int I = 1; I <= 7; I++)
        {
            ARR[I - 1] = X[I - 1];
            N++;
        }
        N = 7;
        for (int I = (N / 2) - 1; I >= 0; I--)
        {
            int J = 2 * I + 1;
            while (J < N - 1)
            {
                if (ARR[J] < ARR[J + 1])
                    J++;

                if (ARR[I] < ARR[J])
                {
                    int temp = ARR[I];
                    ARR[I] = ARR[J];
                    ARR[J] = temp;
                    I = J;
                    J = 2 * I + 1;
                }
                else
                {
                    break;
                }
            }
        }
    }
};

int main()
{
    {HEAP H1(10);
    H1.INSERT(20);
    H1.INSERT(30);
    H1.INSERT(25);
    H1.INSERT(5);
    H1.INSERT(40);
    H1.INSERT(35);
    H1.DISP();}

    cout << endl;

    {HEAP H2(10);
    int AW[6] = {20, 30, 25, 5, 40, 35};
    for (int I = 0; I < 6; I++)
    {
        H2.INSERT(AW[I]);
    }
    H2.DISP();
    H2.DELETE(7);
    H2.DELETE(6);
    H2.DELETE(5);
    H2.DELETE(4);
    H2.DELETE(3);
    H2.DELETE(2);
    H2.DELETE(1);
    cout << endl;
    H2.DISP();
    cout << endl;}

    {HEAP H3;
    int AAA[7] = {5, 10, 30, 20, 35, 40, 15};
    H3.HEAPIFY(AAA);
    H3.DISP();}
   
    cout << endl;

    {HEAP H4(5);
    H4.INSERT(10);
    H4.INSERT(30);
    H4.INSERT(20);
    H4.INSERT(35);
    H4.INSERT(40);
    H4.INSERT(15);
    H4.DISP();}
    return 0;
}