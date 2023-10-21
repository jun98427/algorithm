#include <iostream>
#include <set>
#include <tuple>
#include <algorithm>

#define MAX_N   100000
#define INF     1e10

using namespace std;

int n, m;
int arr[MAX_N+1];
set<pair<int, int> > sets;

int get_max() {
    if(sets.empty()) return 0;
    return sets.rbegin()->first;
}

int get_min() {
    if(sets.empty()) return 0;
    return sets.begin()->first;
}


int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    sort(arr+1, arr+n+1);

    int j=0;

    long long ans = INF;

    for (int i = 1; i <= n; i++)
    {
        while(j+1 <= n && get_max() - get_min() < m)
        {
            j++;
            sets.insert(make_pair(arr[j], j));
        }

        long long gap = get_max() - get_min();

        if(gap < m) break;
        ans = min(ans, gap);
        
        sets.erase(make_pair(arr[i], i));
    }
    
    cout << ans << endl;

    return 0;
}