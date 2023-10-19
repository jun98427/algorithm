#include <iostream>
#include <stack>
#include <tuple>
#include <cstdio>

#define MAX_N   500000

using namespace std;

int n;

int main() {
    // freopen("input.txt", "r", stdin);
    long long ans = 0;
    stack<pair<int, int> > s;

    cin >> n;

    int val;

    for (int i = 0; i < n; i++)
    {
        cin >> val;

        while (!s.empty())
        {
            if(s.top().first >= val)
            {
                break;
            }

            ans += s.top().second;
            s.pop();
        }

        if(s.empty()) s.push({val, 1});
        else if(s.top().first == val) {
            ans += s.top().second;
            s.top().second++;
            if(s.size() >= 2) ans++;
        }else {
            ans += 1;
            s.push({val, 1});
        }
    }

    cout << ans << endl;

    return 0;
}