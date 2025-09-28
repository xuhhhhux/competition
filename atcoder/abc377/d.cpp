#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2E5, M = 18;

int mp[N];
int f[N][M];

int query(int l, int r) {
	int k = log(r - l + 1) / log(2);
	return max(f[l][k], f[r - (1 << k) + 1][k]);
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<int> l(n), r(n);
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		mp[r[i]] = max(mp[r[i]], l[i]);
	}
	
	for (int j = 0; j < M; j++) {
		for (int i = 1; i + (1 << j) - 1 <= m; i++) {
			if (!j) {
				f[i][j] = mp[i];
			} else {
				f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	
	ll ans = 0;
	for (int i = 1; i <= m; i++) {
		int l = i, r = m;
		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (query(i, mid) >= i) {
				r = mid - 1;
			} else {
				l = mid;
			}
		}
		if (query(i, l) < i) {
			ans += l - i + 1;
		}
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