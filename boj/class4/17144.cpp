#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

const int DIR = 4;
const int MAX_N = 50;

int map[MAX_N][MAX_N], add[MAX_N][MAX_N];
int n, m, t;
vector<pair<int, int> > vacuums;

int dr[DIR] = {1, 0, -1, 0};
int dc[DIR] = {0, -1, 0, 1};

// void Print() {
//     cout << "#######\n";
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cout << map[i][j] << " ";
//         }
//         cout << "\n";
//     }
//     cout << "#######\n";
// }

bool isValid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

void Spread() {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(map[i][j] == -1 || map[i][j] == 0) continue;

            int amount = map[i][j] / 5;
            
            for (int k = 0; k < DIR; k++)
            {
                int nr = i + dr[k];
                int nc = j + dc[k];

                if(!isValid(nr, nc) || map[nr][nc] == -1) continue;

                map[i][j] -= amount;
                add[nr][nc] += amount;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            map[i][j] += add[i][j];
            add[i][j] = 0;
        }
    }
}

void RotateUp() {
    int cr, cc;
    tie(cr, cc) = vacuums[0];

    for (int i = cr-1; i > 0; i--)
    {
        map[i][0] = map[i-1][0];
    }

    for (int i = 0; i < m-1; i++)
    {
        map[0][i] = map[0][i+1];
    }

    for (int i = 0; i < cr; i++)
    {
        map[i][m-1] = map[i+1][m-1];
    }

    for (int i = m-1; i > 1; i--)
    {
        map[cr][i] = map[cr][i-1];
    }

    map[cr][1] = 0;
}

void RotateDown() {
    int cr, cc;
    tie(cr, cc) = vacuums[1];

    for (int i = cr+1; i < n-1; i++)
    {
        map[i][0] = map[i+1][0];
    }

    for (int i = 0; i < m-1; i++)
    {
        map[n-1][i] = map[n-1][i+1];
    }

    for (int i = n-1; i >= cr+1; i--)
    {
        map[i][m-1] = map[i-1][m-1];
    }

    for (int i = m-1; i > 1; i--)
    {
        map[cr][i] = map[cr][i-1];
    }

    map[cr][1] = 0;
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n >> m >> t;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == -1) vacuums.push_back({i, j});
        }
    }

    while (t--)
    {
        Spread();
        // Print();
        RotateUp();
        RotateDown();
        // Print();
    }
    

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(map[i][j] != -1) ans += map[i][j];
        }
    }

    cout << ans << "\n";
    
    return 0;
}