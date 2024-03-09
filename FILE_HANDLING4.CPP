#include<bits/stdc++.h>
using namespace std;

int main(){ 
    string FILE = "FILE.DATA",TEXT;
    ifstream READ;
    READ.open(FILE);
    while(READ.eof()==0){
       getline (READ , TEXT);
       cout<<TEXT;
    }
   cout << endl << READ.good();


getline(READ,TEXT);
cout<<"1."<<TEXT<<endl;
// GIVES THE POSITION OF GET POINTER 
int L = READ.tellg();
getline(READ,TEXT);
cout<<"2."<<TEXT<<endl;
// MOVES THE GET POINTER TO DESIRED POSITION 
READ.seekg(L-2,ios::beg);
getline(READ,TEXT);
cout<<"3."<<TEXT<<endl;


//READING FILE IN BINARY MODE 
ifstream READ1;
    READ1.open(FILE,ios::binary);
READ1.seekg(0,ios::end);
    int SIZE = READ1.tellg();
    streampos SIZE1 = READ1.tellg();
    // cout<<SIZE<<endl<<SIZE1;
    READ1.seekg(0,ios::beg);

char * LINES = new char[SIZE1];

    while(READ1.eof()==0){
       getline (READ1 , TEXT);
    READ1.read(LINES,SIZE1);
       cout<<LINES;
    }
    READ1.close();
   cout << endl << READ1.good();
ofstream WRITE1;
WRITE1.open(FILE,ios::binary|ios::trunc);
WRITE1.write(LINES,SIZE1);
WRITE1.close();

    return 0;
}