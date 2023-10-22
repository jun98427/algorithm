#include <iostream>
#include <deque>
#include <tuple>

#define MAX_N 5000000

using namespace std;

int n, l;
int arr[MAX_N];
deque<pair<int, int> >dq;

// 이분 탐색으로 돌려서 삭제하는 것보다 그냥 삭제하는 게 더 빠르다
// 이유는?

void insert(int val, int idx) {
    while (!dq.empty() && idx - dq.front().second  >= l)
    {
        dq.pop_front();
    }

    if(dq.empty()) {
        dq.push_front(make_pair(val, idx));
    }

    int s = 0, e = dq.size()-1, mid;
    int t = e + 1;

    while (s <= e)
    {
        mid = (s+e) / 2;

        auto it = dq.begin() + mid;

        if(it->first < val) {
            s = mid + 1;
        }else {
            t = mid;
            e = mid - 1;
        }
    }

    if(t == dq.size()+1) dq.push_back(make_pair(val, idx));
    else {
        dq.erase(dq.begin()+t, dq.end());
        dq.push_back(make_pair(val, idx));
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> l;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        insert(arr[i], i);
        
        // for(auto it : dq) {
        //     cout << "{" << it.first << " " << it.second << "} ";
        // }
        // cout << "\n";
        cout << dq.front().first <<" ";
    }
    cout <<"\n";

    return 0;
}