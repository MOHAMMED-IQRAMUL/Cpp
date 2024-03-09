#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<int> ARRAY ={1,2,3,4,5};
    for(int i = 0 ; i < ARRAY.size(); i++){
        cout<<ARRAY[i]<<"    "<<ARRAY.at(i)<<"    ";
    }

        vector<vector<int>> MATRIX = {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 0},
            {1, 2, 3, 4, 5}};
        for (int i = 0; i < MATRIX.size(); i++)
        {
            for (int j = 0; j < MATRIX[i].size(); j++)
            {

                cout << MATRIX[i][j] << "   ";
            }
            cout << endl;
        }

    for(auto  VEC : MATRIX)
    {
        for(int x : VEC)
        {
            cout<<x<<"  ";
        }
        cout<<endl;
    }

    int R = 5, E = 10;
    vector<vector<int>> MAT(R, vector<int>(E));
    for (auto VEC : MAT)
    {
        for (int x : VEC)
        {
            cout << x << "  ";
        }
        cout << endl;
    }

    for (int i = 0; i < MAT.size(); i++)
    {
        for (int j = 0; j < MAT[i].size(); j++)
        {

            MAT[i][j] = 1;
        }
        // cout << endl;
    }

    for (auto VEC : MAT)
    {
        for (int x : VEC)
        {
            cout << x << "  ";
            x = 1;
        }
        cout << endl;
    }

    return 0;
}