#include <bits/stdc++.h>
using namespace std;
class NODE
{
public:
    int Data;
    NODE *Next;
};

class CHAINING_HASH
{
    NODE **HT;

public:
    CHAINING_HASH() {}
    CHAINING_HASH(int KEY)
    {
        HT = new NODE *[10];
        for (int i = 0; i < 10; i++)
            HT[i] = nullptr;
    }
    int HASH(int Key) { return Key % 10; }
    void INSERT(int key)
    {
        int hidx = HASH(key);
        NODE *t = new NODE;
        t->Data = key;
        t->Next = nullptr;
        if (HT[hidx] == NULL)
            HT[hidx] = t;
        else
        {
            NODE *p = HT[hidx];
            NODE *q = HT[hidx];
            while (p && p->Data < key)
            {
                q = p;
                p = p->Next;
            }
            if (q == HT[hidx])
            {
                t->Next = q->Next;
                q->Next = t;
            }
        }
    }
    int SEARCH(int Key)
    {
        int hidx = HASH(Key);
        NODE *p = HT[hidx];
        while (p)
        {
            if (p->Data == Key)
                return p->Data;
            p = p->Next;
        }
        return -1;
    }
    ~CHAINING_HASH()
    {
        for (int i = 0; i < 10; i++)
        {
            NODE *p = HT[i];
            while (HT[i])
            {
                HT[i] = HT[i]->Next;
                delete p;
                p = HT[i];
            }
        }
        delete[] HT;
    }
};

class LINEAR_PROBE_HASH
{
    int SIZE;
    int *H;

public:
    LINEAR_PROBE_HASH()
    {
        SIZE = 10;
        H = new int[10];
        for (int i = 0; i < 10; i++)
            H[i] = 0;
    }
    int Hash(int key)
    {
        return key % SIZE;
    }
    void Print()
    {
        cout << endl;
        for (int i = 0; i < 10; i++)
            cout << H[i] << "  ";
    }
    int LinearProbe(int H[], int key)
    {
        int idx = Hash(key);
        int i = 0;
        while (H[(idx + i) % SIZE] != 0)
        {
            i++;
        }
        return (idx + i) % SIZE;
    }
    void INSERT(int key)
    {
        int idx = Hash(key);

        if (H[idx] != 0)
        {
            idx = LinearProbe(H, key);
        }
        H[idx] = key;
    }
    int SEARCH(int key)
    {
        int idx = Hash(key);
        int i = 0;
        // while (H[(idx + i) % SIZE] != key)
        while (H[Hash(idx + i)] != key)
        {
            i++;
            // if (H[(idx + i) % SIZE] == 0)
            if (H[Hash(idx + i)] == 0)
            {
                return -1;
            }
        }
        // return Hash((idx + i) % SIZE);
        return Hash(idx + i);
    }
};

class QUADRATIC_PROBE_HASH
{
    int SIZE;
    int *H;

public:
    QUADRATIC_PROBE_HASH()
    {
        SIZE = 10;
        H = new int[10];
        for (int i = 0; i < 10; i++)
            H[i] = 0;
    }
    void Print()
    {
        cout << endl;
        for (int i = 0; i < 10; i++)
            cout << H[i] << "  ";
    }
    int Hash(int key)
    {
        return key % SIZE;
    }
    int QuadraticProbe(int key)
    {
        int idx = Hash(key);
        int i = 0;
        while (H[(idx + i * i) % SIZE] != 0)
        {
            i++;
        }
        return (idx + i * i) % SIZE;
    }
    void INSERT(int key)
    {
        int idx = Hash(key);

        if (H[idx] != 0)
        {
            idx = QuadraticProbe(key);
        }
        H[idx] = key;
    }
    int SEARCH(int key)
    {
        int idx = Hash(key);
        int i = 0;
        while (H[(idx + i * i) % SIZE] != key)
        {
            i++;
            if (H[(idx + i * i) % SIZE] == 0)
            {
                return -1;
            }
        }
        return (idx + i * i) % SIZE;
    }
};

class DOUBLE_HASHING
{
    int SIZE, PRIME;
    int *H;

public:
    DOUBLE_HASHING()
    {
        SIZE = 10;
        PRIME = 7;
        H = new int[10];
        for (int i = 0; i < 10; i++)
            H[i] = 0;
    }
    void Print()
    {
        cout << endl;
        for (int i = 0; i < 10; i++)
            cout << H[i] << "  ";
    }
    int Hash(int key)
    {
        return key % SIZE;
    }
    int PrimeHash(int key)
    {
        return PRIME - (key % PRIME);
    }
    int DoubleHash(int key)
    {
        int idx = Hash(key);
        int i = 0;
        while (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] != 0)
        {
            i++;
        }
        return (idx + i * PrimeHash(idx)) % SIZE;
    }
    void INSERT(int key)
    {
        int idx = Hash(key);

        if (H[idx] != 0)
        {
            idx = DoubleHash(key);
        }
        H[idx] = key;
    }
    int SEARCH(int key)
    {
        int idx = Hash(key);
        int i = 0;
        while (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] != key)
        {
            i++;
            if (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] == 0)
            {
                return -1;
            }
        }
        return (Hash(idx) + i * PrimeHash(idx)) % SIZE;
    }
};

int main()
{
    {
        CHAINING_HASH H1(1);
        H1.INSERT(16);
        H1.INSERT(122);
        H1.INSERT(12);
        H1.INSERT(5);
        H1.INSERT(25);
        H1.INSERT(68);
        H1.INSERT(39);
        H1.INSERT(75);
        H1.INSERT(6);
        int VL = H1.SEARCH(25);
        cout << endl
             << "SEARCHING FOR ELEMENT 25 " << VL << "  ";
        VL = H1.SEARCH(15);
        cout << endl
             << "SEARCHING FOR ELEMENT 15 " << VL << "  ";
    }
    cout << endl;
    {
        LINEAR_PROBE_HASH H1;
        H1.INSERT(26);
        H1.INSERT(30);
        H1.INSERT(45);
        H1.INSERT(23);
        H1.INSERT(25);
        H1.INSERT(43);

        H1.INSERT(74);
        H1.INSERT(19);
        H1.INSERT(29);
        H1.Print();
        int VL = H1.SEARCH(25);
        cout << endl
             << "SEARCHING FOR ELEMENT 25 " << VL << "  ";
        VL = H1.SEARCH(15);
        cout << endl
             << "SEARCHING FOR ELEMENT 15 " << VL << "  ";
    }
    cout << endl;
    {
        QUADRATIC_PROBE_HASH H1;
        H1.INSERT(23);
        H1.INSERT(43);
        H1.INSERT(13);
        H1.INSERT(27);
        H1.Print();
        int VL = H1.SEARCH(23);
        cout << endl
             << "SEARCHING FOR ELEMENT 23 " << VL << "  ";
        VL = H1.SEARCH(15);
        cout << endl
             << "SEARCHING FOR ELEMENT 15 " << VL << "  ";
    }
    cout << endl;
    {
        DOUBLE_HASHING H1;
        H1.INSERT(5);
        H1.INSERT(25);
        H1.INSERT(15);
        H1.INSERT(35);
        H1.INSERT(95);
        H1.Print();
        int VL = H1.SEARCH(25);
        cout << endl
             << "SEARCHING FOR ELEMENT 25 " << VL << "  ";
        VL = H1.SEARCH(12);
        cout << endl
             << "SEARCHING FOR ELEMENT 12 " << VL << "  ";
    }

    return 0;
}