#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

#define MAX_N   100
#define MAX_H   100
#define DIR     4

using namespace std;

int n;
int dr[DIR] = {1, 0, -1, 0};
int dc[DIR] = {0, 1, 0, -1};

int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

bool isIn(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

void BFS(int r, int c, int h) {
    queue<pair<int, int> > que;
    que.push({r, c});

    visited[r][c] = true;

    int cr, cc;
    while (!que.empty())
    {
        tie(cr, cc) = que.front();
        que.pop();

        for(int i=0; i<DIR; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if(!isIn(nr, nc) || visited[nr][nc] || board[nr][nc] <= h) continue;

            visited[nr][nc] = true;
            que.push({nr, nc});
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin >> board[i][j];
    }

    int ret = 1;
    for(int h=1; h < 100; h++) {
        memset(visited, false, sizeof(visited));
        int temp = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(!visited[i][j] && board[i][j] > h) {
                    temp++;
                    BFS(i, j, h);
                }
            }
        }

        if(temp == 0) break;
        ret = max(ret, temp);
    }

    cout << ret << "\n";

    return 0;
}