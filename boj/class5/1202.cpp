#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

using ll = long long;

const int MAX_N = 300'000;

int bags[MAX_N];
pair<int, int> values[MAX_N];


int main() {
    // freopen("input.txt", "r" , stdin);
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> values[i].first >> values[i].second;
    }

    for (int i = 0; i < k; i++)
    {
        cin >> bags[i];
    }
    
    sort(values, values+n);
    sort(bags, bags+k);

    priority_queue<int> que;

    ll ans = 0;
    int idx = 0;
    for (int i = 0; i < k; i++)
    {
        while (true)
        {
            if(idx >= n || values[idx].first > bags[i]) break;

            que.push(values[idx++].second);
        }
        
        if(!que.empty()) {
            ans += que.top();
            que.pop();
        }
    }
    
    cout << ans << "\n";

    return 0;
}