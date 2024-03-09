#include <bits/stdc++.h>
using namespace std;
#define SIZE 8
#define E 9
#define I 3276
class ADJACENCY_MATRIX
{
public:
    vector<vector<int>> AM;
    int m, n;
    ADJACENCY_MATRIX(int M, int N)
    {
        m = M;
        n = N;
        AM.resize(m, vector<int>(n, 0));
    }
    ADJACENCY_MATRIX(int MAT[][SIZE], int M, int N)
    {

        m = M;
        n = N;
        AM.resize(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                AM[i][j] = MAT[i][j];
            }
        }
    }
    void GETDATA()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "EDGE FROM " << i << " TO " << j;
                cin >> AM[i][j];
            }
        }
    }
    void PUTDATA()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << AM[i][j] << "  ";
            }
            cout << endl;
        }
    }
};

void BFS(int vtx, int A[SIZE][SIZE])
{

    int n = SIZE;
    queue<int> Q;
    int visited[SIZE]{0};
    cout << vtx << ", " << flush;
    visited[vtx] = 1;
    Q.emplace(vtx);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int v = 1; v <= n; v++)
        {
            if (A[u][v] == 1 && visited[v] == 0)
            {
                cout << v << ", " << flush;
                visited[v] = 1;
                Q.emplace(v);
            }
        }
    }
    cout << endl;
}

void RDFS(int u, int A[][8], int n)
{
    static int visited[8]{0};
    if (visited[u] == 0)
    {
        cout << u << ", " << flush;
        visited[u] = 1;
        for (int v = 1; v < n; v++)
        {
            if (A[u][v] == 1 && visited[v] == 0)
            {
                RDFS(v, A, n);
            }
        }
    }
}

void DFS1(int u, int A[][8], int n)
{
    int visited[8]{0};
    stack<int> stk;
    stk.emplace(u);
    cout << u << ", " << flush;
    visited[u] = 1;
    int v = 0;
    while (!stk.empty())
    {
        while (v < n)
        {
            if (A[u][v] == 1 && visited[v] == 0)
            {
                stk.push(u);
                u = v;
                cout << u << ", " << flush;
                visited[u] = 1;
                v = -1;
            }
            v++;
        }
        v = u;
        u = stk.top();
        stk.pop();
    }
}

void DFS2(int u, int A[][8], int n)
{
    int visited[8]{0};
    stack<int> stk;
    stk.emplace(u);
    while (!stk.empty())
    {
        u = stk.top();
        stk.pop();
        if (visited[u] != 1)
        {
            cout << u << ", " << flush;
            visited[u] = 1;
            for (int v = n - 1; v >= 0; v--)
            {
                if (A[u][v] == 1 && visited[v] == 0)
                {
                    stk.emplace(v);
                }
            }
        }
    }
}

void PrintMST(int T[][SIZE - 2], int G[SIZE][SIZE])
{
    cout << "\nMinimum Spanning Tree Edges Using Prims Method \n"
         << endl;
    int sum{0};
    for (int i{0}; i < SIZE - 2; i++)
    {
        int c = G[T[0][i]][T[1][i]];
        cout << "[" << T[0][i] << "]---[" << T[1][i] << "] cost: " << c << endl;
        sum += c;
    }
    cout << endl;
    cout << "Total cost of MST: " << sum << endl;
}
void PrimsMST(int G[SIZE][SIZE], int n)
{
    int u;
    int v;
    int min{I};
    int track[SIZE];
    int T[2][SIZE - 2]{0};
    for (int i{1}; i < SIZE; i++)
    {
        track[i] = I;
        for (int j{i}; j < SIZE; j++)
        {
            if (G[i][j] < min)
            {
                min = G[i][j];
                u = i;
                v = j;
            }
        }
    }
    T[0][0] = u;
    T[1][0] = v;
    track[u] = track[v] = 0;
    for (int i{1}; i < SIZE; i++)
    {
        if (track[i] != 0)
        {
            if (G[i][u] < G[i][v])
            {
                track[i] = u;
            }
            else
            {
                track[i] = v;
            }
        }
    }
    for (int i{1}; i < n - 1; i++)
    {
        int k;
        min = I;
        for (int j{1}; j < SIZE; j++)
        {
            if (track[j] != 0 && G[j][track[j]] < min)
            {
                k = j;
                min = G[j][track[j]];
            }
        }
        T[0][i] = k;
        T[1][i] = track[k];
        track[k] = 0;
        for (int j{1}; j < SIZE; j++)
        {
            if (track[j] != 0 && G[j][k] < G[j][track[j]])
            {
                track[j] = k;
            }
        }
    }
    PrintMST(T, G);
}

void PrintMCST(int T[][SIZE - 2], int A[][E])
{
    cout << "\nMinimum Cost Spanning Tree Edges Using Kruskals Method\n"
         << endl;
    for (int i{0}; i < SIZE - 2; i++)
    {
        cout << "[" << T[0][i] << "]-----[" << T[1][i] << "] cost: " << endl;
    }
    cout << endl;
}
void Union(int u, int v, int s[])
{
    if (s[u] < s[v])
    {
        s[u] += s[v];
        s[v] = u;
    }
    else
    {
        s[v] += s[u];
        s[u] = v;
    }
}
int Find(int u, int s[])
{
    int x = u;
    int v = 0;

    while (s[x] > 0)
    {
        x = s[x];
    }
    while (u != x)
    {
        v = s[u];
        s[u] = x;
        u = v;
    }
    return x;
}
void KruskalsMCST(int A[3][9])
{
    int T[2][SIZE - 2];
    int track[E]{0};
    int set[SIZE] = {-1, -1, -1, -1, -1, -1, -1, -1};
    int i{0};
    while (i < SIZE - 2)
    {
        int min = I;
        int u{0};
        int v{0};
        int k{0};
        for (int j{0}; j < E; j++)
        {
            if (track[j] == 0 && A[2][j] < min)
            {
                min = A[2][j];
                u = A[0][j];
                v = A[1][j];
                k = j;
            }
        }
        if (Find(u, set) != Find(v, set))
        {
            T[0][i] = u;
            T[1][i] = v;
            Union(Find(u, set), Find(v, set), set);
            i++;
        }
        track[k] = 1;
    }
    PrintMCST(T, A);
}

int main()
{
    {
        int MAT[SIZE][SIZE] = {{0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 1, 1, 1, 0, 0, 0},
                               {0, 1, 0, 1, 0, 0, 0, 0},
                               {0, 1, 1, 0, 1, 1, 0, 0},
                               {0, 1, 0, 1, 0, 1, 0, 0},
                               {0, 0, 0, 1, 1, 0, 1, 1},
                               {0, 0, 0, 0, 0, 1, 0, 0},
                               {0, 0, 0, 0, 0, 1, 0, 0}};
        cout << "GRAPH IS \n"
             << "(1)-----------(2) \n"
             << " |             | \n"
             << " |             | \n"
             << " |             | \n"
             << " |             | \n"
             << " |             | \n"
             << "(4)-----------(3) \n"
             << "  \\          / \n"
             << "   \\        / \n"
             << "    \\      / \n"
             << "     \\    / \n"
             << "      \\  / \n"
             << "       (5) \n"
             << "      /  \\ \n"
             << "     /    \\ \n"
             << "    /      \\ \n"
             << "   /        \\ \n"
             << "  /          \\ \n"
             << "(6)          (7) \n";

        cout << "BFS Vertex: 1 -> " << flush;
        BFS(1, MAT);

        cout << "BFS Vertex: 4 -> " << flush;
        BFS(4, MAT);
        cout << endl
             << endl;
    }

    {
        int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 1, 1, 1, 0, 0, 0},
                       {0, 1, 0, 1, 0, 0, 0, 0},
                       {0, 1, 1, 0, 1, 1, 0, 0},
                       {0, 1, 0, 1, 0, 1, 0, 0},
                       {0, 0, 0, 1, 1, 0, 1, 1},
                       {0, 0, 0, 0, 0, 1, 0, 0},
                       {0, 0, 0, 0, 0, 1, 0, 0}};

        cout << "RDFS Vertex: 4 -> " << flush;
        RDFS(4, A, 8);
        cout << endl;
    }
    cout << endl;
    {
        int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 1, 1, 1, 0, 0, 0},
                       {0, 1, 0, 1, 0, 0, 0, 0},
                       {0, 1, 1, 0, 1, 1, 0, 0},
                       {0, 1, 0, 1, 0, 1, 0, 0},
                       {0, 0, 0, 1, 1, 0, 1, 1},
                       {0, 0, 0, 0, 0, 1, 0, 0},
                       {0, 0, 0, 0, 0, 1, 0, 0}};

        cout << "DFS1 Vertex: 4 -> " << flush;
        DFS1(4, A, 8);
        cout << endl;
    }
    cout << endl;
    {
        int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 1, 1, 1, 0, 0, 0},
                       {0, 1, 0, 1, 0, 0, 0, 0},
                       {0, 1, 1, 0, 1, 1, 0, 0},
                       {0, 1, 0, 1, 0, 1, 0, 0},
                       {0, 0, 0, 1, 1, 0, 1, 1},
                       {0, 0, 0, 0, 0, 1, 0, 0},
                       {0, 0, 0, 0, 0, 1, 0, 0}};

        cout << "DFS2 Vertex: 4 -> " << flush;
        DFS2(4, A, 8);
        cout << endl;
    }
    cout << endl;
    {
        int cost[SIZE][SIZE]{
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
        };

        PrimsMST(cost, SIZE - 1);
    }
    cout << endl
         << endl;
    {
        int edges[3][9] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
                           {2, 6, 3, 7, 4, 5, 7, 6, 7},
                           {25, 5, 12, 10, 8, 16, 14, 20, 18}};

        KruskalsMCST(edges);
    }
    return 0;
}