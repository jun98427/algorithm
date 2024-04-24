#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

const int MAX_N = 30'000;
const int MAX_K = 3'000;

int n, m, k, ans = -1;
int candy[MAX_N+1];

vector<int> friends[MAX_N+1];
int friend_cnt[MAX_N+1];
int can_get[MAX_N+1];
int dp[MAX_K+1];

// DFS 후 DP 가능할 듯
void BFS(int cur) {
    int f_cnt = 0;
    int c_cnt = 0;
    friend_cnt[cur] = -1;
    
    queue<int> que;
    que.push(cur);

    while (!que.empty())
    {
        int c = que.front();
        que.pop();

        f_cnt++;
        c_cnt += candy[c];

        for (int next : friends[c])
        {
            if(friend_cnt[next] == 0) {
                friend_cnt[next] = -1;
                que.push(next);
            }
        }
    }

    can_get[cur] = c_cnt;
    friend_cnt[cur] = f_cnt;
}


int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> candy[i];
    }

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if(friend_cnt[i] == 0) BFS(i);
    }

    for (int i = 1; i <= n; i++)
    {
        if(friend_cnt[i] == -1) continue;

        int f_cnt = friend_cnt[i];
        int c_cnt = can_get[i];

        for (int j = k-1; j >= f_cnt; j--)
        {
            dp[j] = max(dp[j], dp[j-f_cnt] + c_cnt);
        }
    }

    int ans = 0;

    for (int i = 1; i < k; i++)
    {
        ans = max(ans, dp[i]);
    }
    
    cout << ans << "\n";

    return 0;
}