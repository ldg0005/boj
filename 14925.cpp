#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int M, N;
int dp[1001][1001];

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	int tmp, ans=0;
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++) {
			cin >> tmp;
			if (!tmp) {
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	cout << ans << '\n';

	return 0;
}