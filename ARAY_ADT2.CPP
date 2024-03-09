#include <bits/stdc++.h>
using namespace std;

class ARRAY
{
private:
    int AR[10];
    int N = 10;

public:
    ARRAY() {}
    ARRAY(int A[])
    {
        for (int i = 0; i < N; i++)
        {
            AR[i] = A[i];
        }
    }
    void MISSING1()
    {
        int L = AR[0], H = AR[N - 1];
        int DIFF = L - 0;
        for (int i = 0; i < N; i++)
        {
            if ((AR[i] - i) != DIFF)
            {
                cout << endl
                     << "MISSING ELEMENT IS " << i + DIFF;
                break;
            }
        }
    }

    void MISSING2()
    {

        int L = AR[0], H = AR[N - 1];
        int DIFF = L - 0;
        cout << "\nMISSING ELEMENT ARE  ";
        for (int i = 0; i < N; i++)
        {
            if ((AR[i] - i) != DIFF)
            {
                while (DIFF < (AR[i] - i))
                {
                    cout << i + DIFF << "   ";
                    DIFF++;
                }
            }
        }
    }

    void MISSING3()
    {

        int L = 1, H = 15;
        int R[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        cout << "\nMISSING ELEMENT ARE  ";
        for (int I = 0; I < N; I++)
        {
            R[AR[I]]++;
        }
        for (int I = L; I < H; I++)
        {
            if (R[I] == 0)
                cout << I << "  ";
        }
    }

    void DUPLICATE1()
    {
        int LASTDUP = 0;
        cout << "\nDUPLICATE ELEMENT ARE  ";
        for (int I = 0; I < N; I++)
        {
            if (AR[I] == AR[I + 1] && AR[I] != LASTDUP)
            {
                cout << AR[I] << "  ";
                LASTDUP = AR[I];
            }
        }
    }

    void DUPLICATE2()
    {
        int J = 0;
        cout << "\nDUPLICATE ELEMENT ARE  ";
        for (int I = 0; I < N - 1; I++)
        {
            if (AR[I] == AR[I + 1])
            {
                J = I + 1;
                while (AR[J] == AR[I])
                    J++;
                cout << AR[I] << " APPAERS (  " << J - I << "  TIMES ) ";
                I = J - 1;
            }
        }
    }

    void DUPLICATE3()
    {
        int H[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        cout << "\nDUPLICATE ELEMENT ARE  ";
        for (int I = 0; I < N; I++)
            H[AR[I]]++;

        for (int I = 1; I < 10; I++)
        {
            if (H[I] > 1)
                cout << I << " APPAERS (  " << H[I] << "  TIMES ) ";
        }
    }

    void DUPLICATE4()
    {
        int COUNT;
        cout << "\nDUPLICATE ELEMENT ARE  ";
        for (int I = 0; I < N - 1; I++)
        {
            COUNT = 1;
            if (AR[I] != -1)
            {

                for (int J = I + 1; J < N; J++)
                {
                    if (AR[I] == AR[J])
                    {
                        COUNT++;
                        AR[J] = -1;
                    }
                }
            }
            if (COUNT > 1)
                cout << AR[I] << " APPAERS (  " << COUNT << "  TIMES ) ";
        }
    }

    void PAIR1(int K)
    {
        cout << "\nPAIR ELEMENT ARE ( A + B = K )  ";
        for (int I = 0; I < N - 1; I++)
        {
            for (int J = I + 1; J < N; J++)
            {
                if ((AR[I] + AR[J]) == K)
                    cout << AR[I] << " + " << AR[J] << " = " << K << "  ";
            }
        }
    }

    void PAIR2(int K)
    {
        int H[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        cout << "\nPAIR ELEMENT ARE ( A + B = K )  ";
        for (int I = 0; I < N; I++)
        {

            if (AR[I] <= K && (H[K - AR[I]]) != 0)
                cout << AR[I] << " + " << K - AR[I] << " = " << K << "  ";

            H[AR[I]]++;
        }
    }

    void PAIR3(int K)
    {
        cout << "\nPAIR ELEMENT ARE ( A + B = K )  ";
        int I = 0, J = N - 1;
        while (I < J)
        {
            if ((AR[I] + AR[J]) == K)
            {
                cout << AR[I] << " + " << AR[J] << " = " << K << "  ";
                I++;
                J--;
            }
            else if ((AR[I] + AR[J]) < K)
                I++;
            else
                J--;
        }
    }
};

int main()
{
    int A1[10] = {5, 6, 7, 8, 9, 10, 12, 13, 14, 15};
    ARRAY A(A1);
    A.MISSING1();

    int A2[10] = {1, 2, 5, 7, 8, 9, 11, 12, 13, 14};
    ARRAY B(A2);
    B.MISSING2();

    int A3[10] = {3, 2, 4, 1, 7, 9, 15, 11, 12, 8};
    ARRAY C(A3);
    C.MISSING3();
    //////////////////////////////////
    int A4[10] = {1, 1, 2, 3, 4, 5, 5, 5, 6, 7};
    ARRAY D(A4);
    D.DUPLICATE1();

    int A5[10] = {1, 1, 2, 3, 4, 5, 5, 5, 6, 7};
    ARRAY E(A5);
    E.DUPLICATE2();

    int A6[10] = {6, 7, 5, 5, 1, 2, 1, 3, 4, 5};
    ARRAY F(A6);
    F.DUPLICATE3();

    int A7[10] = {6, 7, 5, 5, 1, 2, 1, 3, 4, 5};
    ARRAY G(A7);
    G.DUPLICATE4();
    //////////////////////////////////
    int A8[10] = {3, 2, 4, 1, 7, 9, 15, 11, 12, 8};
    ARRAY H(A8);
    H.PAIR1(10);

    int A9[10] = {3, 2, 4, 1, 7, 9, 15, 11, 12, 8};
    ARRAY I(A9);
    I.PAIR2(10);

    int A10[10] = {1, 2, 3, 4, 7, 8, 9, 11, 12, 15};
    ARRAY J(A10);
    J.PAIR3(10);

    return 0;
}