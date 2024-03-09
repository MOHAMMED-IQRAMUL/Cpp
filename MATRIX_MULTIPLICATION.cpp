#include <bits/stdc++.h>
using namespace std;

class MAT
{
    int matrix1[3][3];

public:
    MAT() {}
    friend istream &operator>>(istream &IN, MAT &M1)
    {
        cout << "Enter  : \n";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                IN >> M1.matrix1[i][j];
            }
        }
        return IN;
    }
    friend ostream &operator<<(ostream &OUT, const MAT &M1)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                OUT << M1.matrix1[i][j] << "\t";
            }
            OUT << endl;
        }
        return OUT;
    }
    MAT operator*(MAT M2)
    {
        MAT M3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                M3.matrix1[i][j] = 0;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    M3.matrix1[i][j] += matrix1[i][k] * M2.matrix1[k][j];
                }
            }
        }
        return M3;
    }
};

int main()
{
    // int r1, r2, r3, c1, c2, c3;
    // cout << "Enter Rows and Column of First and Second : ";
    // cin >> r1 >> c1 >> r2 >> c2;
    // r3 = r1, c3 = c2;
    // int matrix1[r1][c1];
    // int matrix2[r2][c2];
    // int matrix3[r3][c3];
    // cout << "Enter 1st : ";
    // for (int i = 0; i < r1; i++)
    // {
    //     for (int j = 0; j < c1; j++)
    //     {

    //         cin >> matrix1[i][j];
    //     }
    // }
    // cout << "Enter 2nd : ";
    // for (int i = 0; i < r2; i++)
    // {
    //     for (int j = 0; j < c2; j++)
    //     {

    //         cin >> matrix2[i][j];
    //     }
    // }
    // // 3rd
    // for (int i = 0; i < r2; i++)
    // {
    //     for (int j = 0; j < c2; j++)
    //     {

    //         matrix3[i][j] = 0;
    //     }
    // }

    // for (int i = 0; i < r1; i++)
    // {
    //     for (int j = 0; j < c2; j++)
    //     {
    //         for (int k = 0; k < r2; k++)
    //         {
    //             matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
    //         }
    //     }
    // }

    // for (int i = 0; i < r3; i++)
    // {
    //     for (int j = 0; j < c3; j++)
    //     {

    //         cout << matrix3[i][j] << "\t";
    //     }
    //     cout << endl;
    // }

    //////////////////////////////////
   
    // MAT M1, M2, M3;
    // cin >> M1;
    // cin >> M2;
    // M3 = M1 * M2;
    // cout << M3;

    return 0;
}