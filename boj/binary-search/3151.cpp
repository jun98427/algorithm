#include <iostream>
#include <unordered_map>
#define MAX_N 10000

using namespace std;

int n;
int scores[MAX_N];
unordered_map<int, int> mapper;

int main() {
    cin >> n;

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];

        ans += mapper[-scores[i]];
        
        for (int j = 0; j < i; j++)
        {
            mapper[scores[i] + scores[j]]++;
        }
    }
    
    cout << ans << endl;

    return 0;
}