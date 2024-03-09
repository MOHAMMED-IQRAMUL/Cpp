#include <bits/stdc++.h>
using namespace std;

template <class T>
class NODE
{
public:
    T DATA;
    NODE<T> *NEXT;
};

template <class T>
class LINKEDLIST
{
    NODE<T> *FIRST;

public:
    LINKEDLIST() { FIRST = NULL; }
    ~LINKEDLIST() {}
    template <class U1>
    friend void RDISP(NODE<U1> *P);
    template <class U2>
    friend int RLength(NODE<U2> *P);
    template <class U3>
    friend T RSUM(NODE<U3> *P);
    template <class U4>
    friend T RMAX(NODE<U4> *P);
    template <class U5>
    friend T RMIN(NODE<U5> *P);

    NODE<T> *GETFI()
    {
        return FIRST;
    }

    LINKEDLIST(T ARR[], int N)
    {
        NODE<T> *T1, *LAST;
        FIRST = new NODE<T>;
        FIRST->DATA = ARR[0];
        FIRST->NEXT = NULL;
        LAST = FIRST;

        for (int I = 1; I < N; I++)
        {
            T1 = new NODE<T>;
            T1->DATA = ARR[I];
            T1->NEXT = NULL;
            LAST->NEXT = T1;
            LAST = T1;
        }
    }

    void Display()
    {
        NODE<T> *P = FIRST;

        while (P)
        {
            cout << P->DATA;
            P = P->NEXT;
            cout << "  ";
        }
    }

    T SUM()
    {
        NODE<T> *P = FIRST;
        T SUMA = 0;
        while (P)
        {
            SUMA += P->DATA;
            P = P->NEXT;
        }
        return SUMA;
    }

    T MAX()
    {
        NODE<T> *P = FIRST;
        T MAX1 = P->DATA;
        while (P)
        {
            if (P->DATA > MAX1)
                MAX1 = P->DATA;
            P = P->NEXT;
        }
        return MAX1;
    }

    T MIN()
    {
        NODE<T> *P = FIRST;
        T MIN1 = P->DATA;
        while (P)
        {
            if (P->DATA < MIN1)
                MIN1 = P->DATA;
            P = P->NEXT;
        }
        return MIN1;
    }

    void Insert(int I, T X)
    {
        NODE<T> *P = FIRST, *M, *N;
        if (I == 0)
        {
            M = new NODE<T>;
            M->DATA = X;
            M->NEXT = FIRST;
            FIRST = M;
        }
        else if (I > 0)
        {
            N = P;
            for (int i = 0; i < I - 1 && P; i++)
                N = N->NEXT;
            if (N)
            {
                M = new NODE<T>;
                M->DATA = X;
                M->NEXT = N->NEXT;
                N->NEXT = M;
            }
        }
    }

    void SORTINSERT(int X)
    {
        NODE<T> *P = FIRST;
        NODE<T> *M = new NODE<T>, *Q = NULL;

        M->DATA = X;
        M->NEXT = NULL;
        if (FIRST == NULL)
            FIRST = M;

        else
        {
            while (P && P->DATA < X)
            {
                Q = P;
                P = P->NEXT;
            }
            if (P == FIRST)
            {
                M->NEXT = FIRST;
                FIRST = M;
            }
            else
            {
                M->NEXT = Q->NEXT;
                Q->NEXT = M;
            }
        }
    }

    T Delete(int I, int L)
    {
        NODE<T> *P = FIRST;
        NODE<T> *Q = NULL;
        T X = -1;
        if (I < 1 || I > L)
        {
            return -1;
        }
        if (I == 1)
        {
            Q = FIRST;
            X = FIRST->DATA;
            FIRST = FIRST->NEXT;
            delete Q;
            return X;
        }
        else
        {
            for (int i = 0; i < I - 1; i++)
            {
                Q = P;
                P = P->NEXT;
                Q->NEXT = P->NEXT;
                X = P->DATA;
                delete P;
                return X;
            }
        }
    }

    int Length()
    {
        NODE<T> *P = FIRST;
        int C = 0;
        while (P)
        {
            C++;
            P = P->NEXT;
        }
        return C;
    }

    string SEARCH(T KEY)
    {
        NODE<T> *P = FIRST;
        while (P)
        {
            if (KEY == P->DATA)
                return " FOUND ";
            P = P->NEXT;
        }
        return " NOT FOUND ";
    }

    void REVERSE1()
    {
        NODE<T> *P = FIRST;
        T *A;
        int I = 0;
        NODE<T> *Q = P;
        A = new T[Length()];
        while (Q)
        {
            A[I] = Q->DATA;
            Q = Q->NEXT;
            I++;
        }
        Q = P;
        I--;
        while (Q)
        {
            Q->DATA = A[I];
            Q = Q->NEXT;
            I--;
        }
    }

    void REVERSE2()
    {
        NODE<T> *P = FIRST;
        NODE<T> *Q = NULL, *R = NULL;
        while (P)
        {
            R = Q;
            Q = P;
            P = P->NEXT;
            Q->NEXT = R;
        }
        FIRST = Q;
    }

    void REVERSE3(NODE<T> *P = NULL)
    {
        if (P == NULL)
        {
            P = FIRST;
        }

        if (P == NULL || P->NEXT == NULL)
        {

            FIRST = P;
            return;
        }

        NODE<T> *L = P->NEXT;
        REVERSE3(L);
        L->NEXT = P;
        P->NEXT = NULL;
    }

    void MERGESORT(NODE<T> *F, NODE<T> *S)
    {
        NODE<T> *LAST;
        if (F->DATA < S->DATA)
        {
            FIRST = LAST = F;
            F = F->NEXT;
            FIRST->NEXT = NULL;
        }
        else
        {
            FIRST = LAST = S;
            S = S->NEXT;
            FIRST->NEXT = NULL;
        }
        while (F && S)
        {
            if (F->DATA < S->DATA)
            {
                LAST->NEXT = F;
                LAST = F;
                F = F->NEXT;
                LAST->NEXT = NULL;
            }
            else
            {
                LAST->NEXT = S;
                LAST = S;
                S = S->NEXT;
                LAST->NEXT = NULL;
            }
        }
        if (F)
            LAST->NEXT = F;
        if (S)
            LAST->NEXT = S;
    }

    T MIDDLEDATA()
    {
        NODE<T> *P = FIRST, *Q = P;
        while (Q)
        {
            Q = Q->NEXT;
            if (Q)
                Q = Q->NEXT;
            if (Q)
                P = P->NEXT;
        }
        return P->DATA;
    }

};

template <class T>
void RDISP(NODE<T> *P)
{
    if (P)
    {
        cout << P->DATA << "  ";
        RDISP(P->NEXT);
    }
}

template <class T>
int RLength(NODE<T> *P)
{
    if (P)
        return RLength(P->NEXT) + 1;
    else
        return 0;
}

template <class T>
T RSUM(NODE<T> *P)
{
    if (!P)
        return 0;
    else
        return RSUM(P->NEXT) + P->DATA;
}

template <class T>
T RMAX(NODE<T> *P)
{
    T X;
    if (!P)
        return -12345;
    X = RMAX(P->NEXT);

    if (X > P->DATA)
        return X;
    else
        return P->DATA;
}

template <class T>
T RMIN(NODE<T> *P)
{  
    T X;
    if (!P)
        return 123456;
    X = RMIN(P->NEXT);

    if (X < P->DATA)
        return X;
    else
        return P->DATA;
}

int main()
{
    // int ARR[5] = {2, 4, 6, 8, 10};
    // LINKEDLIST<int> LIST1(ARR, 5);
    // cout << endl;
    // cout << "LIST ONE ";
    // LIST1.Display();
    // cout << endl;
    // cout << "LIST ONE USING RECURSION ";
    // RDISP(LIST1.GETFI());
    // cout << endl;
    // cout << "LENGTH OF LIST ONE IS " << LIST1.Length();
    // cout << endl;
    // cout << "LENGTH OF LIST ONE USING RECURSION " << RLength(LIST1.GETFI());
    // cout << endl;
    // cout << "SUM OF LIST ONE " << LIST1.SUM();
    // cout << endl;
    // cout << "SUM OF LIST ONE USING RECURSION " << RSUM(LIST1.GETFI());
    // cout << endl;
    // cout << "MAX ELEMENT IS  " << LIST1.MAX();
    // cout << endl;
    // cout << "MIN ELEMENT IS  " << LIST1.MIN();
    // cout << endl;
    // cout << "MAX ELEMENT USING RECURSION  IS  " << RMAX(LIST1.GETFI());
    // cout << endl;
    // cout << "MIN ELEMENT USING RECURSION  IS  " << RMIN(LIST1.GETFI());
    // cout << endl;
    // cout << "ELEMENT   " << LIST1.SEARCH(4);
    // cout << endl;
    // cout << "LIST AFTER INSERTING AT ( 0 / 1 )";
    // LIST1.Insert(0, 1);
    // LIST1.Display();
    // cout << endl;
    // cout << "LIST AFTER INSERTING AT ( 3 / 3 )";
    // LIST1.Insert(3, 3);
    // LIST1.Display();
    // cout << endl;
    // cout << "LIST AFTER INSERTING AT ( 7 / 12 )";
    // LIST1.Insert(6, 12);
    // LIST1.Display();
    // cout << endl;
    // cout << endl;

    // LINKEDLIST<int> LIST2;
    // LIST2.Insert(0, 1);
    // LIST2.Insert(1, 3);
    // LIST2.Insert(2, 5);
    // LIST2.Insert(3, 7);
    // LIST2.Insert(4, 9);
    // LIST2.Insert(5, 11);
    // cout << endl;
    // cout << "LIST TWO ";
    // LIST2.Display();
    // cout << endl;
    // cout << "LIST TWO USING RECURSION ";
    // RDISP(LIST2.GETFI());
    // cout << endl;
    // cout << "LENGTH OF LIST TWO IS " << LIST2.Length();
    // cout << endl;
    // cout << "LENGTH OF LIST TWO USING RECURSION " << RLength(LIST2.GETFI());
    // cout << endl;
    // cout << "SUM OF LIST TWO " << LIST2.SUM();
    // cout << endl;
    // cout << "SUM OF LIST TWO USING RECURSION " << RSUM(LIST2.GETFI());
    // cout << endl;
    // cout << "MAX ELEMENT IS  " << LIST2.MAX();
    // cout << endl;
    // cout << "MIN ELEMENT IS  " << LIST2.MIN();
    // cout << endl;
    // cout << "MAX ELEMENT USING RECURSION  IS  " << RMAX(LIST2.GETFI());
    // cout << endl;
    // cout << "MIN ELEMENT USING RECURSION  IS  " << RMIN(LIST2.GETFI());
    // cout << endl;
    // cout << "ELEMENT   " << LIST2.SEARCH(9);
    // cout << endl;
    // cout << "LIST AFTER INSERTING ( 4 ) IN SORTED LIST ";
    // LIST2.SORTINSERT(4);
    // LIST2.Display();
    // cout << endl;
    // cout << "DELETING ELEMENT AT INDEX 2 IS :- " << LIST2.Delete(2, LIST2.Length());
    // cout << endl;
    // cout << "LIST AFTER DELETING ELEMENT AT INDEX 2 :- ";
    // LIST2.Display();
    // cout << endl;
    // cout << "LIST AFTER REVERSING LIST BY HELP OF ARRAY IS ";
    // LIST2.REVERSE1();
    // LIST2.Display();
    // cout << endl;
    // cout << "LIST AFTER REVERSING LIST BY REVERSING LINKS IS  ";
    // LIST2.REVERSE2();
    // LIST2.Display();
    // cout << endl;
    // cout << "LIST AFTER REVERSING LIST BY RECURSION REVERSING LINKS IS  ";
    // LIST2.REVERSE3();
    // LIST2.Display();
    // cout << endl;
    // cout << endl;

    // LINKEDLIST<int> LIST3;
    // cout << "LIST1 AND LIST2 ARE MERGED IN SORTED WAY ";
    // LIST3.MERGESORT(LIST1.GETFI(),LIST2.GETFI());
    // LIST3.Display();

    // int ARR[5] = {2, 4, 6, 8, 10};
    // LINKEDLIST<int> LIST4(ARR, 5);
    // cout << endl;
    // cout << "LIST ONE ";
    // LIST4.Display();
    // cout << endl;
    // cout << "MIDDLE ELEMENT OF THE LIST IS ";
    // cout << LIST4.MIDDLEDATA();
    // cout << endl;

    return 0;
}