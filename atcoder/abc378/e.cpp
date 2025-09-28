#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2E5 + 10;

ll tr[N];

void add(int x, int c) {
	for (int i = x; i < N; i += i & -i) {
		tr[i] += c;
	}
}

ll sum(int x) {
	ll res = 0;
	for (int i = x; i; i -= i & -i) {
		res += tr[i];
	}
	return res;
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] %= m;
		a[i] = (a[i] + a[i - 1]) % m;
	}
	
	add(1, 1);
	ll ans = 0, tot = 0;
	for (int i = 1; i <= n; i++) {
		ans += i * a[i] - tot;
		ans += m * (sum(N - 1) - sum(a[i] + 1));
		
		tot += a[i];
		add(a[i] + 1, 1);
	}
	cout << ans << "\n";
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