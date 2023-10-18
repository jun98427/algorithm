#include <iostream>
#include <algorithm>

#define MAX_N   5000

using namespace std;

int arr[MAX_N];
int n;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int r, l, m;
    long long gap = 1e10;

    for (int i = 1; i < n-1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            long long sum = arr[i] + arr[j];

            int idx = n, s = i+1, e = n-1;
            int mid;

            while (s <= e)
            {
                mid = (s + e) / 2;

                if(arr[mid] >= -sum) {
                    idx = mid;
                    e = mid-1;
                }else {
                    s = mid+1;
                }
            }

            if(idx != i+1) {
                long long tmp = sum + arr[idx-1];
                if(abs(tmp) < gap) {
                    gap = abs(tmp);
                    r = idx-1;
                    l = j;
                    m = i;
                }
            }

            if(idx != n) {
                long long tmp = sum + arr[idx];
                if(abs(tmp) < gap) {
                    gap = abs(tmp);
                    r = idx;
                    l = j;
                    m = i;
                }
            }         
        }
        
    }
    
    cout << arr[l] << " " << arr[m] << " " << arr[r] << endl;

    return 0;
}