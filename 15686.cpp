#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, ans;
int map[50][50];
vector<pair<int, int> > pos1, pos2;
vector<vector<int> > cost;
vector<int> st, visit;

void dfs(int depth, int s) {
	if (depth == M) {
		int temp = 0;
		for (int i = 0; i < pos1.size(); i++) {
			int tmp = 987654321;
			for (int j = 0; j < st.size(); j++) {
				tmp = min(tmp, cost[i][st[j]]);
			}
			temp += tmp;
		}
		ans = min(ans, temp);
		return;
	}
	for (int i = s; i < pos2.size(); i++) {
		if (!visit[i]) {
			visit[i] = true;
			st.push_back(i);
			dfs(depth + 1, i);
			st.pop_back();
			visit[i] = false;
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) pos1.push_back({ i,j });
			else if (map[i][j] == 2) pos2.push_back({ i,j });
		}
	cost.resize(pos1.size(), vector<int>(pos2.size()));
	for (int i = 0; i < pos1.size(); i++) {
		for (int j = 0; j < pos2.size(); j++) {
			cost[i][j] = abs(pos1[i].first - pos2[j].first) + abs(pos1[i].second - pos2[j].second);
		}
	}
	visit.resize(pos2.size());
	ans = 987654321;
	dfs(0,0);
	
	cout << ans << '\n';

	return 0;
}