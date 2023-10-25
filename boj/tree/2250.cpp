#include <iostream>
#include <vector>

#define MAX_N   10000
#define INF     1e8

using namespace std;

int left_cnt[MAX_N+1];
int min_x_val[MAX_N+1];
int max_x_val[MAX_N+1];
int income[MAX_N+1];
int cnt;
int max_depth;

// 중위 탐색으로 하면 x 값을 구할 수 있음
// depth 별 min_x와 max_x 이렇게 두면 될듯

struct Node {
    int l, r;
};

Node node_pool[MAX_N+1];

void DFS(int cur, int d) { 
    Node c = node_pool[cur];
    max_depth = max(max_depth, d);

    if(c.l != -1) {
        DFS(c.l, d+1);
    }

    min_x_val[d] = min(min_x_val[d], ++cnt);
    max_x_val[d] = max(max_x_val[d], cnt);

    if(c.r != -1) {
        DFS(c.r, d+1);
    }
}

int main() {
    int n;
    cin >> n;

    int c, l_child, r_child;
    for (int i = 1; i <= n; i++)
    {
        cin >> c >> l_child >> r_child;
        
        node_pool[c].l = l_child;
        node_pool[c].r = r_child;

        if(l_child != -1) income[l_child]++;
        if(r_child != -1) income[r_child]++;

        min_x_val[i] = INF;
    }

    int r = 0;
    for (int i = 1; i <= n; i++)
    {
        if(income[i] == 0){
            r = i;
            break;
        }
    }
    
    DFS(r, 1);

    int width = 1;
    int depth = 1;
    for (int i = 2; i <= max_depth; i++)
    {
        if(max_x_val[i] - min_x_val[i]+1 > width) {
            width = max_x_val[i] - min_x_val[i]+1;
            depth = i;
        }
    }

    cout << depth << " " << width << "\n";

    return 0;
}

