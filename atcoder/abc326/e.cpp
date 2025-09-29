#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

constexpr int P = 998244353;

ll power(ll a, ll b) {
	ll res = 1;
	for (; b; b /= 2) {
		if (b % 2) {
			res = res * a % P;
		}
		a = a * a % P;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	
	vector<int> a(n + 2);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	vector<ll> f(n + 2), s(n + 2);
	for (int i = n; i >= 0; i--) {
		f[i] = s[i + 1];
		s[i] = ((f[i] + a[i]) * power(n, P - 2) % P + s[i + 1]) % P;
	}
	cout << f[0] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1;
	// cin >> t;
	
	while (t--) {
		solve();
	}
	
	return 0;
}