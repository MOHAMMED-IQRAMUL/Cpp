#include <bits/stdc++.h>
using namespace std;

class ARR
{
private:
    int AR[15];
    int LENGTH;

public:
    ARR() {}
    ARR(int A[], int L);
    void DISP();
    ARR *MERGE(ARR B);
    ARR *UNION1(ARR B);
    ARR *UNION2(ARR B);
    ARR *INTERSECTION1(ARR B);
    ARR *INTERSECTION2(ARR B);
    ARR *DIFFERENCE1(ARR B);
    ARR *DIFFERENCE2(ARR B);
};

ARR ::ARR(int A[], int L)
{
    LENGTH = L;
    for (int I = 0; I < L; I++)
        AR[I] = A[I];
}

void ARR::DISP()
{
    for (int i = 0; i < LENGTH; i++)
    {
        cout << AR[i] << "  ";
    }
    cout << endl;
}

ARR *ARR ::MERGE(ARR B)
{
    int I = 0, J = 0, K = 0;
    ARR *C = new ARR;

    while (I < LENGTH && J < B.LENGTH)
    {
        if (AR[I] < B.AR[J])
            C->AR[K++] = AR[I++];
        else
            C->AR[K++] = B.AR[J++];
    }
    for (; I < LENGTH; I++)
        C->AR[K++] = AR[I];
    for (; J < B.LENGTH; J++)
        C->AR[K++] = B.AR[J];

    C->LENGTH = K;
    return C;
}

ARR *ARR::UNION1(ARR B)
{
    ARR *C = new ARR;
    int I = 0, J = 0, K = 0;
    bool FLAG = true;
    for (I = 0; I < LENGTH; I++)
    {
        C->AR[I] = AR[I];
    }
    for (J = 0; J < B.LENGTH; J++)
    {
        FLAG = true;
        for (K = 0; K < I; K++)
        {
            if (B.AR[J] == C->AR[K])
            {
                FLAG = false;
                break;
            }
        }
        if (FLAG)
            C->AR[I++] = B.AR[J];
    }

    C->LENGTH = I;
    return C;
}

ARR *ARR ::UNION2(ARR B)
{
    int I = 0, J = 0, K = 0;
    ARR *C = new ARR;
    while (I < LENGTH && J < B.LENGTH)
    {
        if (AR[I] < B.AR[J])
            C->AR[K++] = AR[I++];
        else if (B.AR[J] < AR[I])
            C->AR[K++] = B.AR[J++];
        else
        {
            C->AR[K++] = AR[I++];
            J++;
        }
    }
    for (; I < LENGTH; I++)
        C->AR[K++] = AR[I];
    for (; J < B.LENGTH; J++)
        C->AR[K++] = B.AR[J];

    C->LENGTH = K;

    return C;
}

ARR *ARR::INTERSECTION1(ARR B)
{

    ARR *C = new ARR;
    int I = 0, J = 0, K = 0;
    bool FLAG;
    for (I = 0; I < LENGTH; I++)
    {
        FLAG = false;
        for (J = 0; J < B.LENGTH; J++)
        {
            if (AR[I] == B.AR[J])
            {
                FLAG = true;
                break;
            }
        }
        if (FLAG)
            C->AR[K++] = AR[I];
    }

    C->LENGTH = K;
    return C;
}

ARR *ARR::INTERSECTION2(ARR B)
{

    int I = 0, J = 0, K = 0;
    ARR *C = new ARR;
    while (I < LENGTH && J < B.LENGTH)
    {
        if (AR[I] < B.AR[J])
            I++;
        else if (B.AR[J] < AR[I])
            J++;
        else
        {
            C->AR[K++] = AR[I++];
            J++;
        }
    }

    C->LENGTH = K;

    return C;
}

ARR *ARR::DIFFERENCE1(ARR B)
{

    ARR *C = new ARR;
    int I = 0, J = 0, K = 0;
    bool FLAG;
    for (I = 0; I < LENGTH; I++)
    {
        FLAG = true;
        for (J = 0; J < B.LENGTH; J++)
        {
            if (AR[I] == B.AR[J])
            {
                FLAG = false;
                break;
            }
        }
        if (FLAG)
            C->AR[K++] = AR[I];
    }

    C->LENGTH = K;
    return C;
}

ARR *ARR::DIFFERENCE2(ARR B)
{

    int I = 0, J = 0, K = 0;
    ARR *C = new ARR;
    while (I < LENGTH && J < B.LENGTH)
    {
        if (AR[I] < B.AR[J])
            C->AR[K++] = AR[I++];
        else if (B.AR[J] < AR[I])
            J++;
        else
        {
            I++;
            J++;
        }
    }
    for (; I < LENGTH; I++)
        C->AR[K++] = AR[I];

    C->LENGTH = K;

    return C;
}

int main()
{

    int M = 6, N = 7;
    int A11[M] = {7, 8, 5, 6, 1, 4}, B11[N] = {8, 6, 9, 3, 7, 2, 4};
    int A21[M] = {1, 4, 5, 6, 7, 8}, B21[N] = {2, 3, 4, 6, 7, 8, 9};
    ARR A1(A11, M);
    ARR B1(B11, N);
    ARR A2(A21, M);
    ARR B2(B21, N);

    ARR *M1;
    M1 = A1.MERGE(B1);
    ARR *M2;
    M2 = A2.MERGE(B2);
    ARR *U1;
    U1 = A1.UNION1(B1);
    ARR *U2;
    U2 = A2.UNION2(B2);
    ARR *I1;
    I1 = A1.INTERSECTION1(B1);
    ARR *I2;
    I2 = A2.INTERSECTION2(B2);
    ARR *D1;
    D1 = A1.DIFFERENCE1(B1);
    ARR *D2;
    D2 = A2.DIFFERENCE2(B2);

    cout << "SET A1 ELEMENTS ARE ";
    A1.DISP();
    cout << "SET B1 ELEMENTS ARE ";
    B1.DISP();
    cout << "SET A2 ELEMENTS ARE ";
    A2.DISP();
    cout << "SET B2 ELEMENTS ARE ";
    B2.DISP();
    cout << "MERGING OF TWO SET A AND B IS USING UNSORTED ARRAY ";
    M1->DISP();
    cout << "MERGING OF TWO SET A AND B IS USING SORTED ARRAY ";
    M2->DISP();

    cout << "UNION OF SET A AND B IS USING UNSORTED ARRAY ";
    U1->DISP();
    cout << "UNION OF SET A AND B IS USING SORTED ARRAY ";
    U2->DISP();
    cout << "INTERSECTION OF SET A AND B IS USING UNSORTED ARRAY ";
    I1->DISP();
    cout << "INTERSECTION OF SET A AND B IS USING SORTED ARRAY ";
    I2->DISP();
    cout << "DIFFERENCE OF SET A AND B IS USING UNSORTED ARRAY ";
    D1->DISP();
    cout << "DIFFERENCE OF SET A AND B IS USING SORTED ARRAY ";
    D2->DISP();
    return 0;
}