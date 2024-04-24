#include <iostream>
#include <queue>
#include <cstring>

#define MAX_N 1'000'000

using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    int stage[MAX_N+1];
    memset(stage, -1, sizeof(stage));

    stage[S] = 0;
    queue<int> que;
    que.push(S);

    int ret = -1;

    while (!que.empty())
    {
        int cur = que.front();
        que.pop();

        int v = stage[cur];

        if(cur == G) {
            ret = v;
            break;
        }

        if(cur+U <= F && stage[cur+U] == -1) {
            stage[cur+U] = v+1;
            que.push(cur+U);
        }

        if(cur - D >= 1 && stage[cur-D] == -1) {
            stage[cur-D] = v+1;
            que.push(cur-D);
        }
    }

    if(ret == -1) {
        cout << "use the stairs\n";
    }else cout << ret << "\n";
    
 
    return 0;
}