#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i].second;
	}
	sort(a.begin(), a.end());
	
	ll sum = 0;
	priority_queue<int> q;
	for (int i = 0; i < k - 1; i++) {
		q.push(a[i].second);
		sum += a[i].second;
	}
	
	ll ans = 1E18;
	for (int i = k - 1; i < n; i++) {
		ans = min(ans, a[i].first * (sum + a[i].second));
		if (!q.empty() && q.top() > a[i].second) {
			sum -= q.top();
			sum += a[i].second;
			q.pop();
			q.push(a[i].second);
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