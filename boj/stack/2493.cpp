#include <iostream>
#include <stack>
#include <tuple>

#define MAX_N 500000

using namespace std;

int n;
int arr[MAX_N];
int result[MAX_N];

stack<pair<int, int> > s;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        while (!s.empty())
        {
            if(s.top().first >= arr[i])break;

            s.pop();
        }
        
        if(s.empty()) result[i] = 0;
        else {
            result[i] = s.top().second;
        }

        s.push({arr[i], i+1});
    }

    for (int i = 0; i < n; i++)
    {
        cout << result[i] <<" ";
    }
    cout << endl;

    return 0;
}