#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1000;

int incomes[MAX_N+1];

vector<int> edges[MAX_N+1];

int main() {
    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int cnt, prev = -1, cur;
        cin >> cnt;

        while (cnt--)
        {
            cin >> cur;

            if(prev == -1) {
                prev = cur;
            }else {
                incomes[cur]++;
                edges[prev].push_back(cur);
                prev = cur;
            }
        }
    }

    queue<int> que;
    for (int i = 1; i <= n; i++)
    {
        if(incomes[i] == 0) que.push(i);
    }

    vector<int> ans;

    while (!que.empty())
    {
        int cur = que.front();
        que.pop();

        ans.push_back(cur);

        for (int next : edges[cur])
        {
            incomes[next]--;
            if(incomes[next] == 0) que.push(next);
        }
    }
    
    if(ans.size() != n) cout << 0 << "\n";
    else {
        for (int a : ans)
        {
            cout << a << "\n";
        }
        
    }
    
    return 0;
}