#include <bits/stdc++.h>
using namespace std;
class DIAGONAL
{
    int N;
    int *M;

public:
    DIAGONAL() {}
    DIAGONAL(int N)
    {
        this->N = N;
        M = new int[N];
    }
    ~DIAGONAL()
    {
        delete[] M;
    }
    int GET(int I, int J)
    {
        if (I == J)
            return M[I - 1];
        else
            return 0;
    }
    void SET(int I, int J, int K)
    {
        if (I == J)
            M[I - 1] = K;
    }
    void DISP()
    {
        cout << endl;
        for (int I = 1; I <= N; I++)
        {
            for (int J = 1; J <= N; J++)
            {
                if (I == J)
                    cout << M[I - 1] << "  ";
                else
                    cout << "0  ";
            }
            cout << endl;
        }
    }
};
class LOWER_TRIANGLE1
{
    int N;
    int *M;

public:
    LOWER_TRIANGLE1() {}
    LOWER_TRIANGLE1(int N)
    {
        this->N = N;
        M = new int[(N * (N - 1)) / 2];
    }
    ~LOWER_TRIANGLE1()
    {
        delete[] M;
    }
    int GET(int I, int J)
    {
        if (I >= J)
            return M[((I * (I - 1)) / 2 + (J - 1))];
        else
            return 0;
    }
    void SET(int I, int J, int K)
    {
        if (I >= J)
            M[((I * (I - 1)) / 2 + (J - 1))] = K;
    }
    void DISP()
    {
        cout << endl;
        for (int I = 1; I <= N; I++)
        {
            for (int J = 1; J <= N; J++)
            {
                if (I >= J)
                    cout << M[((I * (I - 1)) / 2 + (J - 1))] << "  ";
                else
                    cout << "0  ";
            }
            cout << endl;
        }
    }
};
class LOWER_TRIANGLE2
{
    int N;
    int *M;

public:
    LOWER_TRIANGLE2() {}
    LOWER_TRIANGLE2(int N)
    {
        this->N = N;
        M = new int[(N * (N - 1)) / 2];
    }
    ~LOWER_TRIANGLE2()
    {
        delete[] M;
    }
    int GET(int I, int J)
    {
        if (I >= J)
            return M[((N * (J - 1)) - (((J - 2) * (J - 1)) / 2) + (I - J))];
        else
            return 0;
    }
    void SET(int I, int J, int K)
    {
        if (I >= J)
            M[((N * (J - 1)) - (((J - 2) * (J - 1)) / 2) + (I - J))] = K;
    }
    void DISP()
    {
        cout << endl;
        for (int I = 1; I <= N; I++)
        {
            for (int J = 1; J <= N; J++)
            {
                if (I >= J)
                    cout << M[((N * (J - 1)) - (((J - 2) * (J - 1)) / 2) + (I - J))] << "  ";
                else
                    cout << "0  ";
            }
            cout << endl;
        }
    }
};
class UPPER_TRIANGLE1
{
    int N;
    int *M;

public:
    UPPER_TRIANGLE1() {}
    UPPER_TRIANGLE1(int N)
    {
        this->N = N;
        M = new int[(N * (N + 1)) / 2];
    }
    ~UPPER_TRIANGLE1()
    {
        delete[] M;
    }
    int GET(int I, int J)
    {
        if (I <= J)
            return M[((N * (I - 1)) - (((I - 2) * (I - 1)) / 2) + (J - I))];
        else
            return 0;
    }
    void SET(int I, int J, int K)
    {
        if (I <= J)
            M[((N * (I - 1)) - (((I - 2) * (I - 1)) / 2) + (J - I))] = K;
    }
    void DISP()
    {
        cout << endl;
        for (int I = 1; I <= N; I++)
        {
            for (int J = 1; J <= N; J++)
            {
                if (I <= J)
                    cout << M[((N * (I - 1)) - (((I - 2) * (I - 1)) / 2) + (J - I))] << "  ";
                else
                    cout << "00  ";
            }
            cout << endl;
        }
    }
};
class UPPER_TRIANGLE2
{
    int N;
    int *M;

public:
    UPPER_TRIANGLE2() {}
    UPPER_TRIANGLE2(int N)
    {
        this->N = N;
        M = new int[(N * (N + 1)) / 2];
    }
    ~UPPER_TRIANGLE2()
    {
        delete[] M;
    }
    int GET(int I, int J)
    {
        if (I <= J)
            return M[(((J * (J - 1)) / 2) + (I - 1))];
        else
            return 0;
    }
    void SET(int I, int J, int K)
    {
        if (I <= J)
            M[(((J * (J - 1)) / 2) + (I - 1))] = K;
    }
    void DISP()
    {
        cout << endl;
        for (int I = 1; I <= N; I++)
        {
            for (int J = 1; J <= N; J++)
            {
                if (I <= J)
                    cout << M[(((J * (J - 1)) / 2) + (I - 1))] << "  ";
                else
                    cout << "00  ";
            }
            cout << endl;
        }
    }
};
class SYMMETRIC
{
    int N;
    int *M;

public:
    SYMMETRIC() {}
    SYMMETRIC(int N)
    {
        this->N = N;
        M = new int[(N * (N + 1)) / 2];
    }
    ~SYMMETRIC()
    {
        delete[] M;
    }
    int GET(int I, int J)
    {
        if (I >= J)
            return M[((I * (I - 1)) / 2 + (J - 1))];
        else
            return M[((J * (J - 1)) / 2 + (I - 1))];
    }
    void SET(int I, int J, int K)
    {
        if (I >= J)
            M[((I * (I - 1)) / 2 + (J - 1))] = K;
        else if (J > I)
            M[((J * (J - 1)) / 2 + (I - 1))] = K;
    }
    void DISP()
    {
        cout << endl;
        for (int I = 1; I <= N; I++)
        {
            for (int J = 1; J <= N; J++)
            {
                if (I >= J)
                    cout << M[((I * (I - 1)) / 2 + (J - 1))] << "  ";
                else
                    cout << M[((J * (J - 1)) / 2 + (I - 1))] << "  ";
            }
            cout << endl;
        }
    }
};
class TRIDIAGONAL
{
    int N;
    int *M;

public:
    TRIDIAGONAL() {}
    TRIDIAGONAL(int N)
    {
        this->N = N;
        M = new int[(3 * N) - 2];
    }
    ~TRIDIAGONAL()
    {
        delete[] M;
    }
    int GET(int I, int J)
    {
        if ((I - J) == 0)
            return M[I - 2];
        else if ((I - J) == 1)
            return M[(N - 1) + (I - 1)];
        else if ((I - J) == -1)
            return M[((2 * N) - 1) + (I - 1)];
        else
            return 0;
    }
    void SET(int I, int J, int K)
    {
        if ((I - J) == 0)
            M[I - 2] = K;
        else if ((I - J) == 1)
            M[(N - 1) + (I - 1)] = K;
        else if ((I - J) == -1)
            M[((2 * N) - 1) + (I - 1)] = K;
    }
    void DISP()
    {
        cout << endl;
        for (int I = 1; I <= N; I++)
        {
            for (int J = 1; J <= N; J++)
            {
                if (I == J)
                    cout << M[I - 2] << "  ";

                else if ((I - J) == 1)
                    cout << M[(N - 1) + (I - 1)] << "  ";
                else if ((I - J) == -1)
                    cout << M[((2 * N) - 1) + (I - 1)] << "  ";

                else
                    cout << "0  ";
            }
            cout << endl;
        }
    }
};
class TOEPLITZ
{
    int N;
    int *M;

public:
    TOEPLITZ() {}
    TOEPLITZ(int N)
    {
        this->N = N;
        M = new int[(N + (N - 1))];
    }
    ~TOEPLITZ()
    {
        delete[] M;
    }
    int GET(int I, int J)
    {
        if (I <= J)
            return M[J - I];
        else if (I > J)
            return M[N + (I - J - 1)];
    }
    void SET(int I, int J, int K)
    {
        if (I <= J)
            M[J - I] = K;
        else if (I > J)
            M[N + (I - J - 1)] = K;
    }
    void DISP()
    {
        cout << endl;
        for (int I = 1; I <= N; I++)
        {
            for (int J = 1; J <= N; J++)
            {
                if (I <= J)
                    cout << M[J - I] << "  ";
                else if (I > J)
                    cout << M[N + (I - J - 1)] << "  ";
            }
            cout << endl;
        }
    }
};
int main()
{
    // DIAGONAL D1(4), D2(5);

    // for (int i = 1; i <= 4; i++)
    // {
    //     for (int j = 1; j <= 4; j++)
    //     {
    //         int EL;
    //         cin >> EL;
    //         D1.SET(i, j, EL);
    //     }
    // }
    // D1.DISP();

    // D2.SET(1, 1, 11); D2.SET(2, 2, 12); D2.SET(3, 3, 13); D2.SET(4, 4, 14); D2.SET(5, 5, 15); cout << D2.GET(1, 1) << "  ";
    // cout << D2.GET(2, 2) << "  ";cout << D2.GET(3, 3) << "  ";cout << D2.GET(4, 4) << "  ";cout << D2.GET(5, 5) << "  ";D2.DISP();

    // LOWER_TRIANGLE1 L1(4), L2(5);

    // for (int i = 1; i <= 4; i++)
    // {
    //     for (int j = 1; j <= 4; j++)
    //     {
    //         int EL;
    //         cin >> EL;
    //         L1.SET(i, j, EL);
    //     }
    // }
    // L1.DISP();

    // L2.SET(1, 1, 10);  L2.SET(2, 1, 21);  L2.SET(2, 2, 20);  L2.SET(3, 1, 31);  L2.SET(3, 2, 32);
    // L2.SET(3, 3, 30);  L2.SET(4, 1, 41);  L2.SET(4, 2, 42);  L2.SET(4, 3, 43);  L2.SET(4, 4, 40);
    // L2.SET(5, 1, 51);  L2.SET(5, 2, 52);  L2.SET(5, 3, 53);  L2.SET(5, 4, 54);  L2.SET(5, 5, 50);
    // cout << L2.GET(1, 1) << "  ";  cout << L2.GET(2, 1) << "  ";  cout << L2.GET(2, 2) << "  ";  cout << L2.GET(3, 1) << "  ";
    // cout << L2.GET(3, 2) << "  ";  cout << L2.GET(3, 3) << "  ";  cout << L2.GET(4, 1) << "  ";  cout << L2.GET(4, 2) << "  ";
    // cout << L2.GET(4, 3) << "  ";  cout << L2.GET(4, 4) << "  ";  cout << L2.GET(5, 1) << "  ";  cout << L2.GET(5, 2) << "  ";
    // cout << L2.GET(5, 3) << "  ";  cout << L2.GET(5, 4) << "  ";  cout << L2.GET(5, 5) << "  ";
    // L2.DISP();

    //    LOWER_TRIANGLE2 L1(4), L2(5);

    // for (int i = 1; i <= 4; i++)
    // {
    //     for (int j = 1; j <= 4; j++)
    //     {
    //         int EL;
    //         cin >> EL;
    //         L1.SET(i, j, EL);
    //     }
    // }
    // L1.DISP();

    // L2.SET(1, 1, 10);  L2.SET(2, 1, 21);  L2.SET(2, 2, 20);  L2.SET(3, 1, 31);  L2.SET(3, 2, 32);
    // L2.SET(3, 3, 30);  L2.SET(4, 1, 41);  L2.SET(4, 2, 42);  L2.SET(4, 3, 43);  L2.SET(4, 4, 40);
    // L2.SET(5, 1, 51);  L2.SET(5, 2, 52);  L2.SET(5, 3, 53);  L2.SET(5, 4, 54);  L2.SET(5, 5, 50);
    // cout << L2.GET(1, 1) << "  ";  cout << L2.GET(2, 1) << "  ";  cout << L2.GET(2, 2) << "  ";  cout << L2.GET(3, 1) << "  ";
    // cout << L2.GET(3, 2) << "  ";  cout << L2.GET(3, 3) << "  ";  cout << L2.GET(4, 1) << "  ";  cout << L2.GET(4, 2) << "  ";
    // cout << L2.GET(4, 3) << "  ";  cout << L2.GET(4, 4) << "  ";  cout << L2.GET(5, 1) << "  ";  cout << L2.GET(5, 2) << "  ";
    // cout << L2.GET(5, 3) << "  ";  cout << L2.GET(5, 4) << "  ";  cout << L2.GET(5, 5) << "  ";
    // L2.DISP();

    // UPPER_TRIANGLE1 L1(4), L2(5);

    // for (int i = 1; i <= 4; i++)
    // {
    //     for (int j = 1; j <= 4; j++)
    //     {
    //         int EL;
    //         cin >> EL;
    //         L1.SET(i, j, EL);
    //     }
    // }
    // L1.DISP();

    // L2.SET(1, 1, 11);  L2.SET(1, 2, 12);  L2.SET(1, 3, 13);  L2.SET(1, 4, 14);  L2.SET(1, 5, 15);
    // L2.SET(2, 2, 22);  L2.SET(2, 3, 23);  L2.SET(2, 4, 24);  L2.SET(2, 5, 25);  L2.SET(3, 3, 33);
    // L2.SET(3, 4, 34);  L2.SET(3, 5, 35);  L2.SET(4, 4, 44);  L2.SET(4, 5, 45);  L2.SET(5, 5, 55);
    // cout << L2.GET(1, 1) << "  ";    cout << L2.GET(1, 2) << "  ";    cout << L2.GET(1, 3) << "  ";    cout << L2.GET(1, 4) << "  ";
    // cout << L2.GET(1, 5) << "  ";    cout << L2.GET(2, 2) << "  ";    cout << L2.GET(2, 3) << "  ";    cout << L2.GET(2, 4) << "  ";
    // cout << L2.GET(2, 5) << "  ";    cout << L2.GET(3, 3) << "  ";    cout << L2.GET(3, 4) << "  ";    cout << L2.GET(3, 5) << "  ";
    // cout << L2.GET(4, 4) << "  ";    cout << L2.GET(4, 5) << "  ";    cout << L2.GET(5, 5) << "  ";
    // L2.DISP();

    //    UPPER_TRIANGLE2 L1(4), L2(5);

    //     for (int i = 1; i <= 4; i++)
    //     {
    //         for (int j = 1; j <= 4; j++)
    //         {
    //             int EL;
    //             cin >> EL;
    //             L1.SET(i, j, EL);
    //         }
    //     }
    //     L1.DISP();

    //     L2.SET(1, 1, 11);  L2.SET(1, 2, 12);  L2.SET(1, 3, 13);  L2.SET(1, 4, 14);  L2.SET(1, 5, 15);
    //     L2.SET(2, 2, 22);  L2.SET(2, 3, 23);  L2.SET(2, 4, 24);  L2.SET(2, 5, 25);  L2.SET(3, 3, 33);
    //     L2.SET(3, 4, 34);  L2.SET(3, 5, 35);  L2.SET(4, 4, 44);  L2.SET(4, 5, 45);  L2.SET(5, 5, 55);
    //     cout << L2.GET(1, 1) << "  ";    cout << L2.GET(1, 2) << "  ";    cout << L2.GET(1, 3) << "  ";    cout << L2.GET(1, 4) << "  ";
    //     cout << L2.GET(1, 5) << "  ";    cout << L2.GET(2, 2) << "  ";    cout << L2.GET(2, 3) << "  ";    cout << L2.GET(2, 4) << "  ";
    //     cout << L2.GET(2, 5) << "  ";    cout << L2.GET(3, 3) << "  ";    cout << L2.GET(3, 4) << "  ";    cout << L2.GET(3, 5) << "  ";
    //     cout << L2.GET(4, 4) << "  ";    cout << L2.GET(4, 5) << "  ";    cout << L2.GET(5, 5) << "  ";
    //     L2.DISP();

    // SYMMETRIC S1(4), S2(5);

    // for (int i = 1; i <= 4; i++)
    // {
    //     for (int j = 1; j <= 4; j++)
    //     {
    //         int EL;
    //         cin >> EL;
    //         S1.SET(i, j, EL);
    //     }
    // }
    // S1.DISP();  cout << endl;

    // S2.SET(1, 1, 11);     S2.SET(2, 1, 22);     S2.SET(2, 2, 33);     S2.SET(3, 1, 44);     S2.SET(3, 2, 45);     S2.SET(3, 3, 22);
    // S2.SET(4, 1, 33);     S2.SET(4, 2, 44);     S2.SET(4, 3, 55);     S2.SET(4, 4, 33);     S2.SET(5, 1, 44);     S2.SET(5, 2, 55);
    // S2.SET(5, 3, 44);     S2.SET(5, 4, 55);     S2.SET(5, 5, 55);     cout << endl;
    // cout << S2.GET(1, 1) << "  ";    cout << S2.GET(1, 2) << "  ";    cout << S2.GET(1, 3) << "  ";    cout << S2.GET(1, 4) << "  ";
    // cout << S2.GET(1, 5) << "  ";    cout << S2.GET(2, 2) << "  ";    cout << S2.GET(2, 3) << "  ";    cout << S2.GET(2, 4) << "  ";
    // cout << S2.GET(2, 5) << "  ";    cout << S2.GET(3, 3) << "  ";    cout << S2.GET(3, 4) << "  ";    cout << S2.GET(3, 5) << "  ";
    // cout << S2.GET(4, 4) << "  ";    cout << S2.GET(4, 5) << "  ";    cout << S2.GET(5, 5) << "  ";    cout << endl;
    // S2.DISP();

    // TRIDIAGONAL T1(4), T2(5);

    // for (int i = 1; i <= 4; i++)
    // {
    //     for (int j = 1; j <= 4; j++)
    //     {
    //         int EL;
    //         cin >> EL;
    //         T1.SET(i, j, EL);
    //     }
    // }
    // T1.DISP();
    // cout << endl;

    //     T2.SET(1, 1, 1);  T2.SET(1, 2, 2);  T2.SET(2, 1, 1);  T2.SET(2, 2, 2);  T2.SET(2, 3, 3);  T2.SET(3, 2, 2);  T2.SET(3, 3, 3);
    //     T2.SET(3, 4, 4);  T2.SET(4, 3, 3);  T2.SET(4, 4, 4);  T2.SET(4, 5, 5);  T2.SET(5, 4, 4);  T2.SET(5, 5, 5);  cout << endl;
    //    cout << T2.GET(1, 1) <<"  " ;   cout << T2.GET(1, 2) <<"  " ;   cout << T2.GET(2, 1) <<"  " ;   cout << T2.GET(2, 2) <<"  " ;
    //    cout << T2.GET(2, 3) <<"  " ;   cout << T2.GET(3, 2) <<"  " ;   cout << T2.GET(3, 3) <<"  " ;   cout << T2.GET(3, 4) <<"  " ;
    //    cout << T2.GET(4, 3) <<"  " ;   cout << T2.GET(4, 4) <<"  " ;   cout << T2.GET(4, 5) <<"  " ;   cout << T2.GET(5, 4) <<"  " ;
    //    cout << T2.GET(5, 5) <<"  " ;   cout << endl;   T2.DISP();

    // TOEPLITZ T1(4), T2(6);

    // for (int i = 1; i <= 4; i++)
    // {
    //     for (int j = 1; j <= 4; j++)
    //     {
    //         int EL;
    //         cin >> EL;
    //         T1.SET(i, j, EL);
    //     }
    // }
    // T1.DISP();
    // cout << endl;

    // T2.SET(1, 1, 1);   T2.SET(1, 2, 2);   T2.SET(1, 3, 3);   T2.SET(1, 4, 4);   T2.SET(1, 5, 5);
    // T2.SET(2, 1, 6);   T2.SET(3, 1, 7);   T2.SET(4, 1, 8);   T2.SET(5, 1, 9);   cout << endl;
    // cout << T2.GET(1, 1) << "  ";   cout << T2.GET(1, 2) << "  ";   cout << T2.GET(1, 3) << "  ";   cout << T2.GET(1, 4) << "  ";
    // cout << T2.GET(1, 5) << "  ";   cout << T2.GET(2, 1) << "  ";   cout << T2.GET(3, 1) << "  ";   cout << T2.GET(4, 1) << "  ";
    // cout << T2.GET(5, 1) << "  ";   cout << endl; T2.DISP();

    return 0;
}