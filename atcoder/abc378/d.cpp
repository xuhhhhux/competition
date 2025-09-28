#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	
	vector ok(n, vector<int>(m));
	vector<int> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1};
	function<int(int, int, int)> dfs = [&](int x, int y, int c) -> int {
		if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '#' || ok[x][y]) {
			return 0;
		}
		if (c == k) {
			return 1;
		}
		
		ok[x][y] = 1;
		int res = 0;
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			res += dfs(tx, ty, c + 1);
		}
		ok[x][y] = 0;
		return res;
	};
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans += dfs(i, j, 0);
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