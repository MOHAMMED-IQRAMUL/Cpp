#include <iostream>
using namespace std;
class OPERATORS
{
    int NUM1, NUM2;

public:
    OPERATORS() {}
    OPERATORS(int X, int Y)
    {
        NUM1 = X;
        NUM2 = Y;
    }

    OPERATORS operator+(OPERATORS O1)
    {
        OPERATORS O;
        O.NUM1 = NUM1 + O1.NUM1;
        O.NUM2 = NUM2 + O1.NUM2;
        return O;
    }
    OPERATORS operator-(OPERATORS O1)
    {
        OPERATORS O;
        O.NUM1 = NUM1 - O1.NUM1;
        O.NUM2 = NUM2 - O1.NUM2;
        return O;
    }
    OPERATORS operator*(OPERATORS O1)
    {
        OPERATORS O;
        O.NUM1 = NUM1 * O1.NUM1;
        O.NUM2 = NUM2 * O1.NUM2;
        return O;
    }
    OPERATORS operator/(OPERATORS O1)
    {
        OPERATORS O;
        O.NUM1 = NUM1 / O1.NUM1;
        O.NUM2 = NUM2 / O1.NUM2;
        return O;
    }
    OPERATORS operator=(OPERATORS O1)
    {
        NUM1 = O1.NUM1;
        NUM2 = O1.NUM2;
    }
    OPERATORS operator++(int)
    {
        OPERATORS O;
        NUM1++;
        NUM2++;
    }
    OPERATORS operator--(int)
    {
        OPERATORS O;
        NUM1--;
        NUM2--;
    }
    OPERATORS operator++()
    {
        OPERATORS O;
        ++NUM1;
        ++NUM2;
    }
    OPERATORS operator--()
    {
        OPERATORS O;
        --NUM1;
        --NUM2;
    }
    OPERATORS operator<=(OPERATORS O1)
    {
        OPERATORS O;

        O.NUM1 = (NUM1 <= O1.NUM1);
        O.NUM2 = (NUM2 <= O1.NUM2);
        return O;
    }
    OPERATORS operator>=(OPERATORS O1)
    {
        OPERATORS O;

        O.NUM1 = (NUM1 >= O1.NUM1);
        O.NUM2 = (NUM2 >= O1.NUM2);
        return O;
    }
    OPERATORS operator!=(OPERATORS O1)
    {
        OPERATORS O;

        O.NUM1 = (NUM1 != O1.NUM1);
        O.NUM2 = (NUM2 != O1.NUM2);
        return O;
    }
    OPERATORS operator==(OPERATORS O1)
    {
        OPERATORS O;

        O.NUM1 = (NUM1 == O1.NUM1);
        O.NUM2 = (NUM2 == O1.NUM2);
        return O;
    }
    void DISP()
    {
        cout << "NUM1 = " << NUM1 << endl
             << "NUM2 = " << NUM2 << endl
             << endl;
    }
};
int main()
{
    OPERATORS N1(8, 6), N2(4, 6), N3(5, 7), N4(3, 5), N5, N6, N7, N8, N9, N0, N11, N12, N13, N14;
    N1.DISP();
    N2.DISP();
    N3.DISP();
    N4.DISP();
    N5 = N1 + N2;
    N6 = N1 - N2;
    N7 = N1 * N2;
    N8 = N1 / N2;
    N14 = N8;
    N3++;
    N4--;
    ++N1;
    --N2;
    N0 = (N2 == N1);
    N11 = (N2 <= N1);
    N12 = (N2 >= N1);
    N13 = (N2 != N1);
    N1.DISP();
    N2.DISP();
    N3.DISP();
    N4.DISP();
    N5.DISP();
    N6.DISP();
    N7.DISP();
    N8.DISP();
    N1.DISP();
    N2.DISP();
    N0.DISP();
    N12.DISP();
    N11.DISP();
    N13.DISP();
    N14.DISP();
    return 0;
}
