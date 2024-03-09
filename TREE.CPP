#include <bits/stdc++.h>
using namespace std;

class NODE
{
public:
    NODE *LCHILD;
    int DATA;
    NODE *RCHILD;
};

class TREE
{
private:
    NODE *ROOT;

public:
    TREE()
    {
        ROOT = new NODE;

        ROOT->LCHILD = ROOT->RCHILD = nullptr;
    }

    void CREATE()
    {
        NODE *P, *T;
        int X;
        queue<NODE *> Q;
        cout << "ENTER ROOT VALUE ";
        cin >> X;
        ROOT->DATA = X;
        ROOT->LCHILD = ROOT->RCHILD = nullptr;

        Q.push(ROOT);
        while (!Q.empty())
        {
            P = Q.front();
            Q.pop();
            cout << "ENTER LEFT CHILD OF " << P->DATA << "  ";
            cin >> X;
            if (X != -1)
            {
                T = new NODE;
                T->DATA = X;
                T->LCHILD = T->RCHILD = nullptr;
                P->LCHILD = T;
                Q.emplace(T);
            }

            cout << "ENTER RIGHT CHILD OF " << P->DATA << "  ";
            cin >> X;
            if (X != -1)
            {
                T = new NODE;
                T->DATA = X;
                T->LCHILD = T->RCHILD = nullptr;
                P->RCHILD = T;
                Q.emplace(T);
            }
        }
    }

    void RPREORDER() { RPREORDER(ROOT); }
    void RPREORDER(NODE *P)
    {
        if (P)
        {
            cout << P->DATA << "  ";
            RPREORDER(P->LCHILD);
            RPREORDER(P->RCHILD);
        }
    }

    void RINORDER() { RINORDER(ROOT); }
    void RINORDER(NODE *P)
    {
        if (P)
        {
            RINORDER(P->LCHILD);
            cout << P->DATA << "  ";
            RINORDER(P->RCHILD);
        }
    }

    void RPOSTORDER() { RPOSTORDER(ROOT); }
    void RPOSTORDER(NODE *P)
    {
        if (P)
        {
            RPOSTORDER(P->LCHILD);
            RPOSTORDER(P->RCHILD);
            cout << P->DATA << "  ";
        }
    }
    void QLEVELORDER() { QLEVELORDER(ROOT); }
    void QLEVELORDER(NODE *P)
    {

        queue<NODE *> Q;
        cout << P->DATA << "  ";
        Q.emplace(P);
        while (!Q.empty())
        {
            P = Q.front();
            Q.pop();
            if (P->LCHILD)
            {
                cout << P->LCHILD->DATA << "  ";
                Q.push(P->LCHILD);
            }
            if (P->RCHILD)
            {
                cout << P->RCHILD->DATA << "  ";
                Q.push(P->RCHILD);
            }
        }
    }

    int RHEIGHT() { RHEIGHT(ROOT); }
    int RHEIGHT(NODE *P)
    {
        int X = 0, Y = 0;
        if (!P)
            return 0;

        X = RHEIGHT(P->LCHILD);

        Y = RHEIGHT(P->RCHILD);
        if (X > Y)
            return X + 1;
        else
            return Y + 1;
    }

    int COUNT1() { COUNT1(ROOT); }
    int COUNT1(NODE *P)
    {
        if (P)
            return COUNT1(P->LCHILD) + COUNT1(P->RCHILD) + 1;
        return 0;
    }

    int COUNT2() { COUNT2(ROOT); }
    int COUNT2(NODE *P)
    {
        int X, Y;
        if (P)
        {
            X = COUNT2(P->LCHILD);
            Y = COUNT2(P->RCHILD);
            return X + Y + 1;
        }
        return 0;
    }

    int SUM() { SUM(ROOT); }
    int SUM(NODE *P)
    {
        int X, Y;
        if (P)
        {
            X = SUM(P->LCHILD);
            Y = SUM(P->RCHILD);
            return X + Y + P->DATA;
        }
        return 0;
    }

    void SPREORDER()
    {
        NODE *P = ROOT;
        stack<NODE *> STK;
        while (P || !STK.empty())
        {
            if (P)
            {
                cout << P->DATA << "  ";
                STK.emplace(P);
                P = P->LCHILD;
            }
            else
            {
                P = STK.top();
                STK.pop();

                P = P->RCHILD;
            }
        }
    }

    void SINORDER()
    {
        NODE *P = ROOT;
        stack<NODE *> STK;
        while (P || !STK.empty())
        {
            if (P)
            {

                STK.emplace(P);
                P = P->LCHILD;
            }
            else
            {
                P = STK.top();
                STK.pop();
                cout << P->DATA << "  ";
                P = P->RCHILD;
            }
        }
    }

    void SPOSTORDER()
    {
        NODE *P = ROOT;
        stack<long int> STK;
        long int TEMP;
        while (P || !STK.empty())
        {
            if (P)
            {
                STK.emplace((long int)P);
                P = P->LCHILD;
            }
            else
            {
                TEMP = STK.top();
                STK.pop();
                if (TEMP > 0)
                {
                    STK.emplace(-TEMP);
                    P = ((NODE *)TEMP)->RCHILD;
                }
                else
                {
                    cout << ((NODE *)(-1 * TEMP))->DATA;
                    P = NULL;
                }
            }
        }
    }

    int searchInorder(int inArray[], int inStart, int inEnd, int data)
    {
        for (int i = inStart; i <= inEnd; i++)
        {
            if (inArray[i] == data)
            {
                return i;
            }
        }
        return -1;
    }
    NODE *GENERATE_TREE(int *inorder, int *preorder, int inStart, int inEnd)
    {
        static int preIndex = 0;

        if (inStart > inEnd)
        {
            return nullptr;
        }

        NODE *node = new NODE;
        node->LCHILD = nullptr;
        node->DATA = (preorder[preIndex++]);
        node->RCHILD = nullptr;

        if (inStart == inEnd)
        {
            return node;
        }

        int splitIndex = searchInorder(inorder, inStart, inEnd, node->DATA);
        node->LCHILD = GENERATE_TREE(inorder, preorder, inStart, splitIndex - 1);
        node->RCHILD = GENERATE_TREE(inorder, preorder, splitIndex + 1, inEnd);

        return node;
    }

    ~TREE()
    {
        DestroyTree(ROOT);
    }
    void DestroyTree(NODE *p)
    {
        if (p != nullptr)
        {
            DestroyTree(p->LCHILD);
            DestroyTree(p->RCHILD);
            delete p;
        }
    }
};
int main()
{

 {   TREE T1;

    cout << endl;
    T1.CREATE();
    cout << endl
         << "TREE LEVEL ORDER ";
    T1.QLEVELORDER();
    cout << endl
         << "TREE RECURSIVE PRE ORDER ";
    T1.RPREORDER();
    cout << endl
         << "TREE RECURSIVE IN ORDER ";
    T1.RINORDER();
    cout << endl
         << "TREE RECURSIVE POST ORDER ";
    T1.RPOSTORDER();
    cout << endl
         << "TREE ITERATIVE PRE ORDER ";
    T1.SPREORDER();
    cout << endl
         << "TREE ITERATIVE IN ORDER ";
    T1.SINORDER();
    cout << endl
         << "TREE ITERATIVE POST ORDER ";
    T1.SPOSTORDER();

    cout << endl
         << "HEIGHT OF TREE IS  "
         << T1.RHEIGHT();
    cout << endl
         << "TOTAL NUMBER OF NODES IS "
         << T1.COUNT1();
    cout << endl
         << "TOTAL NUMBER OF NODES IS "
         << T1.COUNT2();
    cout << endl
         << "SUM OF THE ELEMENTS OF TREE  "
         << T1.SUM();

    int PRE[] = {1, 2, 4, 5, 9, 3, 6, 7, 8}, IN[] = {4, 2, 9, 5, 1, 6, 3, 7, 8}, POST[] = {4, 9, 5, 2, 6, 8, 7, 3, 1};
    TREE T2;
    NODE *T3;
    cout << endl
         << "GENERATING TREE FROM PREORDER AND INORDER TANSVERSAL ";
    T3 = T2.GENERATE_TREE(IN, PRE, 0, 9);
    cout << endl
         << "TREE LEVEL ORDER DISPLAY ";
    T2.QLEVELORDER(T3);}
    return 0;
}