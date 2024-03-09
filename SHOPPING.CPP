#include <bits/stdc++.h>
using namespace std;
class items
{
};
int main()
{
    string ITEMS[10] =
        {
            "BURGER", "FRENCH-FRIES", "PIZZA", "BROAST", "BRIYANI", "CORMA", "MILK", "TEA", "COFEE", "WATER"};
    int PRICE[10] =
        {
            10, 20, 30, 40, 50, 50, 15, 20, 25, 10};
    vector<int> arr;
    int TOTAL = 0, A = 0, P = 0;

    cout << "SELECT ITEMS \n";
    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << "  " << ITEMS[i] << "  PRICE " << PRICE[i] << " $ " << endl;
    }
    cout << "PRESS 101 WHEN DONE SHOPPING ";
    cout << endl
         << endl;

    while (cin >> A && A != 101 && P < 10)
    {
        arr.push_back(A);
        TOTAL += PRICE[A - 1];

        P++;
    }

    cout << "YOUR ITEMS " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << i + 1 << "  " << ITEMS[arr[i] - 1] << "  PRICE " << PRICE[arr[i] - 1] << " $\n";
    }
    cout << "YOUR TOTAL IS " << TOTAL << " $ \n";

    return 0;
}