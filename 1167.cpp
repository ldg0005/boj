#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, node, ans;
vector<vector<pair<int, int> > > map;

void bfs(int start) {
	bool visited[100001] = { 0, };
	queue<pair<int, int> > q;
	q.push(make_pair(start, 0));
	visited[start] = true;
	while (!q.empty()) {
		int v = q.front().first;
		int c = q.front().second;
		if (c > ans) {
			ans = c;
			node = v;
		}
		q.pop();
		for (int j = 0; j < map[v].size(); j++) {
			if (!visited[map[v][j].first]) {
				visited[map[v][j].first] = true;
				q.push(make_pair(map[v][j].first, c + map[v][j].second));
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	map.resize(N + 1);
	int tmp, num, cost;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		while (1) {
			cin >> num;
			if (num == -1) break;
			cin >> cost;
			map[tmp].push_back(make_pair(num, cost));
		}
	}
	bfs(1);
	bfs(node);
	cout << ans << '\n';

	return 0;
}