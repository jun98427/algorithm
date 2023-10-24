#include <iostream>
#include <vector>

#define MAX_N 100000

using namespace std;
using ll = long long;

ll arr[MAX_N+1];
vector<int> edge[MAX_N+1];
int n, m;

void DFS(int cur) {
    for (int next : edge[cur])
    {
        arr[next] += arr[cur];
        DFS(next);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    
    int p, r=-1;
    for (int i = 1; i <= n; i++)
    {
        cin >> p;
        if(p != -1) edge[p].push_back(i);
        else r = i;
    }

    int node, val;
    while (m--)
    {
        cin >> node >> val;
        arr[node] += val;
    }

    DFS(r);

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}