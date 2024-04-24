#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

const int MAX_N = 10000;
pair<long long, long long> points[MAX_N];

int main() {
    freopen("input.txt", "r", stdin);
    long double ans = 0;
    int n;
    long long x1, y1, x2, y2, x3, y3;

    cin >> n;
    cin >> x1 >> y1;

    for (int i = 0; i < n-1; i++)
    {
        cin >> points[i].first >> points[i].second;
    }

    for (int i = 0; i < n-2; i++)
    {
        tie(x2, y2) = points[i];
        tie(x3, y3) = points[i+1];

        long double temp = x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2;
        ans += temp / 2;
    }

    cout << fixed;
    cout.precision(1);
    cout << abs(ans) << "\n";

    return 0;
}