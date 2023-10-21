#include <iostream>
#include <tuple>
#include <algorithm>
#include <queue>

#define MAX_N 100000

using namespace std;

tuple<int, int, int, int> arr[MAX_N];
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    int sm, sd, em, ed;
    for (int i = 0; i < n; i++)
    {
        cin >> sm >> sd >> em >> ed;
        arr[i] = make_tuple(sm, sd, em, ed);
    }

    sort(arr, arr+n);

    int ans = 0, j=-1;
    int tm, td, ttm, ttd;
    em = 3, ed = 1;

    priority_queue<pair<int, int> > pq;

    while(em != 12)
    {
        while (j+1 < n)
        {
            tie(tm, td, ttm, ttd) = arr[j+1];

            if(ttm < em || (ttm == em && ttd <= ed)) {
                j++;
                continue;
            }

            if(tm > em || (tm == em && td > ed)) {
                break;
            }

            j++;
            pq.push(make_pair(ttm, ttd));
        }
        
        if(pq.empty()) {
            ans = 0;
            break;
        }

        tie(tm, td) = pq.top();
        pq.pop();

        if(tm < em || (tm == em && td <= ed)) {
            ans = 0;
            break;
        }

        ans++;
        em = tm;
        ed = td;
    }

    cout << ans << endl;

    return 0;
}