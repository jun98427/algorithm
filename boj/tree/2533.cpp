#include <iostream>
#include <vector>

#define MAX_N 1000000

using namespace std;

vector<int> edge[MAX_N+1];
bool is_visited[MAX_N+1];
int dp[MAX_N+1][2];

int n;

void DFS(int cur) {
    dp[cur][1] = 1;

    for (int next : edge[cur])
    {
        if(is_visited[next]) continue;

        is_visited[next] = true;
        DFS(next);

        dp[cur][1] += min(dp[next][1], dp[next][0]);
        dp[cur][0] += dp[next][1];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;

    int n1, n2;
    for (int i = 0; i < n-1; i++)
    {
        cin >> n1 >> n2;
        edge[n1].push_back(n2);
        edge[n2].push_back(n1);    
    }

    is_visited[1] = true;
    DFS(1);

    cout << min(dp[1][0], dp[1][1]) << "\n";
    
    return 0;
}