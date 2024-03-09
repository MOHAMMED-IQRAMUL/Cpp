#include <bits/stdc++.h>
using namespace std;

int ISBALANCED1(char *EXP)
{
    stack<char> STK;
    for (int I = 0; EXP[I] != '\0'; I++)
    {
        if (EXP[I] == '(')
            STK.push(EXP[I]);
        else if (EXP[I] == ')')
        {
            if (STK.empty())
                return false;
            STK.pop();
        }
    }
    return STK.empty() ? true : false;
}

int ISBALANCED2(char *EXP)
{
    stack<char> STK;
    for (int I = 0; EXP[I] != '\0'; I++)
    {
        if (EXP[I] == '(' || EXP[I] == '[' || EXP[I] == '{')
            STK.push(EXP[I]);
        else if (EXP[I] == ')' || EXP[I] == ']' || EXP[I] == '}')
        {
            if (STK.empty())
                return false;
            int A = 0;
            if (EXP[I] == ')')
                A = (STK.top() + 1);
            else if (EXP[I] == ']')
                A = (STK.top() + 2);
            else if (EXP[I] == '}')
                A = (STK.top() + 2);

            if (EXP[I] == A)
                STK.pop();
        }
    }

    return STK.empty() ? 1 : 0;
}

int ISOPERAND(char X)
{
    if (X == '+' || X == '-' || X == '*' || X == '/' || X == '^' || X == '(' || X == ')')
        return 0;
    else
        return 1;
}

int PRECEDENCE1(char X)
{
    if (X == '+' || X == '-')
        return 1;
    else if (X == '*' || X == '/')
        return 2;

    return 0;
}

int OUTPRCEDENCE(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 3;
    }
    else if (x == '^')
    {
        return 6;
    }
    else if (x == '(')
    {
        return 7;
    }
    else if (x == ')')
    {
        return 0;
    }
    return -1;
}

int INPRECEDENCE(char x)
{
    if (x == '+' || x == '-')
    {
        return 2;
    }
    else if (x == '*' || x == '/')
    {
        return 4;
    }
    else if (x == '^')
    {
        return 5;
    }
    else if (x == '(')
    {
        return 0;
    }
    return -1;
}

char *INFIX_TO_POSTFIX1(char *INFIX)
{
    stack<char> STK;
    STK.push('#');
    char *POSTFIX = new char[strlen(INFIX) + 1];
    int I = 0, J = 0;
    while (INFIX[I] != '\0')
    {
        if (ISOPERAND(INFIX[I]))
        {
            POSTFIX[J++] = INFIX[I++];
        }
        else
        {
            if (PRECEDENCE1(INFIX[I]) > PRECEDENCE1(STK.top()))
            {
                STK.push(INFIX[I++]);
            }

            else
            {
                POSTFIX[J++] = STK.top();
                STK.pop();
            }
        }
    }
    while (!STK.empty())
    {
        POSTFIX[J++] = STK.top();
        STK.pop();
    }
    POSTFIX[J] = '\0';
    return POSTFIX;
}

char *INFIX_TO_POSTFIX2(char *infix)
{
    char *postfix = new char[strlen(infix) + 1];

    stack<char> stk;

    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        if (ISOPERAND(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (stk.empty() || OUTPRCEDENCE(infix[i]) > INPRECEDENCE(stk.top()))
            {
                stk.push(infix[i++]);
            }
            else if (OUTPRCEDENCE(infix[i]) == INPRECEDENCE(stk.top()))
            {
                stk.pop();
            }
            else
            {
                postfix[j++] = stk.top();
                stk.pop();
            }
        }
    }

    while (!stk.empty() && stk.top() != ')')
    {
        postfix[j++] = stk.top();
        stk.pop();
    }

    postfix[j] = '\0';

    return postfix;
}

int EVALUATE(char *postfix)
{
    int i = 0;
    int x1, x2, r = 0;
    stack<char> STK;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (ISOPERAND(postfix[i]))
        {
            STK.push(postfix[i] - '0');
        }
        else
        {
            x2 = STK.top();
            STK.pop();
            x1 = STK.top();
            STK.pop();
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                r = x1 / x2;
                break;
            }
            STK.push(r);
        }
    }
    return STK.top();
}

int main()
{
    // char P1[20] = {'(','(','A','+','B',')','*','(','C','-','D',')','(',')',')'};

    // cout << ISBALANCED1(P1)<<endl;

    //  char P2[20] = {'{','(','A','+','B',')','*','(','C','-','D',')','(',')','}'};

    // cout << ISBALANCED2(P2)<<endl;

    // char P3[20] = {'A', '+', 'B', '*', 'C', '-', 'D', '/', 'E', '\0'};
    // cout << P3 << "  INFIX_TO_POSTFIX  ";
    // cout << INFIX_TO_POSTFIX1(P3) << endl;

    // char P3[ ] = "((A+B)*C)-D^E^F";
    // cout << P3 << "  INFIX_TO_POSTFIX  ";
    // cout << INFIX_TO_POSTFIX2(P3) << endl;

    // char P4[] = "65+34*+";
    // cout << P4 << "  VALUE IS   ";
    // cout << EVALUATE(P4) << endl;

    return 0;
}