#include <iostream>
using namespace std;

long long dp[91][2];

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	if (N == 1 || N == 2) cout << "1" << '\n';
	else {
		dp[2][0] = 1, dp[2][1] = 0;
		for (int i = 3; i <= N; i++) {
			dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
			dp[i][1] = dp[i - 1][0];
		}
		cout << dp[N][0] + dp[N][1] << '\n';
	}
	
	return 0;
}