#include <bits/stdc++.h>
using namespace std;

class QUEUE_USING_ARRAY
{
    int SIZE, FRONT, REAR;
    int *Q;

public:
    QUEUE_USING_ARRAY()
    {
        SIZE = 10;
        FRONT = REAR = -1;
        Q = new int[SIZE];
    }
    QUEUE_USING_ARRAY(int N)
    {
        SIZE = N;
        FRONT = REAR = -1;
        Q = new int[SIZE];
    }
    void ENQUEUE(int X)
    {
        if (REAR == (SIZE - 1))
        {
            cout << "QUEUE OVERFLOW ";
        }
        else
        {
            REAR++;
            Q[REAR] = X;
        }
    }
    int DEQUEUE()
    {
        if (REAR == FRONT)
        {
            cout << "QUEUE UNDERFLOW ";
            return -1;
        }
        else
        {
            int X;
            FRONT++;
            X = Q[FRONT];
            return X;
        }
    }

    void DISPLAY()
    {
        for (int I = FRONT + 1; I <= REAR; I++)
            cout << Q[I] << "  ";
    }
};

class CIRCLE_QUEUE_USING_ARRAY
{
    int SIZE, FRONT, REAR;
    int *Q;

public:
    CIRCLE_QUEUE_USING_ARRAY()
    {
        SIZE = 10;
        FRONT = REAR = 0;
        Q = new int[SIZE];
    }
    CIRCLE_QUEUE_USING_ARRAY(int N)
    {
        SIZE = N;
        FRONT = REAR = 0;
        Q = new int[SIZE];
    }
    void ENQUEUE(int X)
    {
        if (((REAR + 1) % SIZE) == FRONT)
        {
            cout << "QUEUE OVERFLOW ";
        }
        else
        {
            REAR = (REAR + 1) % SIZE;
            Q[REAR] = X;
        }
    }
    int DEQUEUE()
    {
        if (REAR == FRONT)
        {
            cout << "QUEUE UNDERFLOW ";
            return -1;
        }
        else
        {
            int X;
            FRONT = (FRONT + 1) % SIZE;
            X = Q[FRONT];
            return X;
        }
    }

    void DISPLAY()
    {
        int I = FRONT + 1;
        do
        {
            cout << Q[I] << "  ";
            I = (I + 1) % SIZE;
        } while (I != ((REAR + 1) % SIZE));
    }
};

class NODE
{
public:
    int data;
    NODE *next;
};

class QUEUE_USING_LINKEDLIST
{
    NODE *front;
    NODE *rear;

public:
    QUEUE_USING_LINKEDLIST()
    {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int x)
    {
        NODE *t = new NODE;
        if (t == nullptr)
        {
            cout << "Queue Overflow" << endl;
        }
        else
        {
            t->data = x;
            t->next = nullptr;
            if (front == nullptr)
            {
                front = t;
                rear = t;
            }
            else
            {
                rear->next = t;
                rear = t;
            }
        }
    }

    int dequeue()
    {
        int x = -1;
        NODE *p;
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
        }
        else
        {
            p = front;
            front = front->next;
            x = p->data;
            delete p;
        }
        return x;
    }

    bool isEmpty()
    {
        if (front == nullptr)
        {
            return true;
        }
        return false;
    }

    void display()
    {
        NODE *p = front;
        while (p)
        {
            cout << p->data << flush;
            p = p->next;
            if (p != nullptr)
            {
                cout << " <- " << flush;
            }
        }
        cout << endl;
    }
};

class CIRCLE_QUEUE_USING_2STACK
{
    stack<int> e_stk;
    stack<int> d_stk;

public:
    void enqueue(int x)
    {
        e_stk.push(x);
    }

    int dequeue()
    {
        int x = -1;
        if (d_stk.empty())
        {
            if (e_stk.empty())
            {
                cout << "Queue Underflow" << endl;
                return x;
            }
            else
            {
                while (!e_stk.empty())
                {
                    d_stk.push(e_stk.top());
                    e_stk.pop();
                }
            }
        }
        x = d_stk.top();
        d_stk.pop();
        return x;
    }
};
int main()
{

    // QUEUE_USING_ARRAY QA1(5);
    // QA1.ENQUEUE(2);
    // QA1.ENQUEUE(4);
    // QA1.ENQUEUE(6);
    // QA1.ENQUEUE(8);
    // QA1.ENQUEUE(10);
    // QA1.DISPLAY();
    // QA1.ENQUEUE(10);
    // cout << endl
    //      << QA1.DEQUEUE() << endl;
    // QA1.DISPLAY();
    // cout << endl;

    // CIRCLE_QUEUE_USING_ARRAY QA12(6);
    // QA12.ENQUEUE(2);
    // QA12.ENQUEUE(4);
    // QA12.ENQUEUE(6);
    // QA12.ENQUEUE(8);
    // QA12.ENQUEUE(10);
    // QA12.DISPLAY();
    // QA12.ENQUEUE(10);
    // cout << endl
    //      << QA12.DEQUEUE() << endl;
    // QA12.DISPLAY();

    // QUEUE_USING_LINKEDLIST QL1;
    // QL1.enqueue(1);
    // QL1.enqueue(3);
    // QL1.enqueue(5);
    // QL1.enqueue(7);
    // QL1.enqueue(9);
    // QL1.enqueue(11);
    // QL1.display();
    // cout << endl;
    // cout << QL1.dequeue();
    // cout << endl;
    // QL1.display();

    // CIRCLE_QUEUE_USING_2STACK QL1;
    // QL1.enqueue(1);
    // QL1.enqueue(3);
    // QL1.enqueue(5);
    // QL1.enqueue(7);
    // QL1.enqueue(9);
    // QL1.enqueue(11);
    // for (int I = 0; I < 6; I++)
    //     cout << QL1.dequeue() << "  ";

    return 0;
}