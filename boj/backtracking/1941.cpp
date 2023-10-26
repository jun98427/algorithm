#include <iostream>
#include <queue>
#include <cstring>

#define N           25
#define DIR_NUM     4
using namespace std;

char map[N];
int ans;
int numbers[7] = {5, 6, 7, 8, 9, 13, 18};
bool chosed[N], is_visited[N];
int add[DIR_NUM] = {1, -1, -5, 5};

bool is_connected() {
    memset(is_visited, false, sizeof(is_visited));
    int cnt = 0;

    queue<int> que;
    que.push(numbers[0]);

    while (!que.empty())
    {
        int cur = que.front();
        que.pop();

        if(is_visited[cur]) continue;

        is_visited[cur] = true;
        cnt++;

        int div = cur % 5;

        for (int i = 0; i < DIR_NUM; i++)
        {
            if((div == 4 && i == 0) ||(div == 0 && i == 1) ) continue;
            int next = cur + add[i];

            if(next < 0 || next >= 25) continue;

            if(!is_visited[next] && chosed[next]) que.push(next);
        }
    }

    return cnt == 7;
}

void permutation(int idx, int depth, int cnt) {
    if(depth == 7) {
        if(cnt >= 4 && is_connected()) ans++;

        return ;
    }

    if(idx == N) return ;

    for (int i = idx; i < N; i++)
    {
        chosed[i] = true;
        numbers[depth] = i;
        int t_cnt = cnt;

        if(map[i] == 'S') t_cnt++;
        
        permutation(i+1, depth+1, t_cnt);

        chosed[i] = false;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    for (int i = 0; i < N; i++)
    {
        cin >> map[i];
    }
    
    permutation(0, 0, 0);

    cout << ans << "\n";

    return 0;
}