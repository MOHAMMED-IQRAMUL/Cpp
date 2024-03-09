#include <bits/stdc++.h>
using namespace std;

double E1(int X, int N)
{
    static double F = 1, P = 1;
    double R;
    if (N == 0)
    {
        return 1;
    }
    else
    {
        R = E1(X, N - 1);
        P = P * X;
        F = F * N;
        return R + (P / F);
    }
}

double E2(int X, int N)
{
    double s = 1, NUM = 1, DEN = 1;
    for (int i = 1; i <= N; i++)
    {
        NUM *= X;
        DEN *= i;
        s += NUM / DEN;
    }
    return s;
}

double E3(int X, int N)
{
    static double S = 1;
    if (N == 0)
    {
        return S;
    }
    else
    {
        S = 1 + ((X * S / N));
        return E2(X, N - 1);
    }
}

double E4(int X, int N)
{
    double s = 1;
    for (; N > 0; N--)
    {
        s = 1 + ((X * s / N));
    }
    return s;
}
int FIB1(int N)
{
    if (N == 0 || N == 1)
        return N;

    return FIB1(N - 2) + FIB1(N - 1);
}

int FIB2(int N)
{
    int T0 = 0, T1 = 1, S, I;
    if (N == 0 || N == 1)
        return N;

    for (I = 2; I <= N; I++)
    {
        S = T0 + T1;
        T0 = T1;
        T1 = S;
    }
    return S;
}

int F[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int FIB3(int N)
{

    if (N == 0 || N == 1)
    {
        F[N] = N;
        return N;
    }

    else
    {
        if (F[N - 2] == -1)
            F[N - 2] = FIB3(N - 2);

        if (F[N - 1] == -1)
            F[N - 1] = FIB3(N - 1);
        F[N] = F[N - 2] + F[N - 1];
        return F[N - 2] + F[N - 1];
    }
}

double NCR1(int N, int R)
{
    if (R == 0 || N == R)
        return 1;

    return NCR1(N - 1, R - 1) + NCR1(N - 1, R );
}

int fact(int n)
{
 if(n==0)return 1;
 return fact(n-1)*n;
}
double NCR2(int n,int r)
{
 int num,den;
 
 num=fact(n);
 den=fact(r)*fact(n-r);
 
 return num/den;
}

int main()
{
    // cout << "DIRECT METHOD  e^X (2,10) = " << E1(2, 10) << endl;
    // cout << "DIRECT METHOD USING LOOP e^X (2,10) = " << E2(2, 10) << endl;
    // cout << "HORNER RULE METHOD e^X (2,10) = " << E3(2, 10) << endl;
    // cout << "HORNER RULE LOOP METHOD e^X (2,10) = " << E4(2, 10) << endl;

    // cout << "FIBONACCHI SERIES DIRECT METHOD (6) " << FIB1(6) << endl;
    // cout << "FIBONACCHI SERIES DIRECT METHOD USING LOOP (6) " << FIB2(6) << endl;
    // cout << "FIBONACCHI SERIES MEMORIZATION METHOD (6) " << FIB3(6) << endl;

    // cout << "COMBINATION NCR USING DIRECT MEHOD (6,4) " << NCR1(6, 4) << endl;
    // cout << "COMBINATION NCR USING LOOP MEHOD (6,4) " << NCR2(6, 4) << endl;

    return 0;
}