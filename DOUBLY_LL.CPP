#include <bits/stdc++.h>
using namespace std;

class NODE
{
public:
    NODE *PREV;
    int DATA;
    NODE *NEXT;
};

class DOUBLYLINKEDLIST
{
    NODE *FIRST;

public:
    DOUBLYLINKEDLIST() { FIRST = NULL; }

    DOUBLYLINKEDLIST(int A[], int N)

    {
        NODE *D = NULL, *LAST = NULL;
        FIRST = new NODE;

        FIRST->PREV = NULL;
        FIRST->DATA = A[0];
        FIRST->NEXT = NULL;
        LAST = FIRST;
        for (int I = 1; I < N; I++)
        {
            D = new NODE;
            D->DATA = A[I];
            D->NEXT = LAST->NEXT;
            D->PREV = LAST;
            LAST->NEXT = D;
            LAST = D;
        }
    }

    void DISPLAY()
    {
        NODE *D = FIRST;
        while (D)
        {
            cout << D->DATA << "  ";
            D = D->NEXT;
        }
    }

    int LENGTH()
    {
        int LEN = 0;
        NODE *D = FIRST;
        while (D)
        {
            LEN++;

            D = D->NEXT;
        }
        return LEN;
    }

    void INSERT(int IN, int X)
    {
        NODE *D = FIRST;
        NODE *T;
        if (IN < 0 || IN > LENGTH())
            return;
        if (IN == 0)
        {
            T = new NODE;
            T->DATA = X;
            T->PREV = NULL;
            T->NEXT = D;
            D->PREV = T;
            FIRST = T;
        }
        else
        {
            T = new NODE;
            for (int I = 0; I < IN - 1; I++)
                D = D->NEXT;
            T->DATA = X;
            T->NEXT = D->NEXT;
            T->PREV = D;
            D->NEXT = T;
            if (D->NEXT)
                T->NEXT->PREV = D;
        }
    }

    int DELETE(int IN)
    {
        NODE *D = FIRST;
        int X;
        if (IN < 1 || IN >= LENGTH())
            return -1;
        if (IN == 1)
        {
            FIRST = FIRST->NEXT;
            X = D->DATA;
            delete D;
            if (FIRST)
                FIRST->PREV = NULL;
        }
        else
        {

            for (int I = 0; I < IN - 1; I++)
                D = D->NEXT;
            D->PREV->NEXT = D->NEXT;
            if (D->NEXT)
                D->NEXT->PREV = D->PREV;
            X = D->DATA;
            delete D;
        }
        return X;
    }

    void REVERSE()
    {
        NODE *D = FIRST;
        NODE *TEMP;
        while (D)
        {
            TEMP = D->NEXT;
            D->NEXT = D->PREV;
            D->PREV = TEMP;
            D = D->PREV;
            if (D != NULL && D->NEXT == NULL)
                FIRST = D;
        }
    }
};
int main()
{

    // int ARR[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    // DOUBLYLINKEDLIST D1(ARR, 8);

    // cout << endl;
    // cout << "LIST ONE ";
    // D1.DISPLAY();
    // cout << endl;
    // cout << "LENGTH OF LIST ONE IS " << D1.LENGTH();
    // cout << endl;
    // cout << "LIST AFTER INSERTING AT ( 0 / 1 )";
    // D1.INSERT(0, 1);
    // D1.DISPLAY();
    // cout << endl;
    // cout << "LIST AFTER INSERTING AT ( 3 / 3 )";
    // D1.INSERT(3, 3);
    // D1.DISPLAY();
    // cout << endl;
    // cout << "LENGTH OF LIST ONE IS " << D1.LENGTH();
    // cout << endl;
    // cout << "LIST AFTER DELETE AT ( 1 ) "
    //      << D1.DELETE(1);
    // cout << endl;
    // D1.DISPLAY();
    // cout << endl;
    // cout << "LIST AFTER DELETE AT ( 3  ) "
    //      << D1.DELETE(3);
    // cout << endl;
    // D1.DISPLAY();
    // cout << endl;
    // cout << "LENGTH OF LIST ONE IS " << D1.LENGTH();
    // cout << endl;
    // cout << "LIST AFTER REVERSING LIST BY REVERSING LINKS IS  ";
    // D1.REVERSE();
    // D1.DISPLAY();
    // cout << endl;

    return 0;
}