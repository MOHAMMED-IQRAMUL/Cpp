#include <bits/stdc++.h>
using namespace std;
void BINARY_TO_DECIMAL(int n)
{
    int ans = 0, x = 1;
    while (n > 0)
    {
        int y = n % 10;
        ans += +x * y;
        x = x * 2;
        n /= 10;
    }
    cout << "BINARY TO DECIMAL IS : " << ans;
}
void DECIMAL_TO_BINARY(int n)
{
    int x = 1, ans = 0, lastdigit;
    while (x <= n)

        x *= 2;
    x /= 2;
    while (x > 0)
    {
        lastdigit = n / x;
        n -= lastdigit * x;
        x /= 2;
        ans = ans * 10 + lastdigit;
    }

    cout << "DECIMAL TO BINARY IS : " << ans;
}
void DECIMAL_TO_OCTAL(int n)
{
    int x = 1, ans = 0, lastdigit;
    while (x <= n)

        x *= 8;
    x /= 8;
    while (x > 0)
    {
        lastdigit = n / x;
        n -= lastdigit * x;
        x /= 8;
        ans = ans * 10 + lastdigit;
    }

    cout << "DECIMAL TO OCTAL IS : " << ans;
}
void DECIMAL_TO_HEXADECIMAL(int n)
{
    string ans = "";
    int x = 1;
    int lastdigit;
    while (x <= n)

        x *= 16;
    x /= 16;
    while (x > 0)
    {
        lastdigit = n / x;
        n -= lastdigit * x;
        x /= 16;
        if (lastdigit <= 9)
        {
            ans = ans + to_string(lastdigit);
        }
        else
        {
            char c = 'A' + lastdigit - 10;
            ans.push_back(c);
        }
    }

    cout << "DECIMAL TO HEXADECIMAL IS : " << ans;
}
void HEXADECIMAL_TO_DECIMAL(string n)
{
    int ans = 0, x = 1;
    int s = n.size();
    for (int i = s - 1; i >= 0; i--)
    {
        if (n[i] >= '0' && n[i] <= '9')
        {
            ans = ans + x * (n[i] - '0');
        }
        else if (n[i] >= 'A' && n[i] <= 'F')
        {
            ans = ans + x * (n[i] - 'A' + 10);
        }
        x = x * 16;
    }
    cout << "HEXADECIMAL TO DECIMAL :  " << ans;
}
void OCTAL_TO_DECIMAL(int n)
{
    int ans = 0, x = 1;
    while (n > 0)
    {
        int y = n % 10;
        ans += +x * y;
        x = x * 8;
        n /= 10;
    }
    cout << "OCTAL TO DECIMAL IS : " << ans;
}
int main()
{
    BINARY_TO_DECIMAL(1000);
    cout << "\n";
    DECIMAL_TO_BINARY(10);
    cout << "\n";
    DECIMAL_TO_OCTAL(394);
    cout << "\n";
    DECIMAL_TO_HEXADECIMAL(894);
    cout << "\n";
    HEXADECIMAL_TO_DECIMAL("2AB5");
     cout << "\n";
     OCTAL_TO_DECIMAL(632);
    return 0;
}