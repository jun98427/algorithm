#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int MAX_N = 50;

vector<int> edges[MAX_N+1];
int scores[MAX_N+1];
int n;

int Solve(int s) {
    bool is_visited[MAX_N+1] = {false, };

    queue<pair<int, int> >que;
    que.push({s, 0});

    is_visited[s] = true;
    int re = 0;

    while (!que.empty())
    {
        int cur, d;
        tie(cur, d) = que.front();
        que.pop();

        re = max(re, d);

        for (int next : edges[cur])
        {
            if(!is_visited[next]){
                is_visited[next] = true;
                que.push({next, d+1});
            }
        }
    }
    
    return re;
}

int main() {
    // freopen("in.txt","r", stdin);
    cin >> n;

    while (true)
    {
        int a, b;
        cin >> a >> b;

        if(a == -1 && b == -1) break;

        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int sc = 1e8, sc_num = 0;
    for(int i=1; i<=n; i++) {
        scores[i] = Solve(i);
        if(sc == scores[i]) sc_num++;
        else if(sc > scores[i]) {
            sc_num = 1;
            sc = scores[i];
        }
    }

    cout << sc << " " << sc_num <<"\n";

    for(int i=1; i<=n; i++) {
        if(scores[i] == sc) cout << i << " ";
    }
    cout << "\n";

    return 0;
}