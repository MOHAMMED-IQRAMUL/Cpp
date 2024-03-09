#include <bits/stdc++.h>
using namespace std;

class NODE
{
public:
    int DATA;
    NODE *NEXT;
};

class STACK2
{
    NODE *TOP;

public:
    STACK2()
    {
        TOP = NULL;
    }
    int ISEMPTY()
    {
        return TOP ? 0 : 1;
    }
    int ISFULL()
    {
        NODE *T = new NODE;
        int R = T ? 1 : 0;
        return (R);
    }
    void PUSH(int X)
    {
        NODE *T = new NODE;
        if (T == NULL)
            cout << "STACK OVERFLOW ";
        else
        {
            T->DATA = X;
            T->NEXT = TOP;
            TOP = T;
        }
    }
    int POP()
    {
        NODE *P;

        int X = -1;
        if (TOP == NULL)
            cout << "STACK UNDERFLOW ";
        else
        {
            P = TOP;
            TOP = TOP->NEXT;
            X = P->DATA;
            delete P;
        }
        return X;
    }
    int PEEK(int POS)
    {
        int X = -1;
        NODE *P = TOP;

        for (int I = 0; P != NULL && I < POS - 1; I++)
            P = P->NEXT;

        if (P)
            return P->DATA;

        else
            return -1;
    }
    int TOP1()
    {
        if (TOP)
            return TOP->DATA;
        else
            return -1;
    }
    void DISP()
    {
        NODE *P = TOP;
        while (P)
        {
            cout << P->DATA << "  ";
            P = P->NEXT;
        }
    }
};

class STACK1
{
    int SIZE;
    int TOP;
    int *S;

public:
    STACK1()
    {
        SIZE = 10;
        TOP = -1;
        S = new int[SIZE];
    }
    STACK1(int SZ)
    {
        SIZE = SZ;
        TOP = -1;
        S = new int[SIZE];
    }
    void PUSH(int X)
    {
        if (TOP == SIZE - 1)
            cout << "STACK OVERFLOW ";
        else
        {
            TOP++;
            S[TOP] = X;
        }
    }
    int POP()
    {
        int X;
        if (TOP == -1)
            cout << "STACK UNDERFLOW ";
        else
        {
            X = S[TOP];
            TOP--;
        }
        return X;
    }
    int PEEK(int POS)
    {
        int X;
        if ((TOP - POS + 1) < 0)
            cout << "INVALID INDEX ";
        else
            X = S[(TOP - POS + 1)];

        return X;
    }
    int TOP1()
    {
        if (TOP == -1)
            return -1;
        else
            return S[TOP];
    }
    int ISEMPTY()
    {
        if (TOP == -1)
            return 1;
        else
            return 0;
    }
    int ISFULL()
    {
        return (TOP == SIZE - 1);
    }
    void DISP()
    {
        for (int I = TOP; I >= 0; I--)
        {
            cout << S[I] << "  ";
        }
    }
};

int main()
{

    //     STACK1 STK1(6);
    //     STK1.PUSH(1);
    //     STK1.PUSH(2);
    //     STK1.PUSH(3);
    //     STK1.PUSH(4);
    //     STK1.PUSH(5);
    //     STK1.PUSH(6);
    //     STK1.DISP();
    //     cout << endl;
    //     cout << "IS STACK EMPTY ? ";
    //     cout << STK1.ISEMPTY();
    //     cout << endl;
    //     cout << "IS STACK FULL ? ";
    //     cout << STK1.ISFULL();
    //     cout << endl;
    //     cout << "5 TH ELEMENT " << STK1.PEEK(5);
    //     cout << endl;
    //     cout << "TOP ELEMENT POPED " << STK1.POP();
    //     cout << endl;
    //     STK1.DISP();
    //     cout << endl;
    //     cout << "TOP ELEMENT ";
    //    cout <<   STK1.TOP1();
    //     cout << endl;

    // STACK2 STK1;
    // STK1.PUSH(1);
    // STK1.PUSH(2);
    // STK1.PUSH(3);
    // STK1.PUSH(4);
    // STK1.PUSH(5);
    // STK1.PUSH(6);
    // STK1.DISP();
    // cout << endl;
    // cout << "IS STACK EMPTY ? ";
    // cout << STK1.ISEMPTY();
    // cout << endl;
    // cout << "IS STACK FULL ? ";
    // cout << STK1.ISFULL();
    // cout << endl;
    // cout << "5 TH ELEMENT " << STK1.PEEK(5);
    // cout << endl;
    // cout << "TOP ELEMENT POPED " << STK1.POP();
    // cout << endl;
    // STK1.DISP();
    // cout << endl;
    // cout << "TOP ELEMENT ";
    // cout << STK1.TOP1();
    // cout << endl;

    return 0;
}