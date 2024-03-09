#include <bits/stdc++.h>
using namespace std;

const int n = 4; // Define n as a constant

void SaveBoard(char Board[n][n], list<list<string>>& AllBoards)
{
    string row = "";
    list<string> newBoard;

    for(int i = 0; i < n; i++) {
        row = "";
        for(int j = 0; j < n; j++) {
            if(Board[i][j] == 'Q')
                row += 'Q';
            else
                row += '.';
        }

        newBoard.push_back(row);
    }

    AllBoards.push_back(newBoard);
}

bool isSafe(int row, int col, char Board[n][n])
{
     // horizontal
    for (int j = 0; j < n; j++)
    {
        if (Board[row][j] == 'Q')
        {
            return false;
        }
    }

    // vertical
    for (int i = 0; i < n; i++)
    {
        if (Board[i][col] == 'Q')
        {
            return false;
        }
    }

    // upper left
    int r = row;
    for (int c = col; c >= 0 && r >= 0; c--, r--)
    {
        if (Board[r][c] == 'Q')
        {
            return false;
        }
    }

    // upper right
    r = row;
    for (int c = col; c < n && r >= 0; r--, c++)
    {
        if (Board[r][c] == 'Q')
        {
            return false;
        }
    }
    // lower left
    r = row;
    for (int c = col; c >= 0 && r <n ; r++, c--)
    {
        if (Board[r][c] == 'Q')
        {
            return false;
        }
    }

    // lower right
    for (int c = col; c < n && r < n; c++, r++)
    {
        if (Board[r][c] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void Helper(char Board[n][n], list<list<string>>& AllBoards, int col)
{
    if (col == n)
    {
        SaveBoard(Board, AllBoards);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, Board))
        {
            Board[row][col] = 'Q';
            Helper(Board, AllBoards, col + 1);
            Board[row][col] = '-';
        }
    }
}

list<list<string>> SolveNQueens(int n1)
{
    list<list<string>> AllBoards;
    char Board[n][n];

    Helper(Board, AllBoards, 0);
    return AllBoards;
}

int main()
{
    list<list<string>> RET = SolveNQueens(4);

    while (!RET.empty()) {
        list<string> l = RET.back();
        RET.pop_back();

        for (const string& row : l) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}

/*
{
    #include <bits/stdc++.h>
using namespace std;
int n = 4;
void SaveBoard(char Board[4][4], list<list<string>> AllBoards)
{
      string row = "";
       list<string> newBoard ;
      
       for(int i=0; i<n; i++) {
 row = "";
           for(int j=0; j<n; j++) {
               if(Board[i][j] == 'Q')
                   row += 'Q';
               else
                   row += '.';
           }
           
           newBoard.push_back(row);
       }
      
       AllBoards.push_back(newBoard);

}
bool isSafe(int row, int col, char Board[4][4])
{
    // horizontal
    for (int j = 0; j < n; j++)
    {
        if (Board[row][j] == 'Q')
        {
            return false;
        }
    }

    // vertical
    for (int i = 0; i < n; i++)
    {
        if (Board[i][col] == 'Q')
        {
            return false;
        }
    }

    // upper left
    int r = row;
    for (int c = col; c >= 0 && r >= 0; c--, r--)
    {
        if (Board[r][c] == 'Q')
        {
            return false;
        }
    }

    // upper right
    r = row;
    for (int c = col; c < n && r >= 0; r--, c++)
    {
        if (Board[r][c] == 'Q')
        {
            return false;
        }
    }
    // lower left
    r = row;
    for (int c = col; c >= 0 && r <n ; r++, c--)
    {
        if (Board[r][c] == 'Q')
        {
            return false;
        }
    }

    // lower right
    for (int c = col; c < n && r < n; c++, r++)
    {
        if (Board[r][c] == 'Q')
        {
            return false;
        }
    }

    return true;
}




void Helper(char Board[4][4], list<list<string>> AllBoards, int col)
{
    if (col == n)
    {
        SaveBoard(Board, AllBoards);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, Board))
        {
            Board[row][col] = 'Q';
            Helper(Board, AllBoards, col + 1);
            Board[row][col] = '-';
        }
    }
}


list<list<string>> SolveNQueens(int n1)
{
    list<list<string>> AllBoards;
    char Board[4][4];

    Helper(Board, AllBoards, 0);
    return AllBoards;
}


int main()
{
   
    list<list<string>> RET = SolveNQueens(4);

    while (!RET.empty()) {
        list<string> l = RET.back();
        RET.pop_back();

        for (const string& row : l) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
}
*/