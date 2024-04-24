#include <iostream>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

const int MAX_N = 1500;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int> > que;

    for(int i=0; i<n*n; i++) {
        int v;
        cin >> v;

        que.push(v);
        if(que.size() > n) que.pop();
    }

    cout << que.top() << "\n";

    return 0;
}