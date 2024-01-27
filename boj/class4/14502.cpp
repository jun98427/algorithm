#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define MAX_N   8
#define DIR     4

using namespace std;

int map[MAX_N][MAX_N], copy_map[MAX_N][MAX_N];
int n, m;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int chose[3];
int ans = -1;
int emp;

vector<pair<int, int> > empties;
vector<pair<int, int> > viruses;

bool isValid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

void calc() {
    copy(&map[0][0], &map[0][0] + 64, &copy_map[0][0]);

    int r, c;
    for (int i = 0; i < 3; i++)
    {
        tie(r, c) = empties[chose[i]];
        copy_map[r][c] = 1;
    }

    queue<pair<int, int> >que;

    for(pair<int, int> it : viruses) {
        que.push(it);
    }

    int cnt = 0;
    while (!que.empty())
    {
        tie(r, c) = que.front();
        que.pop();

        for (int i = 0; i < DIR; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(!isValid(nr, nc)) continue;

            if(copy_map[nr][nc] == 0) {
                cnt++;
                copy_map[nr][nc] = 2;
                que.push({nr, nc});
            }
        }
    }

    ans = max(ans, emp - 3 - cnt);
    return ;
}

void permute(int cur, int c_idx) {
    if(cur == 3){
        calc();
        return ;
    }

    if(c_idx >= empties.size()) return ;

    chose[cur] = c_idx;
    permute(cur+1, c_idx+1);

    permute(cur, c_idx+1);
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];

            if(map[i][j] == 0) empties.push_back({i, j});
            else if(map[i][j] == 2) viruses.push_back({i, j});
        }
    }

    emp = (int)empties.size();

    permute(0, 0);

    cout << ans << "\n";

    return 0;
}