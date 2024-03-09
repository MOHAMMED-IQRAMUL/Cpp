#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, PAIRSS = 0;
    cout << "enter n ";
    cin >> n;
    vector<int> ARR(n);
    cout << "Enter " << n << " Elements ";
    for (int i = 0; i < n; i++)
    {
        cin >> ARR[i];
    }

    map<int, int> PAIR;

    for (int j = 0; j < n; j++)
    {
        PAIR[ARR[j]]++;
    }
    for (auto FIST : PAIR)
    {
        PAIRSS += FIST.second / 2;
    }

    cout << endl
         << "******************/n";
    cout << endl
         << "*********  " << PAIRSS << "  *********/n";
    cout << endl
         << "******************/n";

    int PAIRSSSS = 0;
    for (int k = 0; k < n; k++)
    {
        PAIRSSSS += PAIR[k] / 2;
    }

    cout << endl
         << "******************/n";
    cout << endl
         << "*********  " << PAIRSSSS << "  *********/n";
    cout << endl
         << "******************/n";
    return 0;
}