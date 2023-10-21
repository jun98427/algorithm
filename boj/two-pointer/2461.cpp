#include <iostream>
#include <algorithm>

#define MAX_CNT 1000000
#define MAX_N   1000
#define INF     1e9

using namespace std;


int n, m;
int ans = INF;
pair<int, int> arr[MAX_CNT];
int is_visited[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    int idx = 0;
    int val, l = n * m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> val;
            arr[idx++] = make_pair(val, i);
        }
    }

    sort(arr, arr+l);

    int j = n-1, check = 0;

    for (int i = 0; i < n; i++)
    {
        int at = arr[i].second;
        is_visited[at]++;
        if(is_visited[at] == 1) check++;
    }

    for (int i = 0; i < l - n; i++)
    {
        // cout << "i : " << i << " j : " << j << " check : " << check << endl;
        while (j+1 < l && check != n)
        {
            j++;
            int at = arr[j].second;
            is_visited[at]++;
            if(is_visited[at] == 1) check++;
        }
        
        // cout << "i : " << i << " j : " << j << " check : " << check << endl;

        if(check != n) break;

        ans = min(ans, arr[j].first - arr[i].first);

        is_visited[arr[i].second]--;
        if(is_visited[arr[i].second] == 0) check--;
    }
    
    cout << ans << endl;

    return 0;
}