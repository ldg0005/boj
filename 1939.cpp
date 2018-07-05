#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, ans[10001];
vector<vector<pair<int, int> > > map;

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	map.resize(N+1);
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		map[a].push_back(make_pair(b, c));
		map[b].push_back(make_pair(a, c));
	}
	int start, end;
	cin >> start >> end;
	for (int i = 0; i < map[start].size(); i++) {
		queue<pair<int, int> > q;
		q.push(map[start][i]);
		while (!q.empty()) {
			int po = q.front().first;
			int co = q.front().second;
			q.pop();
			for (int j = 0; j < map[po].size(); j++) {
				if (ans[map[po][j].first] < min(co, map[po][j].second)) {
					ans[map[po][j].first] = min(co, map[po][j].second);
					q.push(make_pair(map[po][j].first, min(co, map[po][j].second)));
				}
			}
		}
	}
	cout << ans[end] << '\n';

	return 0;
}