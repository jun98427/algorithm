#include <iostream>
#include <vector>

#define MAX_N 50

using namespace std;

int n;
int parent[MAX_N];
int leaf[MAX_N];
bool is_visited[MAX_N];

vector<int> edge[MAX_N];

void DFS(int cur) {
    bool is_leaf = true;

    for (int next : edge[cur])
    {
        is_leaf = false;
        is_visited[next] = true;

        DFS(next);

        leaf[cur] += leaf[next];
    }
    
    if(is_leaf) leaf[cur] = 1;
    return ;
}

int main() {
    cin >> n;

    int r = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> parent[i];

        if(parent[i] == -1) r = i;
        else {
            edge[parent[i]].push_back(i);
        }
    }

    int deleted;
    cin >> deleted;

    is_visited[r] = true;
    DFS(r);

    int ans = leaf[r] - leaf[deleted];

    if(edge[parent[deleted]].size() == 1) ans += 1;

    cout << ans << "\n";

    return 0;
}