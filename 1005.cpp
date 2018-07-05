#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K,ans;
vector<vector<int> > v;
vector<int> d, dp;

void init() {
	N = K = ans = 0;
	v.clear();
	dp.clear();
}
void dfs(int s, int cost) {
	ans < cost ? ans = cost : ans = ans;
	for (int i = 0; i < v[s].size(); i++) {
		if (dp[v[s][i]] < cost + d[v[s][i]]) {
			dp[v[s][i]] = cost + d[v[s][i]];
			dfs(v[s][i], cost + d[v[s][i]]);
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		init();
		cin >> N >> K;
		v.resize(N + 1);
		d.resize(N + 1);
		dp.resize(N + 1);
		for (int i = 1; i <= N; i++)
			cin >> d[i];
		int x, y, dest;
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			v[y].push_back(x);
		}
		cin >> dest;
		dfs(dest, d[dest]);
		cout << ans << '\n';
	}

	return 0;
}