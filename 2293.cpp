#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,k,ans;
int a[101];
int dp[100001];

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
				if (a[i] <= j)
					dp[j] += dp[j - a[i]];
		}
			for (int i = 1; i <= k; i++)
				cout << dp[i] << " ";
			cout << endl;


	}

	cout << dp[k] << '\n';

	return 0;
}