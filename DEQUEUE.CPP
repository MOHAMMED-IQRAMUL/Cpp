#include <bits/stdc++.h>
using namespace std;

class DEQUEUE_USING_ARRAY
{
private:
    int front;
    int rear;
    int size;
    int *Q;

public:
    DEQUEUE_USING_ARRAY(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        Q = new int[size];
    }

    ~DEQUEUE_USING_ARRAY()
    {
        delete[] Q;
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (rear == size - 1)
        {
            return true;
        }
        return false;
    }

    void enqueueFront(int x)
    {
        if (front == -1)
        {
            cout << "DEQueue Overflow" << endl;
        }
        else
        {
            Q[front] = x;
            front--;
        }
    }

    void enqueueRear(int x)
    {
        if (isFull())
        {
            cout << "DEQueue Overflow" << endl;
        }
        else
        {
            rear++;
            Q[rear] = x;
        }
    }

    int dequeueFront()
    {
        int x = -1;
        if (isEmpty())
        {
            cout << "DEQueue Underflow" << endl;
        }
        else
        {
            x = Q[front];
            front++;
        }
        return x;
    }

    int dequeueRear()
    {
        int x = -1;
        if (rear == -1)
        {
            cout << "DEQueue Underflow" << endl;
        }
        else
        {
            x = Q[rear];
            rear--;
        }
        return x;
    }

    void display()
    {
        for (int i = front + 1; i <= rear; i++)
        {
            cout << Q[i] << flush;
            if (i < rear)
            {
                cout << " <- " << flush;
            }
        }
        cout << endl;
    }
};

class NODE
{
public:
    int data;
    NODE *next;
};

class DEQUEUE_USING_LINKEDLIST
{
 NODE* front;
    NODE* rear;
public:
     
 
 DEQUEUE_USING_LINKEDLIST() {
    front = nullptr;
    rear = nullptr;
}
 
void  enqueue(int x) {
    NODE* t = new NODE;
    if (t == nullptr){
        cout << "Queue Overflow" << endl;
    } else {
        t->data = x;
        t->next = nullptr;
        if (front == nullptr){
            front = t;
            rear = t;
        } else {
            rear->next = t;
            rear = t;
        }
    }
}
 
int  dequeue() {
    int x = -1;
    NODE* p;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}
 
bool isEmpty() {
    if (front == nullptr){
        return true;
    }
    return false;
}
 
 ~DEQUEUE_USING_LINKEDLIST() {
    NODE* p = front;
    while (front){
        front = front->next;
        delete p;
        p = front;
    }
}
 
void  display() {
    NODE* p = front;
    while (p){
        cout << p->data << flush;
        p = p->next;
        if (p != nullptr){
            cout << " <- " << flush;
        }
    }
    cout << endl;
}
};


int main()
{
    // int A[] = {1, 3, 5, 7, 9};
    // int B[] = {2, 4, 6, 8}; 
    // DEQUEUE_USING_ARRAY deq(sizeof(A) / sizeof(A[0])); 
    // for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    // {
    //     deq.enqueueRear(A[i]);
    // }
    // deq.display();
    // deq.enqueueRear(11); 
    // for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    // {
    //     deq.dequeueFront();
    // }
    // deq.dequeueFront(); 
    // cout << endl; 
    // for (int i = 0; i < sizeof(B) / sizeof(B[0]); i++)
    // {
    //     deq.enqueueFront(B[i]);
    // }
    // deq.display();
    // deq.enqueueFront(10);
    // deq.enqueueFront(12); 
    // for (int i = 0; i < sizeof(B) / sizeof(B[0]); i++)
    // {
    //     deq.dequeueRear();
    // }
    // deq.display();
    // deq.dequeueRear();
    // deq.dequeueRear();

cout << "\n/////////////////////////////////\n";
//     int A1[] = {1, 3, 5, 7, 9};
//    DEQUEUE_USING_LINKEDLIST q;
//     for (int i=0; i<sizeof(A)/sizeof(A1[0]); i++){
//         q.enqueue(A1[i]);
//     } 
//     q.display(); 
//     for (int i=0; i<sizeof(A1)/sizeof(A1[0]); i++){
//         q.dequeue();
//     }
//     q.dequeue();
    
    
    return 0;
}