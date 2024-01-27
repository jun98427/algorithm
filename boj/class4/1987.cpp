#include <iostream>

#define DIR 4

using namespace std;

char board[20][20];
int n, m, ans;
bool is_visited[20][20];
bool check[26];

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

bool is_in(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c <m;
}

void DFS(int r, int c, int depth) {
    ans = max(ans, depth);

    int nr, nc;
    for (int i = 0; i < DIR; i++)
    {
        nr = r + dr[i];
        nc = c + dc[i];

        if(!is_in(nr, nc)) continue;

        if(check[board[nr][nc] - 'A']) continue;

        check[board[nr][nc] - 'A'] = true;
        DFS(nr, nc, depth+1);
        check[board[nr][nc] - 'A'] = false;
    }
}


int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    check[board[0][0] - 'A'] = true;
    DFS(0, 0, 1);

    cout << ans << "\n";
    
    return 0;
}