#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N   100000
#define INF     200001

using namespace std;

bool is_visited[MAX_N*2];
int dist[MAX_N*2];

int n, k;

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n >> k;

    for (int i = 0; i < MAX_N*2; i++)
    {
        dist[i] = INF;
    }

    dist[k] = 0;
    

    priority_queue<pair<int, int> > que;
    que.push({0, k});

    int cur, d, ans;
    while (!que.empty())
    {
        tie(d, cur) = que.top();

        // cout << "cur : " << cur << " d : " << -d << "\n"; 
        que.pop();

        if(cur == n) 
        {
            ans = -d;
            break;
        }

        if(is_visited[cur]) continue;
        is_visited[cur] = true;

        if(cur % 2 == 0 && cur > n) 
        {
            que.push({d, cur/2});    
        }

        if(!is_visited[cur+1] || dist[cur+1] > -d+1)
        {
            dist[cur+1] = -d+1;
            que.push({d-1, cur+1});
        } 

        if(cur-1 >= 0 && (!is_visited[cur-1] || dist[cur-1] > -d+1)) {
            dist[cur-1] = -d + 1;
            que.push({d-1, cur-1});
        }
    }
    
    cout << ans << "\n";

    return 0;
}
