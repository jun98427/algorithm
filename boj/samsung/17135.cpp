#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>

#define DIR_NUM 3

using namespace std;

int n, m, d;
int ans;

int map[15][15];
bool is_visited[15][15];
int dx[3] = {-1, 0, 1};
int dy[3] = {0, -1, 0};

vector<int> at;

void simulate(){
    memset(is_visited, false, sizeof(is_visited));
    
    int cnt = 0;

    for (int i = n; i > 0; i--)
    {
        // i+1 위치에 궁수가 존재한다고 가정
        int dis[3] = {d+1, d+1, d+1};
        pair<int, int> points[3];

        for (int j = i-1; j >= max(0, i-d); j--)
        {
            for (int k = 0; k < m; k++)
            {
                if(map[j][k] == 0 || is_visited[j][k]) continue;

                for (int l = 0; l < 3; l++)
                {
                    int dist = abs(at[l] - k) + i-j;
                    if(dis[l] > dist) {
                        dis[l] = dist;
                        points[l] = make_pair(j, k);
                    }else if(dis[l] == dist) {
                        if(k < points[l].second) points[l] = make_pair(j, k);
                    }
                }
            }
        }

        for (int j = 0; j < 3; j++)
        {
            if(dis[j] == d+1) continue;

            if(!is_visited[points[j].first][points[j].second]) {
                is_visited[points[j].first][points[j].second] = true;
                cnt++;
            }
        }
    }

    ans = max(cnt, ans);
    return ;
}

void choose(int idx) {
    if(at.size() == 3) {
        simulate();
        return ;
    }

    if(idx == m ) return ;

    at.push_back(idx);
    choose(idx+1);
    at.pop_back();
    choose(idx+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> d;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    choose(0);
    
    cout << ans << endl;

    return 0;
}