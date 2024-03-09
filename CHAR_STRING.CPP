#include <iostream>
using namespace std;

class STRING
{
    char S[10];

public:
    STRING() {}
    STRING(char A[]);
    void DISP();
    void GET_LENGTH();
    void LOWER_TO_UPPER();
    void UPPER_TO_LOWER();
    void REVERSE();
    void DUPLICATE1();
    void DUPLICATE2();
    void DUPLICATE3();
    void CHECK_ANAGRAM1(STRING S1);
    void CHECK_ANAGRAM2(STRING S1);
    void PERMUTATION1(int K);
    void PERMUTATION2(int L, int H);
};
void SWAP(char *A, char *B)
{
    char TEMP = *A;
    *A = *B;
    *B = TEMP;
}
STRING ::STRING(char A[])
{
    int I;
    for (I = 0; A[I] != '\0'; I++)
        S[I] = A[I];
    S[I] = '\0';
}
void STRING ::DISP()
{
    cout << "\nTHE STRING IS " << S;
}
void STRING ::GET_LENGTH()
{
    int I;
    for (I = 0; S[I] != '\0'; I++)
    {
    }
    cout << "\nLENGTH IS EQUAL TO " << I;
}
void STRING ::LOWER_TO_UPPER()
{
    int I;
    cout << "\nSTRING \" " << S << "\" FROM LOWER TO UPPER IS ";
    for (I = 0; S[I] != '\0'; I++)
    {
        if (S[I] == ' ')
            cout << S[I];
        else
        {
            S[I] -= 32;
            cout << S[I];
        }
    }
}
void STRING ::UPPER_TO_LOWER()
{
    int I;
    cout << "\nSTRING \" " << S << "\" FROM UPPER TO LOWER IS ";
    for (I = 0; S[I] != '\0'; I++)
        if (S[I] == ' ')
            cout << S[I];
        else
        {
            S[I] += 32;
            cout << S[I];
        }
}
void STRING ::REVERSE()
{
    int I, J;
    cout << "\nSTRING \" " << S << " \" IN REVERSE IS ";
    for (I = 0; S[I] != '\0'; I++)
    {
    }
    J = I - 1;
    for (J, I = 0; I <= J; I++, J--)
    {
        SWAP(&S[I], &S[J]);
    }
    cout << S;
}
void STRING ::DUPLICATE1()
{
    int I, J, COUNT;
    for (I = 0; S[I] != '\0'; I++)
    {
        COUNT = 1;
        if (S[I] != -1)
        {

            for (J = I + 1; S[J] != '\0'; J++)
            {
                if (S[I] == S[J])
                {
                    COUNT++;
                }
            }
        }
        if (COUNT > 1)
        {
            cout << "\nALPHABET " << S[I] << " HAS OCCURES " << COUNT << " TIMES ";
        }
    }
}
void STRING ::DUPLICATE2()
{
    int H[26] = {0};
    cout << "\nDUPLICATE ELEMENT ARE  ";

    for (int I = 0; S[I] != '\0'; I++)
    {

        H[(S[I] - 65)] += 1;
    }

    for (int I = 0; I < 26; I++)
    {
        if (H[I] > 1)
            cout << char(I + 65) << " APPAERS (  " << H[I] << "  TIMES ) ";
    }
}
void STRING ::DUPLICATE3()
{
    int H = 0, X = 0;
    for (int I = 0; S[I] != '\0'; I++)
    {
        X = 1;
        X = X << (S[I] - 65);
        if ((X & H) > 0)
            cout << endl
                 << S[I] << " IS DUPLICATE ELEMENT ";
        else
            H = X | H;
    }
}
void STRING ::CHECK_ANAGRAM1(STRING S1)
{
    int I;
    bool FL = true;
    for (I = 0; S[I] != '\0'; I++)
    {
        FL = false;

        for (int i = 0; S1.S[I] != '\0'; i++)
        {
            if (S[I] == S1.S[i])
            {
                FL = true;

                break;
            }
        }
        if (FL == false)
        {
            cout << "\nIT IS NOT ANGRAM ";
            break;
        }
    }
    if (FL == true)
    {
        cout << "\nIT IS ANGRAM ";
    }
}
void STRING ::CHECK_ANAGRAM2(STRING S1)
{
    int I = 0, H[26] = {0};
    bool GLF = true;
    for (I = 0; S[I] != '\0'; I++)
    {
        H[S[I] - 65]++;
    }
    for (I = 0; S1.S[I] != '\0'; I++)
    {
        H[S1.S[I] - 65]--;
    }
    for (I = 0; I < 26; I++)
    {
        if (H[I] != 0)
        {
            GLF = false;
            cout << "\n! ANAGRAM";
            break;
        }
    }
    if (GLF == true)
        cout << "\nANAGRAM";
}
void STRING ::PERMUTATION1(int K)
{
    static int A[10] = {0};
    static char RES[10];
    int I = 0;
    if (S[K] == '\0')
    {
        RES[K] = '\0';
        cout << RES << "  ";
    }
    else
    {
        for (I = 0; S[I] != '\0'; I++)
        {
            if (A[I] == 0)
            {
                RES[K] = S[I];
                A[I] = 1;
                PERMUTATION1(K + 1);
                A[I] = 0;
            }
        }
    }
}
void STRING ::PERMUTATION2(int L, int H)
{
    int I;
    if (L == H)
    {
        cout << S << "  ";
    }
    else
    {
        for (I = L; I <= H; I++)
        {
            SWAP(&S[L], &S[I]);
            PERMUTATION2(L + 1, H);
            SWAP(&S[L], &S[I]);
        }
    }
}
int main()
{
    char S1[] = "FOUR";
    STRING A1(S1);
    A1.DISP();
    A1.GET_LENGTH();

    char S2[] = "lower to upper";
    STRING A2(S2);
    A2.LOWER_TO_UPPER();
    A2.DISP();
    char S3[] = "UPPER TO LOWER";
    STRING A3(S3);
    A3.UPPER_TO_LOWER();
    A3.DISP();

    char S4[] = "ESREVER";
    STRING A4(S4);
    A4.REVERSE();
    A4.DISP();

    char S5[] = "FINDING";
    STRING A5(S5);
    A5.DUPLICATE1();
    A5.DUPLICATE2();
    A5.DUPLICATE3();

    char S6[] = "DECIMAL";
    char S7[] = "MEDICAL";
    STRING A6(S6);
    A6.CHECK_ANAGRAM1(S7);
    A6.CHECK_ANAGRAM2(S7);

    char S8[] = "ABC";
    STRING A8(S8);
    // A8.DISP();/

    cout << endl;
    A8.PERMUTATION1(0);

    char S9[] = "ABC";
    STRING A9(S9);
    cout << endl;
    A9.PERMUTATION2(0, 2);

    return 0;
}