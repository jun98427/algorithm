#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 1000
#define MAX_H 20

using namespace std;

vector<pair<int, int> > edge[MAX_N+1];
int sparse_table[MAX_H][MAX_N+1];
int dist[MAX_N+1];

int n, m;

void DFS(int cur, int p) {
    sparse_table[0][cur] = p;

    int next, d;
    for(auto it : edge[cur])
    {
        tie(next, d) = it;
        
        if(next == p) continue;

        dist[next] = dist[cur] + d;
        DFS(next, cur);
    }
}

int main() {
    cin >> n >> m;

    int n1, n2, d;
    for (int i = 0; i < n-1; i++)
    {
        cin >> n1 >> n2 >> d;

        edge[n1].push_back({n2, d});
        edge[n2].push_back({n1, d});
    }

    DFS(1, 0);
    


    return 0;
}