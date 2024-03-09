#include <bits/stdc++.h>
using namespace std;

class ELEMENT
{
    int I, J, X;
    friend class SPARSE;
};

class SPARSE
{
    int M, N, NUM;
    ELEMENT *EL;

public:
    SPARSE() {}
    void SETDATA()
    {
        cout << "ENTER DIMENSIONS AND NON ZERO ELEEMENT (ROWS/COLUMN/NUMBER OF NON ZERO ELEMENT)\n";
        cin >> M >> N >> NUM;

        EL = new ELEMENT[NUM];
        cout << "ENTER " << NUM << " ELEMENTS (ROW/COLUMN/ELEMENT)  " << endl;
        for (int i = 0; i < NUM; i++)
        {
            cin >> EL[i].I >> EL[i].J >> EL[i].X;
        }
    }
    void DISP()
    {

        int K = 0;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == EL[K].I && j == EL[K].J)
                    cout << EL[K++].X << "   ";
                else
                    cout << "0   ";
            }
            cout << endl;
        }
    }
    SPARSE operator+(const SPARSE S)
    {
        SPARSE S2;
        S2.M = M;
        S2.N = N;
        S2.EL = new ELEMENT[NUM + S.NUM];

        // if (M == S.M || N == S.N)

        int i = 0, j = 0, K = 0;
        while (i < NUM && j < S.NUM)
        {
            if (EL[i].I < S.EL[j].I)
                S2.EL[K++] = EL[i++];

            else if (EL[i].I > S.EL[j].I)
                S2.EL[K++] = S.EL[j++];

            else
            {
                if (EL[i].J < S.EL[j].J)
                    S2.EL[K++] = EL[i++];

                else if (EL[i].J > S.EL[j].J)
                    S2.EL[K++] = S.EL[j++];

                else
                {
                    S2.EL[K] = EL[i++];
                    S2.EL[K++].X += S.EL[j++].X;
                }
            }
        }
        for (; i < NUM; i++)
            S2.EL[K++] = EL[i];
        for (; j < S.NUM; j++)
            S2.EL[K++] = S.EL[j];

        S2.NUM = K;

        return S2;
    }
};

int main()
{
    // SPARSE S1, S2;
    // SPARSE S3;
    // S1.SETDATA();
    // S2.SETDATA();
    // S3 = S1 + S2;
    // cout << "SPARSE MATRIX NUMBER 1\n";

    // S1.DISP();
    // cout << "SPARSE MATRIX NUMBER 2\n";
    // S2.DISP();

    // cout << "SUM OF SPARSE MATRIX 1 2  \n";
    // S3.DISP();

    SPARSE S1, S2;
    SPARSE S3;
    S1.SETDATA ();
    S2.SETDATA ();
    S3 = S1 + S2;
    cout << "SPARSE MATRIX NUMBER 1\n";

    S1.DISP();
    cout << "SPARSE MATRIX NUMBER 2\n";
    S2.DISP();

    cout << "SUM OF SPARSE MATRIX 1 2  \n";
    S3.DISP();

    return 0;
}
