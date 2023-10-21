#include <iostream>
#include <unordered_map>

#define MAX_N   30000
#define MAX_K   3000

using namespace std;

int n, d, k, c;
int arr[MAX_N];
int mapper[MAX_K+1];

int get_count() {
    int ret = 0;
    // cout << "------\n";
    for (int i = 1; i <= d; i++)
    {
        // cout << "i : " << i << " " <<mapper[i] << " ";
        if(mapper[i] != 0) ret++;
    }
    // cout << endl;
    return ret;
}

int main() {
    cin >> n >> d >> k >> c;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        if(i < k){
            mapper[val]++;
        }
        arr[i] = val;
    }

    int ans = get_count();
    if(mapper[c] == 0) ans++;

    for (int i = 1; i < n; i++)
    {
        int next_idx = (i + k - 1) % n;
        int prev = arr[i-1];

        // cout << "i : " << i << " next : " << next_idx << "\n";

        mapper[prev]--;
        mapper[arr[next_idx]]++;

        int temp = get_count();
        if(mapper[c] == 0) temp++;

        ans = max(ans, temp);
    }
    
    cout << ans << endl;

    return 0;
}