#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int n;
vector<int> v[2];

int main() {
    cin >> n;

    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        if(val >= 0) v[0].push_back(val);
        else v[1].push_back(val);
    }

    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end(), greater<int>());

    if(v[0].size() == 0) 
    {
        cout << v[1][1] << " " << v[1][0];
        return 0;
    }else if(v[1].size() == 0) {
        cout << v[0][0] << " " << v[0][1];
        return 0;
    }

    int v1, v2, gap = 1e9+2;
    if(v[0].size() >= 2 && v[0][0] + v[0][1] < gap) {
        v1 = v[0][0];
        v2 = v[0][1];
        gap = v1 + v2;
    }

    if(v[1].size() >= 2 && -(v[1][0] + v[1][1]) < gap)
    {
        v1 = v[1][1];
        v2 = v[1][0];
        gap = -(v1 + v2);
    }
    

    for (int i = 0; i < v[1].size(); i++)
    {
        int bound = -v[1][i];

        int s = 0, e = v[0].size()-1, mid;
        int idx = e;

        while (s <= e)
        {
            mid = (s + e) / 2;
            if(v[0][mid] >= bound) {
                idx = mid;
                e = mid - 1;
            }else {
                s = mid + 1;
            }
        }

        // cout << " i : " << i << " idx : " << idx << endl;

        int temp = abs(v[0][idx] - bound);
        if(idx > 0 && abs(v[0][idx-1] - bound) < temp) {
            idx--;
            temp = abs(v[0][idx] - bound);
        }
        // cout << " i : " << i << " idx : " << idx << endl;

        if(temp < gap) {
            v1 = -bound;
            v2 = v[0][idx];
            gap = temp;
        }
        
    }
    
    cout << v1 << " " << v2 << endl;

    return 0;
}