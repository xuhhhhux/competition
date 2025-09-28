#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int ans = 1, cnt = 1, res = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			ans++, cnt++;
		} else if (a[i] == -1) {
			if (cnt >= 2) {
				cnt--;
			} else if (res >= 1) {
				ans++, cnt += 2, res--;
				cnt--;
			} else {
				cout << "-1\n";
				return;
			}
		} else {
			if (cnt >= 2) {
				cnt--, res++;
			} else {
				ans++, cnt++;
			}
		}
	}
	
	int g = gcd(ans, cnt);
	cout << ans / g << " " << cnt / g << "\n";
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