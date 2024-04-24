#include <iostream>
// #include <cstring>

using namespace std;

const int MAX_N = 1000;
const int DIR   = 4;

enum State{
    State_E,
    State_V,
    State_F,
};

int map[MAX_N][MAX_N];
State check[MAX_N][MAX_N];

// U D L R
int dr[DIR] = {-1, 1, 0, 0};
int dc[DIR] = {0, 0, -1, 1};

int n, m;

// search
bool DFS(int r, int c) {
    if(check[r][c] == State_F) return false;
    
    if(check[r][c] == State_V) return true; 

    check[r][c] = State_V;

    int d = map[r][c];
    int nr = r + dr[d];
    int nc = c + dc[d];

    bool ret = DFS(nr, nc);

    check[r][c] = State_F;

    return ret;
}


int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    
    char cmd;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> cmd; 
            if(cmd == 'U') map[i][j] = 0;
            else if(cmd == 'D') map[i][j] = 1;
            else if(cmd == 'L') map[i][j] = 2;
            else map[i][j] = 3;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(check[i][j] == State_E) {
                if(DFS(i, j)) cnt++;
            }
        }
    }
    
    cout << cnt << "\n";


    return 0;
}