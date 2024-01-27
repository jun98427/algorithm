#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

const int MAX_N = 20;
const int DIR   = 4;

int dist[MAX_N][MAX_N];
int map[MAX_N][MAX_N];
int n, consume, build = 2;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isValid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n && dist[r][c] == -1;
}

pair<int, int> Search(int r, int c) {
    memset(dist, -1, sizeof(dist));
    int tar_r = -1, tar_c = -1, cost = -1;

    queue<pair<int, int> > que;
    dist[r][c] = 0;
    que.push({r, c});

    int cr, cc;
    while (!que.empty())
    {
        tie(cr, cc) = que.front();
        que.pop();
        // cout << "cr : " << cr << " cc : " << cc << "\n";

        int d = dist[cr][cc];
        if(cost != -1 && cost <= d) break;

        for (int i = 0; i < DIR; i++)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if(!isValid(nr, nc) || map[nr][nc] > build) continue;
            dist[nr][nc] = d+1;

            if(map[nr][nc] == build || map[nr][nc] == 0)
            {
                que.push({nr, nc});
            }else if(cost == -1 || tar_r > nr || (tar_r == nr && tar_c > nc)){
                tar_r = nr;
                tar_c = nc;
                cost = d+1;
            }
        }
    }

    return make_pair(tar_r, tar_c);
}


int main() {
    // freopen("input.txt", "r", stdin);
    int r, c;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 9) {
                r = i;
                c = j;
                map[i][j] = 0;
            }
        }
    }

    int ans = 0;

    while (true)
    {
        pair<int, int> t = Search(r, c);
        tie(r, c) = t;
        if(r == -1 || c == -1) break;

        ans += dist[r][c];
        map[r][c] = 0;

        consume++;
        if(build == consume) {
            consume = 0;
            build++;
        }
    }
    
    cout << ans << "\n";

    return 0;
}