#include <iostream>
#include <string>
#include <queue>
#include <tuple>

#define MAX_NM  1000
#define MAX_K   10
#define DIR     4

using namespace std;

int n, m, k;
int board[MAX_NM][MAX_NM];
int visited[MAX_K+1][MAX_NM][MAX_NM];

int dr[DIR] = {1, 0, -1, 0};
int dc[DIR] = {0, 1, 0, -1};

bool isIn(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

int Solve() {
    queue<tuple<int, int, int> > que;
    que.push({0, 0, 0});
    visited[0][0][0] = 1;

    int r, c, ck;
    while (!que.empty())
    {
        tie(r, c, ck) = que.front();
        que.pop();

        int d = visited[ck][r][c];

        // cout << "r : " << r << " c : " << c << " ck : " << ck << " d : " << d << "\n";

        if(r == n-1 && c == m-1) return d;

        bool is_night = (d % 2 == 0);
        bool is_exist = false; 

        for(int i=0; i<DIR; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(!isIn(nr, nc)) continue;
            
            if(is_night && board[nr][nc] == 1) {
                // cout << "night" << endl;
                is_exist = true;
                continue;
            }

            int nk = ck + board[nr][nc];
            if(nk > k || visited[nk][nr][nc]) continue;

            visited[nk][nr][nc] = d+1;
            que.push({nr, nc, nk});
        }

        if(is_exist) {
            visited[ck][r][c] = d+1;
            que.push({r, c, ck});
        }
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("in.txt", "r", stdin);
    cin >> n >> m >> k;

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;

        for(int j=0; j<m; j++) board[i][j] = str[j] - '0';
    }

    int ans = Solve();

    cout << ans << "\n";

    return 0;
}