#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
using namespace std;

int main()
{   string LINE;
    fstream T1("TEXT.TXT",ios::app);

    T1<<"HELLO"<<endl;


    fstream T2("TEXT.TXT",ios::in);
    T2.seekg(0,ios::cur);
    T2>>LINE;
    cout<<LINE;
    return 0;
}