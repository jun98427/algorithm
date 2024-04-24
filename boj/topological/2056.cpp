#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

const int MAX_N = 10'000;

int n, in[MAX_N+1], t[MAX_N+1];
vector<int> out[MAX_N+1];


int main() {
    // freopen("in.txt","r", stdin);
    cin >> n;

    priority_queue<pair<int, int> >pq;

    for(int i=1; i<=n; i++) {
        cin >> t[i] >> in[i];

        for(int j=0; j<in[i]; j++) {
            int v;
            cin >> v;
            out[v].push_back(i);
        }

        if(in[i] == 0) {
            pq.push({-t[i], i});
        }
    }

    int ans = 0;
    while (!pq.empty())
    {
        int cur, d;
        tie(d, cur) = pq.top();
        pq.pop();

        d = -d;
        ans = max(ans, d);
        // cout << "cur : " << cur;
        for(int next : out[cur]){
            // cout << " next : " << next << " in " << in[next] << "\n";
            in[next]--;
            if(in[next] == 0) {
                pq.push({-(d+t[next]), next});
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
