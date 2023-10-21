#include <iostream>
#include <algorithm>

#define MAX_N 1000

using namespace std;

int n, k;

pair<int, int> lines[MAX_N];

int get_add(int l, int r){
    int ret = 0;

    for (int i = 0; i < n; i++)
    {
        if(lines[i].first >= r) break;
        
        if(lines[i].second <= l) continue;

        ret++;
    }
    return ret;
}

int main() {
    cin >> n >> k;

    int s, e, l = 1e8, r=-1;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;
        lines[i] = make_pair(s, e);
        l = min(l, s);
        r = max(r, e);
    }

    sort(lines, lines+n);

    int x = 0, y = 0;

    int j = 0;
    int sum = 0;
    for(int i = 0; i < r; i++)
    {
        while (j <= r && sum < k)
        {
            sum += get_add(j, j+1);
            j++;
        }

        if(sum == k) {
            x = i;
            y = j;
            break;
        }

        sum -= get_add(i, i+1);
    }

    cout << x << " " << y << endl;
    
    return 0;
}