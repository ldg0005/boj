#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int dp[1001][4];
int N, answer;

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int R, G, B;
	for (int i = 1; i <= N; i++) {
		cin >> R >> G >> B;
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + R;
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + G;
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + B;
		answer = min(min(dp[i][0], dp[i][1]), dp[i][2]);
	}
	cout << answer << '\n';

	return 0;
}