#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 32000;

int incomes[MAX_N+1];
vector<int> edges[MAX_N+1];

int main() {
    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    int frm, to;
    for (int i = 0; i < m; i++)
    {
        cin >> frm >> to;
        incomes[to]++;
        edges[frm].push_back(to);
    }

    queue<int> que;
    for (int i = 1; i <= n; i++)
    {
        if(incomes[i] == 0) que.push(i);
    }

    while (!que.empty())
    {
        int cur = que.front();
        que.pop();

        cout << cur << " ";

        for(int next : edges[cur])
        {
            incomes[next]--;
            if(incomes[next] == 0) que.push(next);
        }
    }
    
    cout << "\n";

    return 0;
}