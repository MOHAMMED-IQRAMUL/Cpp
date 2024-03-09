#include <bits/stdc++.h>
using namespace std;
/*                       *********  BANKING RECORD SYSTEM  **********                                  */
/*                        *********         BANK          **********                                 */

const int BANK_PASSWORD = 1234;

class BANK_RECORDS
{

public:
    int ACC_NO = 24685, BALANCE = 0, PASSWORD = 0;
    string NAME;

    void GETDATA();
    void DISP();
};
void WRITE_ACC_DATA(BANK_RECORDS B1);
int COUNT_DIGIT(int N);
int GET_INDEX(int x);
void WRITEing(BANK_RECORDS D123[], int n, string jikl);
void UPDATE_PASS(BANK_RECORDS bnk[], int INDF);
void DELETEing(int ACC);

int main()
{
    string FILE = "Bank.data";
    int OPTION, PASS_BANKER, PASS_CUSTOMER, ACC_CUSTOMER, LIMIT_BANKER = 1, LIMIT_CUSTOMER = 1;
    BANK_RECORDS CUST[20];
    ifstream READ_1(FILE);
    int i = 0, LI_1 = 0;
    string DATA_1;
    while (LI_1 < 5)
    {
        getline(READ_1, DATA_1);
        LI_1++;
    }
    while (READ_1.eof() == 0)
    {
        READ_1 >> CUST[i].ACC_NO >> CUST[i].NAME >> CUST[i].BALANCE >> CUST[i].PASSWORD;
        i++;
    }

    cout << "\t\t\t\t**********  WELCOME TO THE  BANK  **********\n\n";
STEP_30:
    cout << "\n\nENTER OPTION :\n"
         << " 1 IF YOU ARE BANK OFFICIAL \n"
         << " 2 IF YOU ARE A CUSTOMER \n"
         << " 3 TO EXIT \n";
    cin >> OPTION;
    LIMIT_BANKER = 1;
    LIMIT_CUSTOMER = 1;
    switch (OPTION)
    {
    case 1:
        // BANK OFFICIAL MENU
        cout << "\nWELCOME SIR  \nPLEASE ENTER THE PASSWORD : ";
    STEP_43:
        cin >> PASS_BANKER;

        if (PASS_BANKER != BANK_PASSWORD)
        {
            if (LIMIT_BANKER == 3)
            {
                cout << "\nSORRY YOU ENTERED WRONG PASSWORD 3 TIMES, TRY NEXT TIME (BYE!)\n";
                goto STEP_30;
            }
            else
            {
                cout << "\nPLEASE ENTER CORRECT PASSWORD : ";
                LIMIT_BANKER++;
            }
            goto STEP_43;
        }

        else
        {
            int OP_1;
        STEP_63:
            cout << "\nBANKER MENU \nENTER YOUR OPTION \n"
                 << "1.OPEN CUSTOMER ACCOUNT\n"
                 << "2.UPDATE CUSTOMER ACCOUNT HOLDER NAME \n"
                 << "3.UPDATE CUSTOMER ACCOUNT PASSWORD \n"
                 << "4.DELETE CUSTOMERS RECORD \n"
                 << "5.SHOW SPECIFIC ACCOUNT DATA \n"
                 << "6.SHOW ALL ACCOUNT DATA \n"
                 << "7.MAIN MENU\n"
                 << "8.EXIT\n";
            cin >> OP_1;

            switch (OP_1)
            {
            case 1:
                // WRITE CODE FOR OPPENING BANK ACCOUNT:
                i++;
                CUST[i].GETDATA();
                //    FUNCTION FOR WRITING DATA IN FILE:
                WRITE_ACC_DATA(CUST[i]);
                cout << "\n";
                goto STEP_63;
                break;

            case 2:
                // WRITE CODE FOR UPDATING ACCOUNT HOLDER NAME :
                int ACC_NO_1_;
                cout << "ENTER ACCOUNT NUMBER : ";
                cin >> ACC_NO_1_;
                int INDP_1;
                INDP_1 = GET_INDEX(ACC_NO_1_);

                if (INDP_1 > 20)
                {
                    cout << "\n\nWRONG ACCOUNT NUMBER ENTERED\nTRY AGAIN LATER \n\n";
                    goto STEP_63;
                }

                cout << "MR/MRs " << CUST[INDP_1].NAME << " PLEASE ENTER NEW NAME : ";
                cin >> CUST[INDP_1].NAME;
                cout << "\nNAME SUCCESSFULLY UPDATED TO : " << CUST[INDP_1].NAME << "\n\n";
                // CODE FOR RE WRITING UPDATED DATA

                WRITEing(CUST, CUST[INDP_1].ACC_NO, CUST[INDP_1].NAME);

                goto STEP_63;
                break;

            case 3:
                // UPDATE CUSTOMER ACCOUNT PASSWORD

                int ACC_NO_2_;
                cout << "ENTER ACCOUNT NUMBER : ";
                cin >> ACC_NO_2_;
                int INDP_2;
                INDP_2 = GET_INDEX(ACC_NO_2_);
                cout << "MR/MRs " << CUST[INDP_2].NAME
                     << "\n PLEASE ENTER NEW PASSWORD TO GET UPDATED : ";
            RE_TRY2:
                cin >> CUST[INDP_2].PASSWORD;

                if (COUNT_DIGIT(CUST[INDP_2].PASSWORD) != 4)
                {
                    cout << "ERROR! ENTER 4 DIGIT PIN ";
                    goto RE_TRY2;
                }

                cout << "\nPASSWORD SUCCESSFULLY UPDATED TO : " << CUST[INDP_2].PASSWORD << endl
                     << endl;

                // CODE FOR RE WRITING UPDATED DATA

                UPDATE_PASS(CUST, i);
                goto STEP_63;
                break;

            case 4:
                //     // DELETE CUSTOMERS RECORD

                int ACC_NO_3_;
                cout << "ENTER ACCOUNT NUMBER : ";
                int OP_2;
                cin >> ACC_NO_3_;
                int INDP_3;
                INDP_3 = GET_INDEX(ACC_NO_3_);
                cout << "MR/MRs " << CUST[INDP_3].NAME << "   : "
                     << "\n PLEASE SELECT \n 1.TO DELETE THE ACCOUNT OR 2.TO GO TO CANCEL : ";
                cin >> OP_2;
                switch (OP_2)
                {
                case 1:
                    // CODE TO DELETE THE DATA AND UPDATE :
                    DELETEing(CUST[INDP_3].ACC_NO);

                    //   delete(CUST[INDP_3]);
                    break;
                case 2:
                    // CODE TO RETURN TO BANKER MENU :
                    goto STEP_63;
                    break;
                default:
                    cout << "ERROR OPTION CHOOSEN IS INVALID .\nREDIRECTED TO THE BANKING MENU.\n";
                }
                cout << "\nACCOUNT DELETED SUCCESSFULLY " << endl
                     << endl;

                goto STEP_63;
                break;

            case 5:
                //  SHOW SPECIFIC ACCOUNT DATA
                int ACC_NO_4_;
                cout << "ENTER ACCOUNT NUMBER : ";
                cin >> ACC_NO_4_;
                int INDP_4;
                INDP_4 = GET_INDEX(ACC_NO_4_);
                cout << "\nCUSTOMER DETAILS :  \n"
                     << "ACCOUNT NUMBER : " << CUST[INDP_4].ACC_NO
                     << "\nACCOUNT HOLDER NAME : " << CUST[INDP_4].NAME
                     << "\nREMAINING BALANCE : " << CUST[INDP_4].BALANCE << "\n\n";

                goto STEP_63;
                break;

            case 6:
                // SHOW ALL ACCOUNT DATA

                cout << "\t\t\t\t**********  WELCOME TO THE  BANK  **********\n\n"
                     << "ACCOUNT HOLDER DETAILS : \n"
                     << "ACCOUNT NUMBER\t\tNAME\t\t\tBALANCE\t\t\tPASSWORD\n\n";

                for (int k = 0; k < i; k++)
                {
                    CUST[k].DISP();
                }

                cout << "\n\n";
                goto STEP_63;
                break;

            case 7:
                //  TO GO TO MAIN MENU
                goto STEP_30;
                break;

            case 8:
                // TO EXIT THE PROGRAM
                cout << "\n\t\t\t********** THANK YOY FOR BANKING!! SEE YOU SOON **********";

                return 0;
                break;

            default:
                cout << "PLEASE ENTER A VALID OPTION ";
                goto STEP_63;
                break;
            }
        }

        break;
    case 2:

        // CUSTOMER MENU
        cout << "\n\nWELCOME SIR  \nPLEASE ENTER YOUR ACCOUNT NUMBER : ";
        cin >> ACC_CUSTOMER;
        // CODE TO GET INDEX OF CUSTOMER
        int INDEX;
        INDEX = GET_INDEX(ACC_CUSTOMER);
    STEP_122:
        cout << "\nHELLO " << CUST[INDEX].NAME << " PLEASE ENTER YOUR PASSWORD : ";
        cin >> PASS_CUSTOMER;
        if (PASS_CUSTOMER != CUST[INDEX].PASSWORD)
        {

            if (LIMIT_CUSTOMER == 3)
            {
                cout << "\nSORRY YOU ENTERED WRONG PASSWORD 3 TIMES, TRY NEXT TIME (BYE!)"
                     << "\nPLEASE CONTACT BANK TO RESET PASSWORD\n\n";
                goto STEP_30;
            }
            else
            {
                cout << "\nPLEASE ENTER CORRECT PASSWORD : ";
                LIMIT_CUSTOMER++;
            }
            goto STEP_122;
        }
        else
        {

            int OP_2;
        STEP_152:
            cout << "\nCUSTOMER MENU \nENTER YOUR OPTION \n"
                 << "1.VIEW BALANCE\n"
                 << "2.WITHDRAW MONEY\n"
                 << "3.DEPOSIT MONEY\n"
                 << "4.UPDATE ACCOUNT PASSWORD \n"
                 << "5.DELETE YOUR ACCOUNT\n"
                 << "6.MAIN MENU\n"
                 << "7.EXIT\n";
            cin >> OP_2;
            switch (OP_2)
            {

            case 1:
                // VIEW BALANCE
                cout << "\nYOUR ACCOUNT BALANCE : " << CUST[INDEX].BALANCE;
                goto STEP_152;
                break;
            case 2:
                // WITHDRAW MONEY
                int AMOUNT1;
                cout << "\nYOUR ACCOUNT BALANCE : " << CUST[INDEX].BALANCE;
                cout << "\nENTER THE AMOUNT YOU WANT TO WITHDRAW ";
                cin >> AMOUNT1;
                CUST[INDEX].BALANCE -= AMOUNT1;
                cout << "\nWITHDRAW SUCCESSFULL, YOU NEW BALANCE IS : " << CUST[INDEX].BALANCE;
                // CODE FOR WRITING UPDATED DATA
                UPDATE_PASS(CUST, i);

                goto STEP_152;
                break;
            case 3:
                // DEPOSIT MONEY
                AMOUNT1 = 0;
                cout << "\nYOUR ACCOUNT BALANCE : " << CUST[INDEX].BALANCE;
                cout << "\nENTER THE AMOUNT YOU WANT TO DEPOSIT ";
                cin >> AMOUNT1;
                CUST[INDEX].BALANCE += AMOUNT1;
                cout << "\nDEPOSIT SUCCESSFULL, YOU NEW BALANCE IS : " << CUST[INDEX].BALANCE;
                // CODE FOR WRITING UPDATED DATA

                UPDATE_PASS(CUST, i);
                goto STEP_152;
                break;
            case 4:
                // UPDATE ACCOUNT PASSWORD
                cout << "\n PLEASE ENTER NEW PASSWORD TO GET UPDATED : ";
            RE_TRY5:
                cin >> CUST[INDEX].PASSWORD;

                if (COUNT_DIGIT(CUST[INDEX].PASSWORD) != 4)
                {
                    cout << "ERROR! ENTER 4 DIGIT PIN ";
                    goto RE_TRY5;
                }

                cout << "\nPASSWORD SUCCESSFULLY UPDATED TO : " << CUST[INDEX].PASSWORD << endl
                     << endl;
                // CODE FOR WRITING UPDATED DATA

                UPDATE_PASS(CUST, i);

                goto STEP_152;
                break;
            case 5:
                // DELETE YOUR ACCOUNT
                int READ_OP;
                cout << "\nPRESS 1 TO DELETE YOUR ACCOUNT, TO  CANCEL PRESS 2  ";
                cin >> READ_OP;
                if (READ_OP == 1)
                {
                    DELETEing(CUST[INDEX].ACC_NO);
                    cout << "ACCOUNT DELETETION SUCCESSFULL \n";
                    goto STEP_30;
                }
                else if (READ_OP == 2)
                {
                    goto STEP_152;
                }
                else
                {
                    cout << "OPTION CHOOSN DOES NOT MATCH ";
                    goto STEP_152;
                }

                break;
            case 6:
                // GO TO MAIN MENU
                goto STEP_30;
                break;
            case 7:
                // EXIT THE PROGRAM
                cout << "\n\t\t\t********** THANK YOY FOR BANKING!! SEE YOU SOON **********";
                return 0;
            default:
                cout << "\nENTER VALID OPTION ";
                goto STEP_152;
                break;
            }
        }
        break;
    case 3:
        cout << "\n\t\t\t********** THANK YOY FOR BANKING!! SEE YOU SOON **********";
        // TO EXIT THE PROGRAM

        break;
    default:
        cout << "PLEASE ENTER A VALID OPTION ";
        goto STEP_30;
        break;
    }
    return 0;
}
void DELETEing(int ACC)
{

    BANK_RECORDS newF[30];
    ifstream READ_1("Bank.data");
    int ii = 0, LI_12 = 0, lop;
    string DATA_12, lines;
    while (LI_12 < 5)
    {
        getline(READ_1, DATA_12);
        lines += DATA_12 + "\n";
        LI_12++;
    }
    while (READ_1.eof() == 0)
    {
        READ_1 >> newF[ii].ACC_NO >> newF[ii].NAME >> newF[ii].BALANCE >> newF[ii].PASSWORD;
        if (newF[ii].ACC_NO == ACC)
        {
            lop = ii;
        }
        ii++;
    }
    READ_1.close();
    ofstream WERT("Bank.data");
    WERT << lines;
    for (int iop = 0; iop < ii; iop++)
    {
        if (iop == lop)
        {
            continue;
        }
        WERT << newF[iop].ACC_NO << "\t\t\t\t\t" << newF[iop].NAME << "\t\t\t"
             << newF[iop].BALANCE << "\t\t\t" << newF[iop].PASSWORD << endl;
    }
}

void UPDATE_PASS(BANK_RECORDS bnk[], int INDF)
{
    ifstream READ_1("Bank.data");
    int LI_12 = 0;
    string DATA_12, lines;
    while (LI_12 < 5)
    {
        getline(READ_1, DATA_12);
        lines += DATA_12 + "\n";
        LI_12++;
    }
    READ_1.close();
    ofstream WERT("Bank.data");
    WERT << lines;
    for (int iJK = 0; iJK < INDF; iJK++)
    {
        WERT << bnk[iJK].ACC_NO << "\t\t\t\t\t"
             << bnk[iJK].NAME << "\t\t\t" << bnk[iJK].BALANCE
             << "\t\t\t" << bnk[iJK].PASSWORD << endl;
    }
}

void WRITEing(BANK_RECORDS D123[], int n, string jikl)
{
    BANK_RECORDS newF[30];
    ifstream READ_1("Bank.data");
    int ii = 0, LI_12 = 0;
    string DATA_12, lines;
    while (LI_12 < 5)
    {
        getline(READ_1, DATA_12);
        lines += DATA_12 + "\n";
        LI_12++;
    }
    while (READ_1.eof() == 0)
    {
        READ_1 >> newF[ii].ACC_NO >> newF[ii].NAME >> newF[ii].BALANCE >> newF[ii].PASSWORD;
        if (newF[ii].ACC_NO == n)
        {
            newF[ii].NAME = jikl;
        }
        ii++;
    }
    READ_1.close();
    ofstream WERT("Bank.data");
    WERT << lines;
    for (int iop = 0; iop < ii; iop++)
    {
        WERT << newF[iop].ACC_NO << "\t\t\t\t\t" << newF[iop].NAME << "\t\t\t"
             << newF[iop].BALANCE << "\t\t\t" << newF[iop].PASSWORD << endl;
    }
}

void WRITE_ACC_DATA(BANK_RECORDS B1)
{
    string FILE = "Bank.data";
    ifstream READ_2(FILE);
    string DATA_1, DATA_2 = "";
    while (READ_2.eof() == 0)
    {
        getline(READ_2, DATA_1);
        DATA_2 += DATA_1 + "\n";
    }

    ofstream READ_3(FILE);
    READ_3 << DATA_2;
    READ_3 << B1.ACC_NO << "\t\t\t\t\t" << B1.NAME << "\t\t\t" << B1.BALANCE
           << "\t\t\t" << B1.PASSWORD << endl;
}

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

int GET_INDEX(int x)
{
    string FILE = "Bank.data";
    ifstream READ_1(FILE);
    int LOI = 0, LI_1 = 0, ACc_No, Bal, Pass;
    string DATA_1, Namee;
    while (LI_1 < 5)
    {
        getline(READ_1, DATA_1);
        LI_1++;
    }
    while (READ_1.eof() == 0)
    {
        READ_1 >> ACc_No >> Namee >> Bal >> Pass;
        if (ACc_No == x)
        {
            return LOI;
        }
        else
        {
            LOI++;
        }
    }
}

void BANK_RECORDS ::GETDATA()
{
    cout << "ENTER THE NAME OF ACCOUNT HOLDER ";
    cin >> NAME;
    cout << "ENTER THE AMOUNT OF DEPOSIT ";
    cin >> BALANCE;
    cout << "CHOOSE 4 DIGIT PIN TO SET PASSWORD ";
RE_TRY1:
    cin >> PASSWORD;
    if (COUNT_DIGIT(PASSWORD) != 4)
    {
        cout << "ERROR! ENTER 4 DIGIT PIN ";
        goto RE_TRY1;
    }
    ACC_NO += 1;
    cout << "\n\nCONGRATULATIONS! YOUR ACC HAS BEEN SUCCESSFULLY CREATED ."
         << "\nYOUR ACCOUNT NUMBER IS : " << ACC_NO << endl;
}

void BANK_RECORDS ::DISP()
{
    cout << ACC_NO << "\t\t\t" << NAME << "\t\t\t"
         << BALANCE << "\t\t\t" << PASSWORD << endl;
}
