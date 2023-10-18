#include <iostream>
#include <map>
#include <algorithm>
#include <tuple>

#define MAX_N 10000
#define MAX_M 100

using namespace std;

int m, n;
pair<int, int> arr[MAX_N][MAX_M];

map<int, int> mapper;
// 중복된 값 제거 필요
// 숫자 크기로 정렬 후 index 값

bool comp(pair<int, int>& a, pair<int, int>& b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main() 
{
    cin >> n >> m;
    
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j].first;
            arr[i][j].second = j+1;
        }

        sort(arr[i], arr[i]+m, comp);
    }

    for (int i = 0; i < m-1; i++)
    {
        for (int j = i+1; j < m; j++)
        {
               
        }   
    }
    
    
    

    cout << ans << endl;

    return 0;
}