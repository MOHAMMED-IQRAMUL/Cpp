#include <bits/stdc++.h>
using namespace std;

class NODE
{
public:
    int DATA;
    NODE *NEXT;
};

class CIRCULARLINKEDLIST
{
    NODE *HEAD;

public:
    CIRCULARLINKEDLIST() { HEAD = NULL; }
    CIRCULARLINKEDLIST(int ARR[], int N)
    {
        NODE *T1, *LAST;
        HEAD = new NODE;
        HEAD->DATA = ARR[0];
        HEAD->NEXT = HEAD;
        LAST = HEAD;

        for (int I = 1; I < N; I++)
        {
            T1 = new NODE;
            T1->DATA = ARR[I];
            T1->NEXT = LAST->NEXT;
            LAST->NEXT = T1;
            LAST = T1;
        }
    }
    void Display()
    {
        NODE *P = HEAD;

        do
        {
            cout << P->DATA;
            cout << "  ";
            P = P->NEXT;
        } while (P != HEAD);
    }
    NODE *GETHEAD()
    {
        return HEAD;
    }
    void RDISP(NODE *P)
    {
        static int FLAG = 0;
        if (P != HEAD || FLAG == 0)
        {
            FLAG = 1;
            cout << P->DATA << "  ";
            RDISP(P->NEXT);
        }
        FLAG = 0;
    }

};

int main()
{
    int ARR[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    CIRCULARLINKEDLIST L1(ARR, 9);
    L1.Display();
    cout << endl;
    L1.RDISP(L1.GETHEAD());
    cout << endl;
    L1.RDISP(L1.GETHEAD());
    cout << endl;
    return 0;
}