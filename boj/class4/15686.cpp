#include <iostream>
#include <vector>
#include <tuple>

#define INF     1e8+7

using namespace std;

vector<pair<int, int> > store, house;
vector<int> chose;
int ans = INF;

void calc() {
    int dist[101];
    for (int i = 0; i < house.size(); i++)
    {
        dist[i] = INF;
    }

    for (int at : chose)
    {
        int x, y, x1, y1;
        tie(x, y) = store[at];

        for (int i = 0; i < house.size(); i++)
        {
            tie(x1, y1) = house[i];

            int d = abs(x1 - x) + abs(y1 - y);

            if(dist[i] > d) dist[i] = d;
        }
    }

    int sum = 0;
    for (int i = 0; i < house.size(); i++)
    {
        sum += dist[i];
    }
    
    ans = min(ans, sum);
}

void permute(int idx, int re) {
    if(re == 0) {
        calc();
        return ;
    }

    if(idx >= store.size()) {
        return ;
    }

    chose.push_back(idx);
    permute(idx+1, re-1);
    chose.pop_back();

    permute(idx+1, re);
}




int main() {
    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val;
            cin >> val;

            if(val == 1) house.push_back({i, j});
            else if(val == 2) store.push_back({i, j});
        }
    }

    permute(0, m);

    cout << ans << "\n";

    return 0;
}