#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

#define MAX_V   100
#define DIR     4

using namespace std;

int map[MAX_V][MAX_V];
bool is_visited[MAX_V][MAX_V];
int counts[MAX_V][MAX_V];
int n, m;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isIn(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

bool BFS(int r, int c) {
    is_visited[r][c] = true;

    queue<pair<int, int> >que;
    vector<pair<int, int> > targets;
    que.push({r, c});

    int cr, cc;
    while (!que.empty())
    {
        tie(cr, cc) = que.front();
        que.pop();

        for (int i = 0; i < DIR; i++)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if(!isIn(nr, nc) || is_visited[nr][nc]) continue;

            if(map[nr][nc] == 0) {
                is_visited[nr][nc] = true;
                que.push({nr, nc});
            }else {
                counts[nr][nc]++;
                if(counts[nr][nc] > 1) {
                    is_visited[nr][nc] = true;
                    targets.push_back({nr, nc});
                }
            }
        }
    }

    for (pair<int, int> t : targets)
    {
        tie(cr, cc) = t;
        map[cr][cc] = 0;
    }
    
    return targets.size() > 0;
}

void init() {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            counts[i][j] = 0;
            is_visited[i][j] = false;
        }
        
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    
    int ans = 0;
    while (true)
    {
        if(!BFS(0, 0)) {
            break;   
        }
        ans++;
        init();
    }
    
    cout << ans << "\n";

    return 0;
}