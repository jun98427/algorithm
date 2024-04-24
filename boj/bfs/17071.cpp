#include <iostream>
#include <queue>

#define MAX_N   500'000

using namespace std;

bool isv[MAX_N+1][2];

int Solve(int s, int e) {
    if(s == e) return 0;

    int mov = 1;

    queue<int> que;
    que.push(s);

    while (!que.empty())
    {
        e += mov;
        if(e > MAX_N) break;

        // cout << "s : " << s <<" e : " << e << " mov : " << mov <<"\n";

        int idx = mov % 2; 
        if(isv[e][idx]) return mov;

        int qsize = que.size();

        for(int i=0; i<qsize; i++)
        {
            int cur = que.front();
            que.pop();

            for(int next : {cur-1, cur+1, cur*2}) {
                // cout << "next : " << next<< "\n";
                if(next < 0 || next > MAX_N) continue;
                
                if(e == next) return mov;

                if(isv[next][idx]) continue;

                isv[next][idx] = true;
                que.push(next);
            }
        }
        
        mov++;
    }
    
    return -1;
}

int main(){
    // freopen("in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;

    int ans = Solve(n, k);

    cout << ans << "\n";

    return 0;
}