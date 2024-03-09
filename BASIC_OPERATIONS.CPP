#include <bits/stdc++.h>
using namespace std;
int main()
{    int NUM1, NUM2, ANS;
    char OP;
    cout << "Enter two integer values : ";
    cin >> NUM1 >> NUM2;
    cout << "Enter an arithmetic operator : ";
    cin >> OP;
    switch (OP)
    {
    case '+':
        ANS = NUM1 + NUM2;
        cout << NUM1 << " " << OP << " " << NUM2 << " = " << ANS;
        break;
    case '-':
        ANS = NUM1 - NUM2;
        cout << NUM1 << " " << OP << " " << NUM2 << " = " << ANS;
        break;
    case '*':
        ANS = NUM1 * NUM2;
        cout << NUM1 << " " << OP << " " << NUM2 << " = " << ANS;
        break;
    case '/':
        ANS = NUM1 / NUM2;
        cout << NUM1 << " " << OP << " " << NUM2 << " = " << ANS;
        break;
    case '%':
        ANS = NUM1 % NUM2;
        cout << NUM1 << " " << OP << " " << NUM2 << " = " << ANS;
        break;
        ;
    default:
        cout << "\nError! Operator is not correct";
        break;
    }
    return 0;
}