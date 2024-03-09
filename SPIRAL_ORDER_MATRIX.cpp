#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r, c;
    cout << "Enter Rows and Column : ";
    cin >> r >> c;
    int matrix[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "Enter " << i + 1 << " \t" << j + 1 << " : ";
            cin >> matrix[i][j];
        }
    }
    int row_start = 0, row_end = r - 1, column_start = 0, column_end = c - 1;
    while (row_start <= row_end && column_start <= column_end)
    {
        // FOR ROW START
        for (int col = column_start; col <= column_end; col++)
        {
            cout << " " << matrix[row_start][col];
        }
        row_start++;
        // FOR COLUMN END
        for (int row = row_start; row <= row_end; row++)
        {
            cout << " " << matrix[row][column_end];
        }
        column_end--;
        // FOR ROW END
        for (int col = column_end; col >= column_start; col--)
        {
            cout << " " << matrix[row_end][col];
        }
        row_end--;
        // FOR COLUMN START
        for (int row = row_end; row >= row_start; row--)
        {
            cout << " " << matrix[row][column_start];
        }
        column_start++;
    }
    return 0;
}