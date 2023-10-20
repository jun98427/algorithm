#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int val;

    priority_queue<long long, vector<long long>, greater<long long> > pq;

    for (int i = 0; i < n; i++)
    {
        cin >> val;
        pq.push(val);
    }

    long long ans = 0;

    while (m--)
    {
        long long v1 = pq.top();
        pq.pop();
        long long v2 = pq.top();
        pq.pop();

        long long t = v1 + v2;
        pq.push(t);
        pq.push(t);
    }

    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    
    cout << ans << endl;

    return 0;
}