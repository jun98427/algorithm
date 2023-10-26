#include <iostream>
#include <tuple>

#define MAX_N 8

using namespace std;

pair<int, int> arr[MAX_N];
bool breakup[MAX_N];
int n;
int ans;

void dfs(int hand, int cnt) {
    if(hand == n) {
        ans = max(ans, cnt);
        return;
    }

    if(breakup[hand]) {
        return dfs(hand+1, cnt);
    }

    int hand_dur, hand_weight;
    tie(hand_dur, hand_weight) = arr[hand];
    bool check = false;
    for (int i = 0; i < n; i++)
    {
        if(hand == i) continue;

        if(!breakup[i]) {
            check = true;
            int tmp_dur, tmp_weight, t_cnt = cnt;
            tie(tmp_dur, tmp_weight) = arr[i];

            arr[hand].first = hand_dur - tmp_weight;
            arr[i].first = tmp_dur - hand_weight;

            if(arr[hand].first <= 0) {
                breakup[hand] = true;
                t_cnt++;
            }

            if(arr[i].first <= 0) {
                breakup[i] = true;
                t_cnt++;
            }

            dfs(hand+1, t_cnt);

            arr[hand].first = hand_dur;
            arr[i].first = tmp_dur;
            breakup[hand] = false;
            breakup[i] = false;
        }
    }

    if(!check) {
        ans = max(ans, cnt);
        return ;
    }
    
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    
    dfs(0, 0);

    cout << ans << "\n";

    return 0;
}