#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

#define MAX_N 200000

using namespace std;

int ans, n;
pair<int, int> arr[MAX_N];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr+n);

    ans += 1;
    priority_queue<int, vector<int>, greater<int> >pq;
    pq.push(arr[0].second);

    for (int i = 1; i < n; i++)
    {
        if(pq.top() <= arr[i].first) {
            pq.pop();
            pq.push(arr[i].second);
        }else {
            ans++;
            pq.push(arr[i].second);
        }
    }
    
    cout << ans << endl;

    return 0;
}

