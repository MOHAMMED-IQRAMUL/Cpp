#include <bits/stdc++.h>
using namespace std;
int ACC_NO = 100;

int COUNT_DIGIT(int N)
{
    int DIGI = 0, rem;
    while (N != 0)
    {
        N = N / 10;
        DIGI++;
    }
    return DIGI;
}

class PERSON
{

public:
    int PhNo;
    string Name, Address;

public:
    virtual void GETDATA() = 0;
};

class BANK : public PERSON
{
public:
    int AccNo, PIN, BALANCE;

public:
    void GETDATA()
    {
        cout << "ENTER THE NAME OF ACCOUNT HOLDER ";
        cin >> Name;
        cout << "ENTER THE PHONE NUMBER ";
        cin >> PhNo;
        cout << "ENTER YOUR ADDRESS ";
        cin >> Address;
        cout << "ENTER THE AMOUNT OF DEPOSIT ";
        cin >> BALANCE;
        cout << "CHOOSE 4 DIGIT PIN TO SET PASSWORD ";
    RE_TRY1:
        cin >> PIN;
        if (COUNT_DIGIT(PIN) != 4)
        {
            cout << "ERROR! ENTER 4 DIGIT PIN ";
            goto RE_TRY1;
        }
        ACC_NO += 1;
        cout << "\n\nCONGRATULATIONS! YOUR ACC HAS BEEN SUCCESSFULLY CREATED ."
             << "\nYOUR ACCOUNT NUMBER IS : " << ACC_NO << endl;
        AccNo = ACC_NO;
    }

    void WITHDRAW(int mn)
    {
        BALANCE -= mn;
    }
    void DEPOSIT(int nm)
    {
        BALANCE += nm;
    }

    void DISP()
    {
        cout << ACC_NO << "\t\t\t" << Name << "\t\t\t"
             << BALANCE << "\t\t\t" << PIN << endl;
    }

    int GETACC()
    {
        return AccNo;
    }
};

int main()
{

    BANK E1[10];
    int INDEX = 0;

    int OP_1;
STEP_63:
    cout << "ENTER YOUR OPTION \n"
         << "1.OPEN  ACCOUNT\n"
         << "2.UPDATE  ACCOUNT HOLDER NAME \n"
         << "3.SHOW ACCOUNT DATA \n"
         << "4.VIEW BALANCE\n"
         << "5.WITHDRAW MONEY\n"
         << "6.DEPOSIT MONEY\n"
         << "7.UPDATE ACCOUNT PASSWORD \n"
         << "8.EXIT\n";
    cin >> OP_1;

    switch (OP_1)
    {
    case 1:
        //<< "1.OPEN  ACCOUNT\n"
        E1[INDEX].GETDATA();
        INDEX++;
        goto STEP_63;

        break;
    case 2:
        //<< "2.UPDATE  ACCOUNT HOLDER NAME \n"
        int ACCS, ind;
        cout << "ENTER ACCOUNT NUMBER ";
        cin >> ACCS;
        for (int i = 0; i < 10; i++)
        {
            if (ACCS == E1[i].GETACC())
                ind = i;
        }
        cout << "HELLO mr/mrs " << E1[ind].Name << "ENTER NEW NAME ";
        cin >> E1[ind].Name;
        cout << "Successfull";
        goto STEP_63;

        break;
    case 3:
        //<< "3.SHOW ACCOUNT DATA \n"
        ACCS = 0, ind = 0;
        cout << "ENTER ACCOUNT NUMBER ";
        cin >> ACCS;
        for (int i = 0; i < 10; i++)
        {
            if (ACCS == E1[i].GETACC())
                ind = i;
        }
        E1[ind].DISP();
        goto STEP_63;

        break;
    case 4:
        // << "4.VIEW BALANCE\n"
        ACCS = 0, ind = 0;
        cout << "ENTER ACCOUNT NUMBER ";
        cin >> ACCS;
        for (int i = 0; i < 10; i++)
        {
            if (ACCS == E1[i].GETACC())
                ind = i;
        }
        cout << "BALANCE = " << E1[ind].BALANCE;
        goto STEP_63;

        break;
    case 5:
        //<< "5.WITHDRAW MONEY\n"

        ACCS = 0, ind = 0;
        cout << "ENTER ACCOUNT NUMBER ";
        cin >> ACCS;
        for (int i = 0; i < 10; i++)
        {
            if (ACCS == E1[i].GETACC())
                ind = i;
        }
        int MONEY;
        cout << "ENTER THE MONEY TO WITHDRAW ";
        cin >> MONEY;
        E1[ind].WITHDRAW(MONEY);
        cout << "NEW BALANCE = " << E1[ind].BALANCE;

        goto STEP_63;

        break;
    case 6:
        //<< "6.DEPOSIT MONEY\n"
        ACCS = 0, ind = 0;
        cout << "ENTER ACCOUNT NUMBER ";
        cin >> ACCS;
        for (int i = 0; i < 10; i++)
        {
            if (ACCS == E1[i].GETACC())
                ind = i;
        }

        cout << "ENTER THE MONEY TO DEPOSIT ";
        cin >> MONEY;
        E1[ind].DEPOSIT(MONEY);
        cout << "NEW BALANCE = " << E1[ind].BALANCE;

        goto STEP_63;

        break;
    case 7:
        // << "7.UPDATE ACCOUNT PASSWORD \n"
        ACCS = 0, ind = 0;
        cout << "ENTER ACCOUNT NUMBER ";
        cin >> ACCS;
        for (int i = 0; i < 10; i++)
        {
            if (ACCS == E1[i].GETACC())
                ind = i;
        }
        cout << "HELLO mr/mrs " << E1[ind].Name << "ENTER NEW PIN ";
        cin >> E1[ind].PIN;
        cout << "Successfull";

        goto STEP_63;

        break;
    case 8:
        //<< "8.EXIT\n";
        cout << "\n\t\t\t********** THANK YOY FOR BANKING!! SEE YOU SOON **********";
        return 1;
        break;

    default:
        cout << "ENTER CORRECT OPTION ";
        goto STEP_63;
        break;
    }

    return 0;
}