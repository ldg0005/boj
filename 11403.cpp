#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int> > map;
bool ans[100][100];
vector<bool> visit;

void dfs(int s, int n) {
	visit[n] = true;
	for (int i = 0; i < map[n].size(); i++) {
		if (!visit[map[n][i]]) {
			ans[s][map[n][i]] = true;
			dfs(s, map[n][i]);
		}
		else if (map[n][i] == s)
			ans[s][map[n][i]] = true;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	map.resize(N);
	int tmp;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp) map[i].push_back(j);
		}
	for (int i = 0; i < N; i++) {
		visit.clear();
		visit.resize(N);
		dfs(i, i);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << ans[i][j] << " ";
		cout << '\n';
	}

	return 0;
}