#include <iostream>
#include <vector>
#include <queue>

#define MAX_N   50
#define MAX_M   50

using namespace std;

bool is_visited[MAX_N+1];
bool tell_true[MAX_M];
vector<int> party[MAX_M];
vector<int> participate[MAX_N+1];

int n, m;

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;

    int k, idx;
    cin >> k;

    queue<int> know_truth;

    while (k--)
    {
        cin >> idx;
        know_truth.push(idx);
        is_visited[idx] = true;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> k;
        while (k--)
        {
            cin >> idx;
            participate[idx].push_back(i);
            party[i].push_back(idx);
        }
    }

    // bfs 가능?
    while (!know_truth.empty())
    {
        int cur = know_truth.front();
        know_truth.pop();

        for (int p : participate[cur])
        {
            if(tell_true[p]) continue;
            tell_true[p] = true;

            for (int u : party[p])
            {
                if(!is_visited[u]) {
                    is_visited[u] = true;
                    know_truth.push(u);
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        if(!tell_true[i]) ans++;
    }
    
    cout << ans << "\n";

    return 0;
}