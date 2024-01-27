#include <iostream>
#include <queue>
#include <tuple>

#define INF 100005;

using namespace std;

int times[100005], counts[100005];

// +1 -1 *2 모두 1초씩 소요
// priority que 사용 이유가 있나? -> 딱히 없음

int main() {
    // freopen("input.txt", "r", stdin);
    int x, y;
    cin >> x >> y;

    int ans = INF;
    int cnt = 0;

    queue<pair<int, int> > que;
    que.push({0, x});
    times[x] = 0;
    counts[x] = 1;

    int c, t;
    while (!que.empty())
    {
        tie(t, c) = que.front();
        que.pop();

        // cout << "t : " << t << " c : " << c << "\n";

        if(times[c] != t) continue;

        if(c == y) 
        {
            ans = t; 
            break;
        }

        if(c > 0) {
            if(times[c-1] == 0) {
                times[c-1] = t+1;
                counts[c-1] = counts[c];
                que.push({t+1, c-1});
            }else if(times[c-1] == t+1) {
                counts[c-1] += counts[c];
            }
        }

        if(c+1 < 100001) {
            if(times[c+1] == 0) {
                times[c+1] = t+1;
                counts[c+1] = counts[c];
                que.push({t+1, c+1});
            }else if(times[c+1] == t+1) {
                counts[c+1] += counts[c];
            }
        }

        if((c << 1) < 100001) {
            if(times[(c<<1)] == 0) {
                times[(c<<1)] = t+1;
                counts[(c<<1)] = counts[c];
                que.push({t+1, (c<<1)});
            }else if(times[(c<<1)] == t+1) {
                counts[(c<<1)] += counts[c];
            }
        }
    }

    cout << ans << "\n" << counts[y] << "\n";

    return 0;
}