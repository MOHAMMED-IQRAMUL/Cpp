#include <bits/stdc++.h>
using namespace std;

class NODE
{
public:
    NODE *LCHILD;
    int DATA;
    NODE *RCHILD;
};

class BST
{

    NODE *ROOT;

public:
    BST()
    {
        ROOT = new NODE;

        ROOT = nullptr;
    }

    void RINORDER(NODE *P)
    {
        if (P)
        {
            RINORDER(P->LCHILD);
            cout << P->DATA << "  ";
            RINORDER(P->RCHILD);
        }
    }
    void RPOSTORDER(NODE *P)
    {
        if (P)
        {
            RPOSTORDER(P->LCHILD);
            RPOSTORDER(P->RCHILD);
            cout << P->DATA << "  ";
        }
    }

    NODE *GETROOT() { return ROOT; }

    void INSERT1(int KEY)
    {
        NODE *T = ROOT;
        NODE *R = nullptr, *P;
        if (!ROOT)
        {
            P = new NODE;
            P->DATA = KEY;
            P->LCHILD = nullptr ; P->RCHILD = nullptr;
            ROOT = P;
            return;
        }
        while (T)
        {
            R = T;
            if (KEY == T->DATA)
                return;
            else if (KEY < T->DATA)
                T = T->LCHILD;
            else
                T = T->RCHILD;
        }
        P = new NODE;
        P->DATA = KEY;
        P->LCHILD = nullptr; P->RCHILD = nullptr;
        if (P->DATA < R->DATA)
            R->LCHILD = P;
        else
            R->RCHILD = P;
    }

    NODE *RINSERT(NODE *P, int KEY)
    {
        NODE *T;
        if (!P)
        {
            T = new NODE;
            T->DATA = KEY;
            T->LCHILD = T->RCHILD = nullptr;
            return T;
        }
        if (KEY < P->DATA)
        {
            P->LCHILD = RINSERT(P->LCHILD, KEY);
        }
        else if (KEY > P->DATA)
        {
            P->RCHILD = RINSERT(P->RCHILD, KEY);
        }
        return P;
    }

    NODE *RSEARCH(NODE *T, int KEY)
    {
        if (!T)
            return NULL;

        if (KEY == T->DATA)
            return T;
        else if (KEY < T->DATA)
            return RSEARCH(T->LCHILD, KEY);
        else
            return RSEARCH(T->RCHILD, KEY);
    }

    NODE *ISEARCH(int KEY)
    {
        NODE *T = ROOT;
        while (T)
        {
            if (KEY == T->DATA)
                return T;
            else if (KEY < T->DATA)
                T = T->LCHILD;
            else
                T = T->RCHILD;

            return NULL;
        }
    }

    NODE *INPRE(NODE *P)
    {
        while (P && P->RCHILD)
            P = P->RCHILD;
        return P;
    }
    NODE *INSUCC(NODE *P)
    {
        while (P && P->LCHILD)
            P = P->LCHILD;
        return P;
    }
    int HEIGHT(NODE *P)
    {
        int x;
        int y;
        if (P == nullptr)
        {
            return 0;
        }
        x = HEIGHT(P->LCHILD);
        y = HEIGHT(P->RCHILD);
        return x > y ? x + 1 : y + 1;
    }
    NODE *DELETE(NODE *P, int KEY)
    {
        NODE *q;

        if (P == nullptr)
        {
            return nullptr;
        }

        if (P->LCHILD == nullptr && P->RCHILD == nullptr)
        {
            if (P == ROOT)
            {
                ROOT = nullptr;
            }
            delete P;
            return nullptr;
        }

        if (KEY < P->DATA)
        {
            P->LCHILD = DELETE(P->LCHILD, KEY);
        }
        else if (KEY > P->DATA)
        {
            P->RCHILD = DELETE(P->RCHILD, KEY);
        }
        else
        {
            if (HEIGHT(P->LCHILD) > HEIGHT(P->RCHILD))
            {
                q = INPRE(P->LCHILD);
                P->DATA = q->DATA;
                P->LCHILD = DELETE(P->LCHILD, q->DATA);
            }
            else
            {
                q = INSUCC(P->RCHILD);
                P->DATA = q->DATA;
                P->RCHILD = DELETE(P->RCHILD, q->DATA);
            }
        }
        return P;
    }

    void CREATE_BST_FROM_PRE(int pre[], int n)
    {
        int i = 0;
        ROOT = new NODE;
        ROOT->DATA = pre[i++];
        ROOT->LCHILD = nullptr;
        ROOT->RCHILD = nullptr;

        NODE *t;
        NODE *p = ROOT;
        stack<NODE *> stk;

        while (i < n)
        {
            if (pre[i] < p->DATA)
            {
                t = new NODE;
                t->DATA = pre[i++];
                t->LCHILD = nullptr;
                t->RCHILD = nullptr;
                p->LCHILD = t;
                stk.push(p);
                p = t;
            }
            else
            {
                if (pre[i] > p->DATA && pre[i] < stk.empty() ? 32767 : stk.top()->DATA)
                {
                    t = new NODE;
                    t->DATA = pre[i++];
                    t->LCHILD = nullptr;
                    t->RCHILD = nullptr;
                    p->RCHILD = t;
                    p = t;
                }
                else
                {
                    p = stk.top();
                    stk.pop();
                }
            }
        }
    }
};

int main()
{

    {
        BST TR1;

        TR1.INSERT1(30);
        TR1.INSERT1(20);
        TR1.INSERT1(10);
        TR1.INSERT1(3);
        TR1.INSERT1(4);
        TR1.INSERT1(25);
        TR1.INSERT1(22);
        TR1.INSERT1(27);
        TR1.INSERT1(50);
        TR1.INSERT1(35);
        TR1.INSERT1(40);
        TR1.INSERT1(55);

        cout << endl;
        TR1.RINORDER(TR1.GETROOT());
        cout << endl;
        TR1.RPOSTORDER(TR1.GETROOT());

        cout << "\nPERFORMING RECURIVE SEARCH TO FIND 20 ";
        NODE *PL1 = TR1.RSEARCH(TR1.GETROOT(), 20);
        PL1 ? cout << " FOUND " : cout << " NOT FOUND ";
        cout << "\nPERFORMING ITERATIVE SEARCH TO FIND 30 ";
        NODE *PL2 = TR1.ISEARCH(30);
        PL2 ? cout << " FOUND " : cout << " NOT FOUND ";
        cout << "\nPERFORMING RECURIVE SEARCH TO FIND 1 ";
        NODE *PL3 = TR1.RSEARCH(TR1.GETROOT(), 1);
        PL3 ? cout << " FOUND " : cout << " NOT FOUND ";
        cout << "\nPERFORMING ITERATIVE SEARCH TO FIND 2  ";
        NODE *PL4 = TR1.ISEARCH(2);
        PL4 ? cout << " FOUND " : cout << " NOT FOUND ";

        TR1.DELETE(TR1.GETROOT(), 10);
        cout << endl;
        TR1.RINORDER(TR1.GETROOT());

        TR1.DELETE(TR1.GETROOT(), 30);
        cout << endl;
        TR1.RINORDER(TR1.GETROOT());

        TR1.DELETE(TR1.GETROOT(), 20);
        cout << endl;
        TR1.RINORDER(TR1.GETROOT());

        TR1.DELETE(TR1.GETROOT(), 10);
        cout << endl;
        TR1.RINORDER(TR1.GETROOT());
    }
    cout << endl;
    cout << endl;
    {
        BST TR1;

        TR1.INSERT1(30);
        TR1.RINSERT(TR1.GETROOT(), 20);
        TR1.RINSERT(TR1.GETROOT(), 10);
        TR1.RINSERT(TR1.GETROOT(), 3);
        TR1.RINSERT(TR1.GETROOT(), 4);
        TR1.RINSERT(TR1.GETROOT(), 25);
        TR1.RINSERT(TR1.GETROOT(), 22);
        TR1.RINSERT(TR1.GETROOT(), 27);
        TR1.RINSERT(TR1.GETROOT(), 50);
        TR1.RINSERT(TR1.GETROOT(), 35);
        TR1.RINSERT(TR1.GETROOT(), 40);
        TR1.RINSERT(TR1.GETROOT(), 55);

        cout << endl;
        TR1.RINORDER(TR1.GETROOT());
        cout << endl;
        TR1.RPOSTORDER(TR1.GETROOT());

        cout << "\nPERFORMING RECURIVE SEARCH TO FIND 20 ";
        NODE *PL1 = TR1.RSEARCH(TR1.GETROOT(), 20);
        PL1 ? cout << " FOUND " : cout << " NOT FOUND ";
        cout << "\nPERFORMING ITERATIVE SEARCH TO FIND 30 ";
        NODE *PL2 = TR1.ISEARCH(30);
        PL2 ? cout << " FOUND " : cout << " NOT FOUND ";
        cout << "\nPERFORMING RECURIVE SEARCH TO FIND 1 ";
        NODE *PL3 = TR1.RSEARCH(TR1.GETROOT(), 1);
        PL3 ? cout << " FOUND " : cout << " NOT FOUND ";
        cout << "\nPERFORMING ITERATIVE SEARCH TO FIND 2  ";
        NODE *PL4 = TR1.ISEARCH(2);
        PL4 ? cout << " FOUND " : cout << " NOT FOUND ";

        TR1.DELETE(TR1.GETROOT(), 10);
        cout << endl;
        TR1.RINORDER(TR1.GETROOT());

        TR1.DELETE(TR1.GETROOT(), 30);
        cout << endl;
        TR1.RINORDER(TR1.GETROOT());

        TR1.DELETE(TR1.GETROOT(), 20);
        cout << endl;
        TR1.RINORDER(TR1.GETROOT());

        TR1.DELETE(TR1.GETROOT(), 10);
        cout << endl;
        TR1.RINORDER(TR1.GETROOT());
    }
    cout << endl;
    cout << endl;

    int PRE[] = {
        4, 3, 10, 22, 27, 25, 20, 40, 35, 55, 50, 30};
    BST TR3;
    TR3.CREATE_BST_FROM_PRE(PRE, 12);
    TR3.RINORDER(TR3.GETROOT());
    cout << endl;
    TR3.RPOSTORDER(TR3.GETROOT());
    return 0;
}