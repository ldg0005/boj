#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, ans=-10000, tmp=0, dp=-10000;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		dp = max(dp + tmp, tmp);
		ans = max(ans, dp);
	}
	cout << ans << '\n';

	return 0;
}