#include <iostream>
using namespace std;

int N;
int dp[1001], p[1001];

inline int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> p[i];
	for (int i = 1; i <= N; i++) 
		for (int j = 0; j <= i; j++) 
			dp[i] = max(dp[i], dp[j] + p[i - j]);
	cout << dp[N] << '\n';

	return 0;
}