#include <iostream>
#include <vector>

using namespace std;

vector<int> acid, base;
int n;

int main() {
    cin >> n;

    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;

        if(val >= 0) base.push_back(val);
        else acid.push_back(val);
    }

    int gap = 1e9;
    
    if(acid.size() >= 2 && abs(gap) > -(acid[acid.size()-1] + acid[acid.size()-2])) {
        gap = acid[acid.size()-1] + acid[acid.size()-2];
    }

    if(base.size() >= 2 && abs(gap) > base[0] + base[1]){
        gap = base[0] + base[1];
    }

    if(base.size() && acid.size()){
        for (int val : acid)
        {
            val = -val;
            int s = 0, e = base.size()-1, mid;
            int t = base.size();

            while (s <= e)
            {
                mid = (s + e) / 2;

                if(base[mid] >= val) 
                {
                    t = min(t, mid);
                    e = mid-1;
                }else {
                    s = mid+1;
                }
            }

            if(t != base.size() && abs(gap) > base[t]-val) {
                gap = base[t] - val;
            }

            if(t > 0 && abs(gap) > val - base[t-1]){
                gap = base[t-1] - val;
            }
        }
    }

    cout << gap << endl;


    return 0;
}