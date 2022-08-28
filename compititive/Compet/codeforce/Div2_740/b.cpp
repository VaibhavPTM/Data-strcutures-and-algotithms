#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		set<int> ans;
		int pre = (a + b + 1) / 2;
		for (int i = 0; i <= min(a, b); ++i) ans.insert(abs(a - pre) + 2 * i);
		for (int i = 0; i <= min(a, b); ++i) ans.insert(abs(b - pre) + 2 * i);
		printf("%d\n", ans.size());
		for (auto i : ans) printf("%d ", i);
		putchar('\n');
	}
	return 0;
}