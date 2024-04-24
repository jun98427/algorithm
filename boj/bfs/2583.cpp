#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

#define MAX_NM  100
#define DIR     4

using namespace std;

bool board[MAX_NM][MAX_NM];
int n, m, k;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

bool isIn(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

int BFS(int r, int c) {
    queue<pair<int, int> >que;
    que.push({r, c});

    board[r][c] = true;

    int ret = 0;

    int cr, cc;
    while (!que.empty())
    {
        tie(cr, cc) = que.front();
        que.pop();
        ret++;

        for(int i=0; i<DIR; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if(!isIn(nr, nc) || board[nr][nc]) continue;

            board[nr][nc] = true;
            que.push({nr, nc});
        }
    }

    return ret;
}

int main() {
    // freopen("in.txt", "r", stdin);
    cin >> n >> m >> k;

    int r1, c1, r2, c2;
    while (k--)
    {
        cin >> c1 >> r1 >> c2 >> r2;

        for(int i=r1; i<r2; i++) {
            for(int j=c1; j<c2; j++) board[i][j] = true;
        }
    }

    int ans = 0;
    vector<int> v;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!board[i][j]) {
                ans++;
                v.push_back(BFS(i, j));
            }
        }
    }

    sort(v.begin(), v.end());

    cout << ans << "\n";

    for(int val : v) cout << val << " ";
    cout << "\n";
    
    return 0;
}
