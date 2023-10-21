#include <iostream>
#include <vector>

#define MAX_N   4000000

using namespace std;

int n;
vector<int> primes;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    cin >> n;

    vector<bool> prime(n + 1, true);

    for (int i = 2; i * i <= n; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (prime[i]) primes.push_back(i);
    }

    int sum = 0;
    int j = 0;
    int ans = 0;

    for (int i = 0; i < primes.size(); i++)
    {
        while (j < primes.size())
        {
            if(sum >= n) break;

            sum += primes[j];
            j++;
        }
        
        if(sum == n) ans++;

        sum -= primes[i];
    }

    cout << ans << endl;

    return 0;
}