#include <iostream>
using namespace std;

int map[2][100001], dp[2][100001];

inline int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, N;
	cin >> t;
	while (t--) {
		cin >> N;
		for (int j = 1; j <= N; j++)
			cin >> map[0][j];
		cin >> map[1][1];
		dp[0][1] = map[0][1], dp[1][1] = map[1][1];
		int ans=max(dp[0][1],dp[1][1]);
		for (int i = 2; i <= N; i++) {
			cin >> map[1][i];
			int tmp = max(dp[0][i - 2], dp[1][i - 2]);
			dp[0][i] = max(dp[1][i - 1] + map[0][i], tmp + map[0][i]);
			dp[1][i] = max(dp[0][i - 1] + map[1][i], tmp + map[1][i]);
			ans = max(dp[0][i], dp[1][i]);
		}
		cout << ans << '\n';
	}


	return 0;
}