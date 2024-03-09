#include <bits/stdc++.h>
using namespace std;

class NODE
{
public:
    NODE *LCHILD;
    int DATA;
    int HEIGHT;
    NODE *RCHILD;
};

class AVL
{
public:
    NODE *ROOT;

public:
    AVL()
    {
        ROOT = new NODE;
        ROOT = NULL;
    }

    NODE *GETNODE()
    {
        return ROOT;
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

    void RPREORDER(NODE *P)
    {
        if (P)
        {
            cout << P->DATA << "  ";
            RPREORDER(P->LCHILD);
            RPREORDER(P->RCHILD);
        }
    }

    int NODEHEIGHT(NODE *P)
    {
        int HL, HR;
        HL = (P && P->LCHILD) ? P->LCHILD->HEIGHT : 0;
        HR = (P && P->RCHILD) ? P->RCHILD->HEIGHT : 0;

        return HL > HR ? HL + 1 : HR + 1;
    }

    int BALANCEFACTOR(NODE *P)
    {
        int HL, HR;
        HL = (P && P->LCHILD) ? P->LCHILD->HEIGHT : 0;
        HR = (P && P->RCHILD) ? P->RCHILD->HEIGHT : 0;

        return HL - HR;
    }

    NODE *LLROTATION(NODE *P)
    {
        NODE *PL = P->LCHILD;
        NODE *PLR = PL->RCHILD;

        PL->RCHILD = P;
        P->LCHILD = PLR;
        P->HEIGHT = NODEHEIGHT(P);
        PL->HEIGHT = NODEHEIGHT(PL);

        if (ROOT == P)
            ROOT = PL;

        return PL;
    }

    NODE *LRROTATION(NODE *P)
    {

        NODE *PL = P->LCHILD;
        NODE *PLR = PL->RCHILD;

        PL->RCHILD = PLR->LCHILD;
        P->LCHILD = PLR->RCHILD;

        PLR->LCHILD = PL;
        PLR->RCHILD = P;

        P->HEIGHT = NODEHEIGHT(P);
        PL->HEIGHT = NODEHEIGHT(PL);
        PLR->HEIGHT = NODEHEIGHT(PLR);

        if (ROOT == P)
            ROOT = PLR;

        return PLR;
    }

    NODE *RRROTATION(NODE *P)
    {
        NODE *PR = P->RCHILD;
        NODE *PRL = PR->LCHILD;

        PR->LCHILD = P;
        P->RCHILD = PRL;
        P->HEIGHT = NODEHEIGHT(P);
        PR->HEIGHT = NODEHEIGHT(PR);

        if (ROOT == P)
            ROOT = PR;

        return PR;
    }

    NODE *RLROTATION(NODE *P)
    {

        NODE *PR = P->RCHILD;
        NODE *PRL = PR->LCHILD;

        PR->LCHILD = PRL->RCHILD;
        P->RCHILD = PRL->LCHILD;

        PRL->RCHILD = PR;
        PRL->LCHILD = P;

        P->HEIGHT = NODEHEIGHT(P);
        PR->HEIGHT = NODEHEIGHT(PR);
        PRL->HEIGHT = NODEHEIGHT(PRL);

        if (ROOT == P)
            ROOT = PRL;

        return PRL;
    }

    NODE *RINSERT(NODE *P, int KEY)
    {
        NODE *T;
        if (!P)
        {
            T = new NODE;
            T->DATA = KEY;
            T->HEIGHT = 1;
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

        P->HEIGHT = NODEHEIGHT(P);

        if (BALANCEFACTOR(P) == 2 && BALANCEFACTOR(P) == 1)
            return LLROTATION(P);
        else if (BALANCEFACTOR(P) == 2 && BALANCEFACTOR(P) == -1)
            return LRROTATION(P);
        else if (BALANCEFACTOR(P) == -2 && BALANCEFACTOR(P) == 1)
            return RLROTATION(P);
        else if (BALANCEFACTOR(P) == -2 && BALANCEFACTOR(P) == -1)
            return RRROTATION(P);

        return P;
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

    NODE *DELETE_MY(NODE *P, int KEY)
    {
        if (P == NULL)
        {
            return NULL;
        }

        if (P->LCHILD == NULL && P->RCHILD == NULL)
        {
            if (P == ROOT)
            {
                ROOT = NULL;
            }
            delete P;
            return NULL;
        }

        if (KEY < P->DATA)
        {
            P->LCHILD = DELETE_MY(P->LCHILD, KEY);
        }
        else if (KEY > P->DATA)
        {
            P->RCHILD = DELETE_MY(P->RCHILD, KEY);
        }
        else
        {
            NODE *Q;
            if (NODEHEIGHT(P->LCHILD) > NODEHEIGHT(P->RCHILD))
            {
                Q = INPRE(P->LCHILD);
                P->DATA = Q->DATA;
                P->LCHILD = DELETE_MY(P->LCHILD, Q->DATA);
            }
            else
            {
                Q = INSUCC(P->RCHILD);
                P->DATA = Q->DATA;
                P->RCHILD = DELETE_MY(P->RCHILD, Q->DATA);
            }
        }

        // UPDATE HEIGHT
        P->HEIGHT = NODEHEIGHT(P);

        // BALANCE FACTOR AND ROTATION
        if (BALANCEFACTOR(P) == 2 && BALANCEFACTOR(P->LCHILD) == 1)
        { // L1 ROTATION
            return LLROTATION(P);
        }
        else if (BALANCEFACTOR(P) == 2 && BALANCEFACTOR(P->LCHILD) == -1)
        { // L-1 ROTATION
            return LRROTATION(P);
        }
        else if (BALANCEFACTOR(P) == -2 && BALANCEFACTOR(P->RCHILD) == -1)
        { // R-1 ROTATION
            return RRROTATION(P);
        }
        else if (BALANCEFACTOR(P) == -2 && BALANCEFACTOR(P->RCHILD) == 1)
        { // R1 ROTATION
            return RLROTATION(P);
        }
        else if (BALANCEFACTOR(P) == 2 && BALANCEFACTOR(P->LCHILD) == 0)
        { // L0 ROTATION
            return LLROTATION(P);
        }
        else if (BALANCEFACTOR(P) == -2 && BALANCEFACTOR(P->RCHILD) == 0)
        { // R0 ROTATION
            return RRROTATION(P);
        }

        return P;
    }

    NODE *DELETE_AI(NODE *P, int KEY)
    {
        if (P == NULL)
        {
            return NULL;
        }

        if (KEY < P->DATA)
        {
            P->LCHILD = DELETE_AI(P->LCHILD, KEY);
        }
        else if (KEY > P->DATA)
        {
            P->RCHILD = DELETE_AI(P->RCHILD, KEY);
        }
        else
        {
            if (P->LCHILD == nullptr || P->RCHILD == nullptr)
            {
                NODE *temp = P->LCHILD ? P->LCHILD : P->RCHILD;

                if (temp == nullptr)
                {
                    temp = P;
                    P = nullptr;
                }
                else
                {
                    *P = *temp;
                }

                delete temp;
            }
            else
            {
                NODE *temp = INPRE(P->LCHILD);
                P->DATA = temp->DATA;
                P->LCHILD = DELETE_AI(P->LCHILD, temp->DATA);
            }
        }

        if (P == nullptr)
        {
            return P;
        }

        P->HEIGHT = NODEHEIGHT(P);

        if (BALANCEFACTOR(P) == 2)
        {
            if (BALANCEFACTOR(P->LCHILD) >= 0)
            {
                return LLROTATION(P);
            }
            else
            {
                return LRROTATION(P);
            }
        }
        else if (BALANCEFACTOR(P) == -2)
        {
            if (BALANCEFACTOR(P->RCHILD) <= 0)
            {
                return RRROTATION(P);
            }
            else
            {
                return RLROTATION(P);
            }
        }

        return P;
    }

    NODE *Delete(NODE *p, int key)
    {
        if (p == nullptr)
        {
            return nullptr;
        }

        if (p->LCHILD == nullptr && p->RCHILD == nullptr)
        {
            if (p == ROOT)
            {
                ROOT = nullptr;
            }
            delete p;
            return nullptr;
        }

        if (key < p->DATA)
        {
            p->LCHILD = Delete(p->LCHILD, key);
        }
        else if (key > p->DATA)
        {
            p->RCHILD = Delete(p->RCHILD, key);
        }
        else
        {
            NODE *q;
            if (NODEHEIGHT(p->LCHILD) > NODEHEIGHT(p->RCHILD))
            {
                q = INPRE(p->LCHILD);
                p->DATA = q->DATA;
                p->LCHILD = Delete(p->LCHILD, q->DATA);
            }
            else
            {
                q = INSUCC(p->RCHILD);
                p->DATA = q->DATA;
                p->RCHILD = Delete(p->RCHILD, q->DATA);
            }
        }

        // Update height
        p->HEIGHT = NODEHEIGHT(p);

        // Balance Factor and Rotation
        if (BALANCEFACTOR(p) == 2 && BALANCEFACTOR(p->LCHILD) == 1)
        { // L1 Rotation
            return LLROTATION(p);
        }
        else if (BALANCEFACTOR(p) == 2 && BALANCEFACTOR(p->LCHILD) == -1)
        { // L-1 Rotation
            return LRROTATION(p);
        }
        else if (BALANCEFACTOR(p) == -2 && BALANCEFACTOR(p->RCHILD) == -1)
        { // R-1 Rotation
            return RRROTATION(p);
        }
        else if (BALANCEFACTOR(p) == -2 && BALANCEFACTOR(p->RCHILD) == 1)
        { // R1 Rotation
            return RLROTATION(p);
        }
        else if (BALANCEFACTOR(p) == 2 && BALANCEFACTOR(p->LCHILD) == 0)
        { // L0 Rotation
            return LLROTATION(p);
        }
        else if (BALANCEFACTOR(p) == -2 && BALANCEFACTOR(p->RCHILD) == 0)
        { // R0 Rotation
            return RRROTATION(p);
        }

        return p;
    }
};

int main()
{
    {
        AVL TR1;

        TR1.ROOT = TR1.RINSERT(TR1.GETNODE(), (30));
        TR1.ROOT = TR1.RINSERT(TR1.GETNODE(), (20));
        TR1.ROOT = TR1.RINSERT(TR1.GETNODE(), (10));
        TR1.ROOT = TR1.RINSERT(TR1.GETNODE(), (25));
        //    TR1.ROOT =  TR1.RINSERT(TR1.GETNODE(), (60));
        TR1.ROOT = TR1.RINSERT(TR1.GETNODE(), (40));
        TR1.ROOT = TR1.RINSERT(TR1.GETNODE(), (5));
        TR1.ROOT = TR1.RINSERT(TR1.GETNODE(), (4));
        //    TR1.ROOT =  TR1.RINSERT(TR1.GETNODE(), (65));
        cout << endl
             << endl;
        TR1.RINORDER(TR1.GETNODE());
        cout << endl
             << endl;
        TR1.RPREORDER(TR1.GETNODE());

        TR1.DELETE_MY(TR1.ROOT, 10);
        cout << endl
             << endl;

        TR1.RINORDER(TR1.GETNODE());
        cout << endl
             << endl;
        TR1.RPREORDER(TR1.GETNODE());
    }

    {
        AVL TR1;

        TR1.ROOT = TR1.RINSERT(TR1.GETNODE(), (30));
        TR1.ROOT = TR1.RINSERT(TR1.GETNODE(), (20));
        TR1.ROOT = TR1.RINSERT(TR1.GETNODE(), (10));
        TR1.ROOT = TR1.RINSERT(TR1.GETNODE(), (25));
        //    TR1.ROOT =  TR1.RINSERT(TR1.GETNODE(), (60));
        TR1.ROOT = TR1.RINSERT(TR1.GETNODE(), (40));
        TR1.ROOT = TR1.RINSERT(TR1.GETNODE(), (5));
        TR1.ROOT = TR1.RINSERT(TR1.GETNODE(), (4));
        //    TR1.ROOT =  TR1.RINSERT(TR1.GETNODE(), (65));
        cout << endl
             << endl;
        TR1.RINORDER(TR1.GETNODE());
        cout << endl
             << endl;
        TR1.RPREORDER(TR1.GETNODE());

        TR1.DELETE_AI(TR1.ROOT, 10);
        cout << endl
             << endl;

        TR1.RINORDER(TR1.GETNODE());
        cout << endl
             << endl;
        TR1.RPREORDER(TR1.GETNODE());
    }

    {
        AVL TR1;

        TR1.ROOT = TR1.RINSERT(TR1.GETNODE(), (30));
        TR1.ROOT = TR1.RINSERT(TR1.GETNODE(), (20));
        TR1.ROOT = TR1.RINSERT(TR1.GETNODE(), (10));
        TR1.ROOT = TR1.RINSERT(TR1.GETNODE(), (25));
        //    TR1.ROOT =  TR1.RINSERT(TR1.GETNODE(), (60));
        TR1.ROOT = TR1.RINSERT(TR1.GETNODE(), (40));
        TR1.ROOT = TR1.RINSERT(TR1.GETNODE(), (5));
        TR1.ROOT = TR1.RINSERT(TR1.GETNODE(), (4));
        //    TR1.ROOT =  TR1.RINSERT(TR1.GETNODE(), (65));
        cout << endl
             << endl;
        TR1.RINORDER(TR1.GETNODE());
        cout << endl
             << endl;
        TR1.RPREORDER(TR1.GETNODE());

        TR1.Delete(TR1.ROOT, 10);
        cout << endl
             << endl;

        TR1.RINORDER(TR1.GETNODE());
        cout << endl
             << endl;
        TR1.RPREORDER(TR1.GETNODE());
    }

    return 0;
}