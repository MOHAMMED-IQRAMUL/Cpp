#include <bits/stdc++.h>
using namespace std;
class person{
    int no;
    string name , age , gender ;
    public:
    void getdata(){
        cout<<"ENTER NAME ";
        cin>>name;
        cout<<"ENTER NO ";
        cin>>no;
        cout<<"ENTER AGE ";
        cin>>age;
        cout<<"ENTER GENDER ";
        cin>>gender;
    }
    void putdata(){
        cout<<"NAME "<<name<<endl;
        cout<<"NO "<<no<<endl;
        cout<<"AGE "<<age<<endl;
        cout<<"GENDER "<<gender<<endl;
    }
};
int main()
{
    ofstream WRITE("FILE.DATA");
    person P[5];
    for(int i = 0 ; i< 5 ; i++){
        P[i].getdata();
        WRITE.write ( (char * ) & P[i] , sizeof(P[i]));
    }
//     string TEXT;
//     ifstream READ("HI.TXT");
//     for(int i = 0 ; i < 5 ; i++){
//    READ.read((char * ) & P[i] , sizeof(P[i]));
//    P[i].putdata();
//    cout<<endl;
//     }
    return 0;
}