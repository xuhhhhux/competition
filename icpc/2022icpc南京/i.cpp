#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
	string s;
	cin >> s;
	
	map<char, int> mp;
	int ans = 0;
	for (auto c : s) {
		ans = max(ans, ++mp[c]);
	}
	cout << int(s.size()) - ans << "\n";
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