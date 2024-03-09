#include <bits/stdc++.h>
using namespace std;
int main()
{
    //******  FIRST EXAMPLE *****

       int a =9,b=0;
       try{
        if(b!=0){
            cout<<a/b;
        }
        else{
            throw "HI",b;
        }
       }
       catch(int n ){
       cerr<<"ERROR!! in int   "<<n;
       }
       catch(char const* s){
        cerr<<"ERROR!!  in string   "<<s;
       }

    //*****  SECOND EXAMPLE  *****

    char STR[7];
    int i = 0;

    cout << "\n\n****ENTERING****\n\n";

    try
    {
        while (cin >> STR[i])
        {
            i++;
            if (i >= 7)
            {
                throw " OUT OF BOUND ";
            }
        }
    }
    catch (const char *PO)
    {
         cerr<<PO;
    }

    cout << "\n\n****OUT****\n\n";

    for (int i = 0; i < 7; i++)
    {
        cout << STR[i] << "  ";
    }

    //*****  THIRD EXAMPLE  *****

    int ARR[5]={1,2,3,4,5},I=0;
    try{
       while(1){
        if(I!=5){
            cout<<ARR[I];
        }
        else{
            throw " OUT OF BOUND ";
        }
        I++;
       }
    }
    catch( const char * MSG){
        cout<<MSG;
    }

    return 0;
}