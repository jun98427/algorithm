#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 32'000;

int incomes[MAX_N+1];
vector<int> edges[MAX_N+1];

int main() {
    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        incomes[b]++;
        edges[a].push_back(b);
    }

    priority_queue<int> que;
    for (int i = 1; i <= n; i++)
    {
        if(incomes[i] == 0) que.push(-i);
    }

    while (!que.empty())
    {
        int c = que.top();
        que.pop();

        c = -c;
        cout << c << " ";

        for (int next : edges[c])
        {
            incomes[next]--;
            if(incomes[next] == 0) que.push(-next);
        }
    }

    cout << "\n";
    
    return 0;
}