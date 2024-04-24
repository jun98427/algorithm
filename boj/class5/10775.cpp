#include <iostream>

using namespace std;

const int MAX_G = 100'000;
const int MAX_P = 100'000;

// nlogn까지 가능

int parent[MAX_G+1];

int findParent(int x) {
    if(x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

void Union(int v1, int v2) {
    int p1 = findParent(v1);
    int p2 = findParent(v2);

    if(p1 < p2) parent[p2] = p1;
    else parent[p1] = p2;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int g, p;
    cin >> g >> p;

    for (int i = 1; i <= g; i++)
    {
        parent[i] = i;
    }

    int ans = 0;

    for (int i = 0; i < p; i++)
    {
        int t;
        cin >> t;

        int tmp = findParent(t);
        if(tmp == 0) break;

        ans++;
        Union(tmp, tmp-1);
    }
    
    cout << ans << "\n";

    return 0;
}