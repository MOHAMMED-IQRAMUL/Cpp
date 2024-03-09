#include <bits/stdc++.h>
using namespace std;

void PRINT(int Arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << Arr[i] << "  ";
    cout << endl;
}

void SWAP(int &A, int &B)
{
    int TEMP = A;
    A = B;
    B = TEMP;
}

int Max(int A[], int n)
{
    int max = -32768;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

void INSERTIONSORT_YT(int Arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int current = Arr[i];
        int j = i - 1;
        while (Arr[j] > current && j >= 0)
        {
            Arr[j + 1] = Arr[j];
            j--;
        }
        Arr[j + 1] = current;
    }
}
void SELECTIONSORT_YT(int Arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (Arr[j] < Arr[i])
            {
                int temp = Arr[j];
                Arr[j] = Arr[i];
                Arr[i] = temp;
            }
        }
    }
}
void BUBBLESORT_YT(int Arr[], int n)
{
    int count = 0;
    while (count < n - 1)
    {
        for (int i = 0; i < n - count - 1; i++)
        {
            if (Arr[i] > Arr[i + 1])
            {
                int temp = Arr[i + 1];
                Arr[i + 1] = Arr[i];
                Arr[i] = temp;
            }
        }
        count++;
    }
}

void INSERTIONSORT_UD(int Arr[], int n)
{
    int x;
    for (int i = 1; i < n; i++)
    {
        x = Arr[i];
        int j = i - 1;
        while (Arr[j] > x && j > -1)
        {
            Arr[j + 1] = Arr[j];
            j--;
        }
        Arr[j + 1] = x;
    }
}
void SELECTIONSORT_UD(int Arr[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (Arr[j] < Arr[k])
                k = j;
        }
        SWAP(Arr[i], Arr[k]);
    }
}
void BUBBLESORT_UD(int Arr[], int n)
{
    int FLAG = 0;
    for (int i = 0; i < n; i++)
    {
        FLAG = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (Arr[j] > Arr[j + 1])
            {
                SWAP(Arr[j], Arr[j + 1]);
                FLAG = 1;
            }
        }
        if (FLAG == 0)
            break;
    }
}

int Partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;

    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);

        if (i < j)
            SWAP(A[i], A[j]);
    } while (i < j);

    SWAP(A[l], A[j]);
    return j;
}
void QuickSort(int A[], int l, int h)
{
    int j;

    if (l < h)
    {
        j = Partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}

void Merge1(int A[], int B[], int C[], int m, int n)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = B[j++];
        }
    }
    for (; i < m; i++)
        C[k++] = A[i];
    for (; j < n; j++)
        C[k++] = B[j];
    // while (i < m){
    //     C[k++] = A[i++];
    // }
    // while (j < n){
    //     C[k++] = A[j++];
    // }
}
void Merge(int A[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[high + 1];
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }
    while (i <= mid)
    {
        B[k++] = A[i++];
    }
    while (j <= high)
    {
        B[k++] = A[j++];
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}
void IterativeMergeSort1(int A[], int n)
{
    int p;
    for (p = 2; p <= n; p = p * 2)
    {
        for (int i = 0; i + p - 1 < n; i = i + p)
        {
            int low = i;
            int high = i + p - 1;
            int mid = (low + high) / 2;
            Merge(A, low, mid, high);
        }
    }
    if (p / 2 < n)
    {
        Merge(A, 0, p / 2 - 1, n - 1);
    }
}
void IterativeMergeSort2(int A[], int n)
{
    int p, l, h, mid, i;
    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(A, l, mid, h);
        }
        if (n - i > p / 2)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(A, l, mid, n - 1);
        }
    }
    if (p / 2 < n)
    {
        Merge(A, 0, p / 2 - 1, n - 1);
    }
}
void RecursiveMergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        // int mid = (low + (high - low)) / 2;
        int mid = (low + (high)) / 2;
        RecursiveMergeSort(A, low, mid);
        RecursiveMergeSort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}

void CountSort(int A[], int n)
{
    int max = Max(A, n);
    int *count = new int[max + 1];
    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[A[i]]++;
    }
    int i = 0;
    int j = 0;
    while (j < max + 1)
    {
        if (count[j] > 0)
        {
            A[i++] = j;
            count[j]--;
        }
        else
        {
            j++;
        }
    }
    delete[] count;
}

class Node
{
public:
    int value;
    Node *next;
};
void Insert(Node **ptrBins, int idx)
{
    Node *temp = new Node;
    temp->value = idx;
    temp->next = nullptr;
    if (ptrBins[idx] == nullptr)
    {
        ptrBins[idx] = temp;
    }
    else
    {
        Node *p = ptrBins[idx];
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = temp;
    }
}
int Delete(Node **ptrBins, int idx)
{
    Node *p = ptrBins[idx];
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}
void BinSort(int A[], int n)
{
    int max = Max(A, n);
    Node **bins = new Node *[max + 1];
    for (int i = 0; i < max + 1; i++)
    {
        bins[i] = nullptr;
    }
    for (int i = 0; i < n; i++)
    {
        Insert(bins, A[i]);
    }
    int i = 0;
    int j = 0;
    while (i < max + 1)
    {
        while (bins[i] != nullptr)
        {
            A[j++] = Delete(bins, i);
        }
        i++;
    }
    delete[] bins;
}

int countDigits(int x)
{
    int count = 0;
    while (x != 0)
    {
        x = x / 10;
        count++;
    }
    return count;
}
void initializeBins(Node **p, int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = nullptr;
    }
}
int getBinIndex(int x, int idx)
{
    return (int)(x / pow(10, idx)) % 10;
}
void Insert(Node **ptrBins, int value, int idx)
{
    Node *temp = new Node;
    temp->value = value;
    temp->next = nullptr;
    if (ptrBins[idx] == nullptr)
    {
        ptrBins[idx] = temp;
    }
    else
    {
        Node *p = ptrBins[idx];
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = temp;
    }
}
void RadixSort(int A[], int n)
{
    int max = Max(A, n);
    int nPass = countDigits(max);
    Node **bins = new Node *[10];
    initializeBins(bins, 10);
    for (int pass = 0; pass < nPass; pass++)
    {
        for (int i = 0; i < n; i++)
        {
            int binIdx = getBinIndex(A[i], pass);
            Insert(bins, A[i], binIdx);
        }
        int i = 0;
        int j = 0;
        while (i < 10)
        {
            while (bins[i] != nullptr)
            {
                A[j++] = Delete(bins, i);
            }
            i++;
        }
        initializeBins(bins, 10);
    }
    delete[] bins;
}

void ShellSort(int A[], int n)
{
    for (int gap = n / 2; gap >= 1; gap /= 2)
    {
        for (int j = gap; j < n; j++)
        {
            int temp = A[j];
            int i = j - gap;
            while (i >= 0 && A[i] > temp)
            {
                A[i + gap] = A[i];
                i = i - gap;
            }
            A[i + gap] = temp;
        }
    }
}

int main()
{
    {
        int A1[10] = {2, 3, 4, 5, 9, 87, 6, 5, 43, 2}, A2[10] = {2, 3, 4, 5, 9, 87, 6, 5, 43, 2}, A3[10] = {2, 3, 4, 5, 9, 87, 6, 5, 43, 2};

        INSERTIONSORT_YT(A1, 10);
        PRINT(A1, 10);
        SELECTIONSORT_YT(A2, 10);
        PRINT(A2, 10);
        BUBBLESORT_YT(A3, 10);
        PRINT(A3, 10);
    }
        cout << endl;

{
        int A1[10] = {2, 3, 4, 5, 9, 87, 6, 5, 43, 2};

        QuickSort(A1, 0,10);
        PRINT(A1, 10); 
    }
    cout << endl;

    {
        int A1[10] = {2, 3, 4, 5, 9, 87, 6, 5, 43, 2},
            A2[10] = {2, 3, 4, 5, 9, 87, 6, 5, 43, 2},
            A3[10] = {2, 3, 4, 5, 9, 87, 6, 5, 43, 2},
            A4[10] = {2, 3, 4, 5, 9, 87, 6, 5, 43, 2};

        INSERTIONSORT_UD(A1, 10);
        PRINT(A1, 10);
        SELECTIONSORT_UD(A2, 10);
        PRINT(A2, 10);
        BUBBLESORT_UD(A3, 10);
        PRINT(A3, 10);
        QuickSort(A4, 0, 10);
        PRINT(A4, 10);
    }

    cout << endl;

    {
        int A[5] = {1, 3, 5, 7, 9},
            B[5] = {2, 4, 6, 8, 10},
            C[11],
            D[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
        Merge1(A, B, C, 5, 5);
        PRINT(C, 10);
        Merge(D, 0, 4, 10);
        PRINT(D, 10);
        cout << endl;
        int A1[10] = {9, 1, 2, 5, 8, 3, 6, 3, 4, 7},
            A2[10] = {9, 1, 2, 5, 8, 3, 6, 3, 4, 7};
        IterativeMergeSort1(A1, 10);
        PRINT(A1, 10);
        IterativeMergeSort2(A2, 10);
        PRINT(A2, 10);
        cout << endl;
        int A3[10] = {1, 3, 5, 9, 6, 7, 8, 2, 4, 10},
            A4[13] = {9, 1, 2, 5, 8, 3, 6, 3, 4, 7, 10, 2, 1};
        RecursiveMergeSort(A3, 0, 9);
        PRINT(A3, 10);
        RecursiveMergeSort(A4, 0, 12);
        PRINT(A4, 13);
    }

    cout << endl;

    {
        int A1[10] = {9, 7, 5, 3, 1, 2, 4, 6, 8, 10},
            A2[11] = {12, 9, 7, 5, 3, 1, 2, 4, 6, 8, 10};
        CountSort(A1, 10);
        PRINT(A1, 10);
        CountSort(A2, 11);
        PRINT(A2, 11);
    }

    cout << endl;

    {
        int A1[10] = {9, 7, 5, 3, 1, 2, 4, 6, 8, 4},
            A2[11] = {12, 3, 7, 5, 3, 1, 2, 4, 6, 8, 10};
        BinSort(A1, 10);
        PRINT(A1, 10);
        BinSort(A2, 11);
        PRINT(A2, 11);
    }

    cout << endl;

    {
        int A1[10] = {9, 7, 5, 3, 1, 2, 4, 6, 8, 4},
            A2[11] = {111, 999, 888, 665, 434, 134, 764, 257, 343, 786, 34},
            A3[10] = {
                9999,
                333,
                5555,
                674,
                246,
                12,
                6,
                257,
                876,
                3456,
            };
        RadixSort(A1, 10);
        PRINT(A1, 10);
        RadixSort(A2, 11);
        PRINT(A2, 11);
        RadixSort(A3, 10);
        PRINT(A3, 10);
    }

    cout << endl;

    {
        int A1[10] = {9, 7, 5, 3, 1, 2, 4, 6, 8, 4},
            A2[11] = {12, 3, 7, 5, 3, 1, 2, 4, 6, 8, 10},
            A3[13] = {1, 3, 4, 33, 76, 32, 21, 78, 24, 31, 64, 9, 80};
        ShellSort(A1, 10);
        PRINT(A1, 10);
        ShellSort(A2, 11);
        PRINT(A2, 11);
        ShellSort(A3, 13);
        PRINT(A3, 13);
    }

    return 0;
}