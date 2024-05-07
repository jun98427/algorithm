#include <iostream>

#define MAX_N   1000

using namespace std;

// n^2 으로 풀어도 될 듯
int arr[MAX_N];
int dp[MAX_N], P[MAX_N];
int n;

void printRoute(int v) {
    if(v == P[v]) {
        cout << arr[v] << ' ';
        return ;
    }
    printRoute(P[v]);
    cout << arr[v] << ' ';
}

int main() {
    // freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];

    int max_val = 0, idx = 0;

    for(int i=0; i<n; i++) {
        dp[i] = 1;
        P[i] = i;

        for(int j=0; j<i; j++) {
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1 ) {
                dp[i] = dp[j] + 1;
                P[i] = j;
            }
        }

        if(dp[i] > max_val) {
            max_val = dp[i];
            idx = i;
        }
    }

    cout << max_val << "\n";
    printRoute(idx);
    cout << "\n";

    return 0;
}