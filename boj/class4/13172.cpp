#include <iostream>

using namespace std;

using ll = long long;
ll MOD = 1'000'000'007;

ll calc(ll x, ll y){
	if(y==1) return x;
	if(y%2==1) return x*calc(x,y-1)%MOD;
	ll p = calc(x,y/2);
	return p*p%MOD;
}

ll gcd(ll a, ll b) {
    ll tmp;
    while (b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

int main(){
	ll m,a,b;
	ll ans = 0;
	
	cin >> m;
	
	while(m--){
		cin >> b >> a;

        ll g;
        if(a > b) g = gcd(a, b);
        else g = gcd(b, a);
        
		b /= g;
		a /= g;
		ans += a*calc(b,MOD-2)%MOD;
		ans%=MOD;
	}
	
	cout << ans << "\n";
	
	return 0;
}