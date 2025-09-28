#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	
	auto power = [&](ll a, ll b, ll p) -> ll {
		ll res = 1;
		for (; b; b /= 2) {
			if (b % 2) {
				res = res * a % p;
			}
			a = a * a % p;
		}
		return res;
	};
	vector<int> vis(n);
	for (int i = 0; i < n; i++) {
		if (vis[i]) {
			continue;
		}
		
		vector<int> a;
		int x = i;
		while (!vis[x]) {
			vis[x] = 1;
			a.push_back(x);
			x = p[x];
		}
		int len = a.size();
		for (int j = 0; j < len; j++) {
			p[a[j]] = a[(j + power(2, k, len)) % len];
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << p[i] + 1 << " \n"[i == n - 1];
	}
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