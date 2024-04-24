#include <iostream>
#include <map>

using namespace std;

using ll = long long;

int arr[41], m, n;
ll cnt;

map<int, int> mapper;

void left(int idx, int sum) {
    if(idx < 0) {
        mapper[sum]++;
        return ;
    }

    left(idx-1, sum);
    left(idx-1, sum + arr[idx]);
}

void right(int idx, int sum) {
    if(idx >= n) {
        cnt += mapper[m - sum];
        return ;
    }

    right(idx+1, sum);
    right(idx+1, sum + arr[idx]);
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> arr[i];

    int s = (n >> 1);

    left(s-1, 0);
    right(s, 0);

    cout << (m == 0 ? cnt-1 : cnt) << "\n";

    return 0;
}