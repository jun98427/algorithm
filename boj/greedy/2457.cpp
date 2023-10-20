#include <iostream>
#include <tuple>
#include <algorithm>

#define MAX_N 100000

using namespace std;

tuple<int, int, int, int> arr[MAX_N];
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n;

int main() {
    cin >> n;

    int sm, sd, em, ed;
    for (int i = 0; i < n; i++)
    {
        cin >> sm >> sd >> em >> ed;
        arr[i] = make_tuple(sm, sd, em, ed);
    }

    sort(arr, arr+n);

    int ans = 0, j;
    em = 2, ed = 28;

    for (int i = 0; i < n; i++)
    {
        int j = i-1;
        while (j+1 < n)
        {
            int tm, td, ttm, ttd;
            tie(tm, td, ttm, ttd) = arr[j+1];

            if(tm > em || (tm == em && td > ed)) break;

            ttd -= 1;
            if(ttd == 0) {
                ttm -= 1;
                ttd = month[ttm];
            }

            if(ttm > em || (ttm == em && ttd > ed)) {
                em = ttm;
                ed = ttd;
            }
            j++;
        }

        if(j == i-1) {
            ans = 0;
            break;
        }

        ans ++;

        if(em == 12 || (em == 11 && ed >= 30)) break;
        
        i = j;
    }

    cout << ans << endl;

    return 0;
}