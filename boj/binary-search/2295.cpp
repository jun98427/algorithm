#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <unordered_set>

#define MAX_N 1000

using namespace std;

int n;

vector<int> vec;
unordered_set<int> set;

int main() {
    // freopen("2295.txt", "r", stdin);
    cin >> n;

    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        vec.push_back(val);
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i; j < vec.size(); j++)
        {
            val = vec[i] + vec[j];

            if(val >= vec.back()) break;

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
    for (int i = vec.size()-1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if(set.find(vec[i] - vec[j]) != set.end()) 
            {
                ans = vec[i];
                break;
            }
        }

        if(ans != -1) break;
    }
    
    cout << ans << endl;

    return 0;
}
