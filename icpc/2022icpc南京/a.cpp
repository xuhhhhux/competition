#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1E3 + 10;

int a[N][N];

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	string s;
	cin >> s;
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			a[i][j] = 0;
		}
	}
	
	int u = 1, d = n, l = 1, r = m;
	int U = 1, D = n, L = 1, R = m;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'U') {
			U++, D++;
		}
		if (s[i] == 'D') {
			U--, D--;
		}
		if (s[i] == 'L') {
			L++, R++;
		}
		if (s[i] == 'R') {
			L--, R--;
		}
		u = max(u, U);
		d = min(d, D);
		l = max(l, L);
		r = min(r, R);
		if (u > n || d < 0 || l > m || r < 0 || u > d || l > r) {
			if (k == 0) {
				cout << n * m << "\n";
			} else {
				cout << "0\n";
			}
			return;
		}
	}
	
	map<pair<int, int>, int> cnt;
	cnt[{u, l}] = 1;
	a[u][l]++;
	a[u][r + 1]--;
	a[d + 1][l]--;
	a[d + 1][r + 1]++;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'U') {
			u--, d--;
		} else if (s[i] == 'D') {
			u++, d++;
		} else if (s[i] == 'L') {
			l--, r--;
		} else {
			l++, r++;
		}
		
		if (!cnt[{u, l}]) {
			cnt[{u, l}] = 1;
			a[u][l]++;
			a[u][r + 1]--;
			a[d + 1][l]--;
			a[d + 1][r + 1]++;	
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
			if (a[i][j] == (d - u + 1) * (r - l + 1) - k) {
				ans++;
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1;
	cin >> t;
	
	while (t--) {
		solve();
	}
	
	return 0;
}