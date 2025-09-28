#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<vector<int>> e(n + 1);
	vector<int> d(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
		d[u]++, d[v]++;
	}
	
	vector<int> vis(n + 1);
	ll ans = 0;
	function<int(int)> dfs = [&](int u) -> int {
		vis[u] = 1;
		int res = 0;
		for (auto v : e[u]) {
			if (vis[v] || d[v] < 2 || d[v] > 3) {
				continue;
			}
			if (d[v] == 3) {
				res += dfs(v);
			} else {
				res++;
			}
		}
		return res;
	};
	for (int i = 1; i <= n; i++) {
		if (vis[i] || d[i] != 3) {
			continue;
		}
		int x = dfs(i);
		if (x >= 2) {
			ans += 1ll * x * (x - 1) / 2;
		}
	}
	cout << ans << "\n";
	
	return 0;
}
