#include <iostream>

#define MAX_INNING      50
#define NUM_OF_BATTER   9

using namespace std;

int ans, n;

int order[NUM_OF_BATTER];
int result[MAX_INNING][NUM_OF_BATTER];
bool is_used[NUM_OF_BATTER];

void solve() {
    int cur = 0, cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int base[3] = {0, 0, 0}, out_count = 0;

        while(out_count < 3) {
            int re = result[i][order[cur]];
            cur = (cur+1)%9;

            if(re == 0) {
                out_count++;
            }else if(re == 1){
                cnt += base[2];
                base[2] = base[1];
                base[1] = base[0];
                base[0] = 1;
            }else if(re == 2){
                cnt += base[2] + base[1];
                base[2] = base[0];
                base[1] = 1;
                base[0] = 0;
            }else if(re == 3){
                cnt += base[0] + base[1] + base[2];
                base[0] = base[1] = 0;
                base[2] = 1;
            }else {
                cnt += base[0] + base[1] + base[2] + 1;
                base[0] = 0; 
                base[1] = 0;
                base[2] = 0;
            }
        }
    }
    
    ans = max(ans, cnt);
}

void comb(int idx){
    if(idx == NUM_OF_BATTER) {
        solve();
        return;
    }

    if(idx == 3) {
        comb(idx+1);
    }else {
        for (int i = 1; i < NUM_OF_BATTER; i++)
        {
            if(!is_used[i]) {
                is_used[i] = true;
                order[idx] = i;
                comb(idx+1);

                is_used[i] = false;
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < NUM_OF_BATTER; j++)
        {
            cin >> result[i][j];
        }
    }

    is_used[0] = true;
    order[3] = 0; 

    comb(0);

    cout << ans << endl;
    
    return 0;
}