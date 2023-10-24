#include <iostream>

#define MAX_N 100000

using namespace std;
using ll = long long;

ll ans;

struct Node {
    int left;
    int right;
};

Node node_pool[MAX_N+1];
bool is_visited[MAX_N+1];
int n, cnt;

void DFS(int cur) {
    Node c = node_pool[cur];    

    if(c.left != -1) {
        // cout << cur << " ";
        ans++;
        DFS(c.left);
        if(cnt != n) ans++;
    }

    if(!is_visited[cur]) {
        is_visited[cur] = true;
        cnt++;
    }

    if(c.right != -1) {
        ans++;
        // cout << cur << " ";
        DFS(c.right);
        if(cnt != n) ans++;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n;

    int cur, l, r;
    for (int i = 0; i < n; i++)
    {
        cin >> cur >> l >> r;
        node_pool[cur].left = l;
        node_pool[cur].right = r;
    }
    
    DFS(1);
    // cout << "\n";
    cout << ans << "\n";

    return 0;
}