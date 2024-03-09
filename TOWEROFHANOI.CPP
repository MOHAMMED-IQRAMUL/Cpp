#include <bits/stdc++.h>
using namespace std;

void TOH(int N, int A, int B, int C)
{
    static int i = 0;
    if (N > 0)
    {

        TOH(N - 1, A, C, B);

        i++;
        cout << i << ". MOVE FROM " << A << " TO " << C << "  (" << A << " , " << C << " ) \n";
        TOH(N - 1, B, A, C);
    }
}

int main()
{
    TOH(3, 1, 2, 3);
    return 0;
}