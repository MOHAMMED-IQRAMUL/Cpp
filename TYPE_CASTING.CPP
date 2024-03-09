#include <bits/stdc++.h>
using namespace std;
int main()
{
    int INT = 1234, CONVO_STRING_INT, CONVO_FLOAT_INT, CONVO_DOUBLE_INT;
    string STRING = "6871", CONVO_INT_STRING, CONVO_FLOAT_STRING, CONVO_DOUBLE_STRING;
    float FLOAT = 8642.234, CONVO_INT_FLOAT, CONVO_STRING_FLOAT, CONVO_DOUBLE_FLOAT;
    double DOUBLE = 123.9876, CONVO_INT_DOUBLE, CONVO_FLOAT_DOUBLE, CONVO_STRING_DOUBLE;

    cout << "\n\nINT = " << INT << endl;
    CONVO_STRING_INT = stoi(STRING);
    cout << "STRING = " << STRING << " CONVO_STRING_INT " << CONVO_STRING_INT << endl;

    CONVO_FLOAT_INT = static_cast<int>(FLOAT);
    cout << "FLOAT = " << FLOAT << " CONVO_FLOAT_INT " << CONVO_FLOAT_INT << endl;

    CONVO_DOUBLE_INT = static_cast<int>(DOUBLE);
    cout << "DOUBLE = " << DOUBLE << " CONVO_DOUBLE_INT " << CONVO_DOUBLE_INT << endl;

    cout << "\n\nSTRING = " << STRING << endl;
    CONVO_INT_STRING = to_string(INT);
    cout << "INT = " << INT << " CONVO_INT_STRING " << CONVO_INT_STRING << endl;

    CONVO_FLOAT_STRING = to_string(FLOAT);
    cout << "FLOAT = " << FLOAT << " CONVO_FLOAT_STRING " << CONVO_FLOAT_STRING << endl;

    CONVO_DOUBLE_STRING = to_string(DOUBLE);
    cout << "DOUBLE = " << DOUBLE << " CONVO_DOUBLE_STRING " << CONVO_DOUBLE_STRING << endl;

    cout << "\n\nFLOAT = " << FLOAT << endl;
    CONVO_INT_FLOAT = INT;
    cout << "INT = " << INT << " CONVO_INT_FLOAT " << CONVO_INT_FLOAT << endl;

    CONVO_STRING_FLOAT = stof(STRING);
    cout << "STRING = " << STRING << " CONVO_STRING_FLOAT " << CONVO_STRING_FLOAT << endl;

    CONVO_DOUBLE_FLOAT = static_cast<float>(DOUBLE);
    cout << "DOUBLE = " << DOUBLE << " CONVO_DOUBLE_FLOAT " << CONVO_DOUBLE_FLOAT << endl;

    cout << "\n\nDOUBLE = " << DOUBLE << endl;
    CONVO_INT_DOUBLE = INT;
    cout << "INT = " << INT << " CONVO_INT_DOUBLE " << CONVO_INT_DOUBLE << endl;

    CONVO_STRING_DOUBLE = stod(STRING);
    cout << "STRING = " << STRING << " CONVO_STRING_DOUBLE " << CONVO_STRING_DOUBLE << endl;

    CONVO_FLOAT_DOUBLE = FLOAT;
    cout << "FLOAT = " << FLOAT << " CONVO_FLOAT_DOUBLE " << CONVO_FLOAT_DOUBLE << endl;

    return 0;
}