#include <iostream>
#include <queue>
#include <cstring>
#include <stack>

#define MAX_NK 200'000

using namespace std;

int par[MAX_NK];
int visited[MAX_NK];

int main() {
    // freopen("in.txt", "r", stdin);
    int start, target;
    cin >> start >> target;

    memset(visited, -1, sizeof(visited));

    visited[start] = 0;
    par[start] = -1;

    queue<int> que;
    que.push(start);

    while (!que.empty())
    {
        int cur = que.front();
        que.pop();

        if(cur == target) break;

        int v = visited[cur];

        if(cur - 1 >= 0 && visited[cur-1] == -1) {
            visited[cur-1] = v+1;
            par[cur-1] = cur;
            que.push(cur-1);
        }

        if(cur < target && visited[cur+1] == -1) {
            visited[cur+1] = v+1;
            par[cur+1] = cur;
            que.push(cur+1);
        }

        if(cur < target && visited[cur*2] == -1) {
            visited[cur*2] = v+1;
            par[cur*2] = cur;
            que.push(cur*2);
        }
    }

    cout << visited[target] << "\n";

    stack<int> st;
    int cur = target;
    while (cur != -1)
    {
        st.push(cur);
        cur = par[cur];
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    cout << "\n";
    
    return 0;
}