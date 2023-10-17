#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>

#define MAX_N   10
#define INF     1e9

using namespace std;

int n;
int ans = INF;

vector<int> edge[MAX_N+1];
int values[MAX_N+1];
bool is_visited[MAX_N+1];
int team[MAX_N+1];

void DFS(int cur, int side){
    if(is_visited[cur]) return;

    is_visited[cur] = true;

    for (int next : edge[cur])
    {
        if(!is_visited[next] && team[next] == side) {
            DFS(next, side);
        }
    }
}

void Simulate(){
    memset(is_visited, false, sizeof(is_visited));
    
    DFS(1, 0);

    for (int i = 2; i <= n; i++)
    {
        if(team[i] != 0) {
            DFS(i, team[i]);
            break;
        }else if(!is_visited[i]){
            return ;
        }
    }

    int sum[2] = {0, 0};
    for (int i = 1; i <= n; i++)
    {
        if(!is_visited[i]) return ;

        sum[team[i]] += values[i];
    }

    int gap = abs(sum[0] - sum[1]);

    ans = min(ans, gap);
    return ;
}

void Comb(int idx, int opp_cnt) 
{
    if(idx == n+1) {
        if(opp_cnt != 0) Simulate();
        return;
    }
    team[idx] = 1;
    Comb(idx+1, opp_cnt+1);
    team[idx] = 0;

    Comb(idx+1, opp_cnt);
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> values[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int cnt, to; 
        cin >> cnt;

        while (cnt--)
        {
            cin >> to;
            edge[i].push_back(to);
        }
    }
    
    Comb(2, 0);

    cout << (ans != INF ? ans : -1) << endl;

    return 0;
}