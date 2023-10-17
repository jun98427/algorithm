#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <unordered_set>

#define MAX_N 1000

using namespace std;

int n;

vector<int> v;
unordered_set<int> set;

int main() {
    // freopen("2295.txt", "r", stdin);
    cin >> n;

    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        v.push_back(val);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i; j < v.size(); j++)
        {
            val = v[i] + v[j];

            if(val >= v.back()) break;

            set.insert(val);
        }
    }
    

    // for(int x : v) {
    //     for (int y : v)
    //     {
    //         val = x+y;
            
    //         if(val >= v.back()) break;

    //         set.insert(val);
    //     }
    // }

    int ans = -1;
    for (int i = v.size()-1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if(set.find(v[i] - v[j]) != set.end()) 
            {
                ans = v[i];
                break;
            }
        }

        if(ans != -1) break;
    }
    
    cout << ans << endl;

    return 0;
}
