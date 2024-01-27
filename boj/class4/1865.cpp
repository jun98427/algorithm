#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N   500
#define INF     1e8+7

using namespace std;

int n;
vector<tuple<int, int, int> > edge;

bool solve() {
    int dist[MAX_N+1];
    for (int i = 1; i <= n; i++)
    {
        dist[i] = 0;
    }

    for (int i = 0; i < n-1; i++)
    {
        for (tuple<int, int, int> it : edge)
        {
            int from, to, w;
            tie(from, to, w) = it;

            if(dist[to] > dist[from] + w) dist[to] = dist[from] + w;
        }
    }

    for (tuple<int, int, int> it : edge)
    {
        int from, to, w;
        tie(from, to, w) = it;

        if(dist[to] > dist[from] + w) return true;
    }
    
    return false;
}



int main() {
    // freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc; 

    while(tc--) {
        int m, w, from, to, weight;
        cin >> n >> m >> w;

        edge.clear();

        while (m--)
        {
            cin >> from >> to >> weight;

            edge.push_back({from, to, weight});
            edge.push_back({to, from, weight});
        }

        while (w--)
        {
            cin >> from >> to  >> weight;
            
            edge.push_back({from, to, -weight});
        }

        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}