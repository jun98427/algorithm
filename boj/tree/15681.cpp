#include <iostream>
#include <vector>

#define MAX_NODE 100000

using namespace std;

vector<int> edge[MAX_NODE+1];
int sub[MAX_NODE+1];

int n, r, q;

void DFS(int cur, int p) {
    sub[cur]++;

    for (int next : edge[cur])
    {
        if(next == p) continue;

        DFS(next, cur);
        sub[cur] += sub[next];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    cin >> n >> r >> q;

    int n1, n2;
    for (int i = 0; i < n-1; i++)
    {
        cin >> n1 >> n2;

        edge[n1].push_back(n2);
        edge[n2].push_back(n1);
    }

    DFS(r, 0);
    
    while (q--)
    {
        cin >> n1;
        cout << sub[n1] << "\n";
    }
    
    return 0;
}