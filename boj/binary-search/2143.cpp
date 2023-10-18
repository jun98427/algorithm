#include<iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define MAX_N   1000

using namespace std;

long long arr[2][MAX_N+1];
int T, n, m;
unordered_map<long long, int> mapper;

int main() {
    cin >> T;

    cin >> n;
    int v;
    for (int i = 1; i <= n; i++)
    {
        cin >> v;
        arr[0][i] = arr[0][i-1] + v;
    }

    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> v;
        arr[1][i] = arr[1][i-1] + v;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            long long temp = arr[0][i] - arr[0][j];
            mapper[temp]++;
        }
    }

    long long ans = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            long long temp = arr[1][i] - arr[1][j];
            auto it = mapper.find(T - temp);
            if(it != mapper.end()) ans += it->second;
        }
    }
    
    cout << ans << endl;

    return 0;
}