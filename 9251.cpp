#include <stdio.h>

char s[1002], t[1002];
int nS, nT;
int dp[1001][1001];

inline int _strlen(char *a) {
	int i;
	for (i = 0; a[i] != 0; i++);
	return i;
}
inline int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	freopen("9251input.txt", "r", stdin);
	scanf("%s", &s[1]);
	scanf("%s", &t[1]);
	nS = _strlen(s + 1);
	nT = _strlen(t + 1);
	int ans = 0;
	for (int i = 1; i <= nS; i++) {
		for (int j = 1; j <= nT; j++) {
			if (s[i] == t[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
			ans = max(dp[i][j], ans);
		}
	}
	printf("%d\n", ans);
	return 0;
}