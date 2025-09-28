#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> e(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
	}
	
	vector<int> vis(n + 1), dis(n + 1);
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		
		for (int v : e[u]) {
			if (v == 1) {
				cout << dis[u] + 1 << "\n";
				return;
			}
			if (vis[v]) {
				continue;
			}
			vis[v] = 1;
			dis[v] = dis[u] + 1;
			q.push(v);
		}
	}
	cout << "-1\n";
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