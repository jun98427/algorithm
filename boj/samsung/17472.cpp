#include <iostream>
#include <queue>
#include <tuple>

#define MAX_NUM     10
#define DIR_NUM     4
#define INF         1e9

using namespace std;

int n, m, ans;
int origin[MAX_NUM][MAX_NUM];
int map[MAX_NUM][MAX_NUM];

int num_of_city;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int edge[7][7];
int uf[7];
int dist[7];

bool is_valid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m && origin[r][c];
}

void BFS(int r, int c) 
{
    queue<pair<int, int> > que;
    que.push({r, c});

    map[r][c] = num_of_city;

    int y, x;
    while (!que.empty())
    {
        tie(y, x) = que.front();
        que.pop();

        for (int i = 0; i < DIR_NUM; i++)
        {
            int nr = y + dr[i];
            int nc = x + dc[i];

            if(is_valid(nr, nc) && map[nr][nc] != num_of_city)
            {
                map[nr][nc] = num_of_city;
                que.push({nr, nc});
            }
        }
    }
}

void identify(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(origin[i][j] == 1 && !map[i][j])
            {
                num_of_city++;
                BFS(i, j);
            }
        }
    }
}

void get_edges(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int from = map[i][j], to, d;
            if(from != 0)
            {
                // row
                int next = j+1;
                while (next < m)
                {
                    to = map[i][next];
                    if(from == to) break;

                    if(to != 0) 
                    {
                        d = next - j - 1;
                        if(d >= 2 && (edge[from][to] == 0 || edge[from][to] > d)){
                            edge[from][to] = d;
                            edge[to][from] = d;
                        }
                        break;
                    }
                    next++;
                }

                // col
                next = i+1;
                while (next < n)
                {
                    to = map[next][j];
                    if(from == to) break;

                    if(to != 0) 
                    {
                        d = next - i - 1;
                        if(d >= 2 && (edge[from][to] == 0 || edge[from][to] > d)){
                            edge[from][to] = d;
                            edge[to][from] = d;
                        }
                        break;
                    }
                    next++;
                }
            }
        }
    }
    
}

int Find(int x) {
    if(uf[x] == x) return x;
    return uf[x] = Find(uf[x]);
}

bool Union(int x, int y) {
    int py = Find(y);
    int px = Find(x);

    if(py == px) return false;

    uf[py] = px;
    return true;
}

int main() 
{   
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> origin[i][j];
        }
    }

    identify();
    get_edges();

    priority_queue<tuple<int, int, int> > pq;
    for (int i = 1; i < num_of_city; i++)
    {
        uf[i] = i;
        for (int j = i+1; j <= num_of_city; j++)
        {
            if(edge[i][j] != 0) pq.push(make_tuple(-edge[i][j], i, j));
        }
    }
    
    int from, to, d;
    while (!pq.empty())
    {
        tie(d, from, to) = pq.top();
        pq.pop();

        d = -d;

        if(Union(from, to)) ans += d;
    }

    int px = Find(1);
    for (int i = 2; i <= num_of_city; i++)
    {
        int py = Find(i);
        if(px != py) {
            ans = -1;
            break;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}