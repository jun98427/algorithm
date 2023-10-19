#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <tuple>
#include <cstdio>

#define MAX_N 100
#define MAX_M 10000

using namespace std;

int m, n;
int arr[MAX_N][MAX_M];

int main() 
{
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    set<int> sets;
    unordered_map<int, int> mapper;

    for (int i = 0; i < n; i++)
    {   
        sets.clear();
        mapper.clear();

        for (int j = 0; j < m; j++)
        {
            sets.insert(arr[i][j]);
        }

        int idx = 0;
        for (int it : sets)
        {
            mapper[it] = ++idx;
        }

        for (int j = 0; j < m; j++)
        {
            arr[i][j] = mapper[arr[i][j]];
        }
    }

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            bool check = true;
            
            for (int k = 0; k < m; k++)
            {
                if(arr[i][k] != arr[j][k]){
                    check = false;
                    break;
                }
            }
            
            if(check) ans++;
        }
    }
    

    cout << ans << endl;

    return 0;
}