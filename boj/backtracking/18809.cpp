#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>

#define MAX_N       50
#define DIR_NUM     4
#define FLOWER      25001

using namespace std;

// 0 : 호수  1 : 배양액 x  2 : 배양액 o
int map[50][50];
int is_visited[50][50];

vector<pair<int, int> > at;
vector<pair<int, int> >chosed;
int N, M, R, G;
int ans;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

bool is_range(int r, int c) {
    return r >=0 && r < N && c >= 0 && c < M;
}

void solve() {
    memset(is_visited, 0, sizeof(is_visited));
    
    int cnt = 0, val, r, c, idx;
    queue<tuple<int, int, int> > que;

    for (int i = 0; i < R+G; i++)
    {
        tie(val, idx) = chosed[i];
        tie(r, c) = at[idx];

        // cout << "val : " << val << " r : " << r << " c : " << c << endl;

        is_visited[r][c] = val;
        que.push({val, r, c});
    }

    while (!que.empty())
    {
        
        tie(val, r, c) = que.front();
        que.pop();

        if(val != is_visited[r][c]) continue;

        int nr, nc, n_val;

        if(val > 0) n_val = val + 1;
        else n_val = val - 1;

        for (int i = 0; i < DIR_NUM; i++)
        {
            nr = r + dr[i];
            nc = c + dc[i];

            if(!is_range(nr, nc)) continue;

            if(is_visited[nr][nc] + n_val == 0) {
                cnt++;
                is_visited[nr][nc] = FLOWER;
            }else if(is_visited[nr][nc] == 0 && map[nr][nc] != 0) {
                is_visited[nr][nc] = n_val;
                que.push(make_tuple(n_val, nr, nc));
            }
        }
    }
    
    ans = max(ans, cnt);
}

void permutation(int idx, int r_remain, int g_remain) {
    if(r_remain == 0 && g_remain == 0) {
        solve();
        return;
    }

    if(idx == at.size()) return ;

    for (int i = idx; i < (int)at.size(); i++)
    {
        if(r_remain >= 0) {
            chosed.push_back({-1, i});
            permutation(i+1, r_remain-1, g_remain);
            chosed.pop_back();
        }

        if(g_remain >= 0) {
            chosed.push_back({1, i});
            permutation(i+1, r_remain, g_remain-1);
            chosed.pop_back();
        }

        permutation(i+1, r_remain, g_remain);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    cin >> N >> M >> R >> G;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];

            if(map[i][j] == 2) at.push_back({i, j});
        }
    }

    permutation(0, R, G);

    cout << ans << "\n";

    return 0;
}