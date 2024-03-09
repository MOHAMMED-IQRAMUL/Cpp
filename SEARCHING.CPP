#include<bits/stdc++.h>
using namespace std;
int BIN(int ARR[], int L , int H , int KEY)
{  int MID = 0  ;
    while(L<=H)
    {
        MID = (L+H)/2;

        if(KEY == ARR[MID])
         return MID;
        else if (KEY < ARR[MID])
            H = MID - 1 ;
        else
           L = MID + 1 ;
    }
    return -1;
}

int RBIN(int ARR[], int L , int H , int KEY)
{ static int MID = 0  ;
    if(L<=H)
    {
        MID = (L+H)/2;
        if(KEY == ARR[MID])
         return MID;
        else if (KEY < ARR[MID])
           return  RBIN(  ARR ,   L ,  MID - 1 ,  KEY);
            else  
            return RBIN(  ARR ,  MID + 1 ,  H ,  KEY) ;
    }
    return -1;
}


int main(){ 
    int ARR[10]={1,2,3,4,5,6,7,8,9 };
    int L=0,H=10,KEY=3 ;
    cout << "ELEMENT 2 IS FOUND AT " << BIN(  ARR ,   0 ,  9,  22) << endl ;
    cout << "ELEMENT 2 IS FOUND AT " << RBIN(  ARR ,   0,  9 , 44) << endl ; 
    return 0;
}