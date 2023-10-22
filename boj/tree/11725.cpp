#include <iostream>
#include <vector>

#define MAX_N 100000

using namespace std;

int n;
vector<int> edges[MAX_N+1];
int parent[MAX_N+1];

void DFS(int cur, int p) {
    parent[cur] = p;

    for (int next : edges[cur])
    {
        if(next == p) continue;

        DFS(next, cur);
    }
}

int main() {
    cin >> n;

    int n1, n2;
    for (int i = 0; i < n-1; i++)
    {
        cin >> n1 >> n2;
        edges[n1].push_back(n2);
        edges[n2].push_back(n1);
    }

    DFS(1, 0);

    for (int i = 2; i <= n; i++)
    {
        cout << parent[i] << "\n";
    }

    return 0;
}