#include <iostream>
using namespace std;

class NODE
{
public:
    int COLUMN;
    int VALUE;
    NODE *NEXT;
};

class SPARSEMATRIX
{
    // int M;
    NODE *A[5];

public:
    SPARSEMATRIX()
    {
        for (int i = 0; i < 5; i++)
        {
            A[i] = new NODE; 
        }
    }
    void CREATE()
    {
        for (int i = 0; i < 5; i++)
        {

            cout << "ENTER MATRIX NON ZERO ELEMENTS COLUMN/ELEMENT FOR ROW NUMBER " << i << "  ";
            cin >> A[i]->COLUMN >> A[i]->VALUE; 
        }
    }
    void DISP()
    {
        NODE *P = new NODE;
        for (int i = 0; i < 5; i++)
        {
            P = A[i];
            for (int J = 0; J < 5; J++)
            {
                if (J == P->COLUMN)
                {
                    cout << P->VALUE << "  ";
                    // P = P->NEXT;
                }
                else
                    cout << "0  ";
            }
            
                    cout <<endl;
        }
    }
};

int main()
{
    SPARSEMATRIX S1;
    S1.CREATE();
    S1.DISP();
}