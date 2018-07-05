#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, ans;
vector<vector<int> > v;
vector<int> downcnt, upcnt;
vector<int> visit;

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	int a, b;
	v.resize(N+1);
	downcnt.resize(N + 1);
	upcnt.resize(N + 1);
	visit.resize(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) {
		queue<int> q;
		q.push(i);
		visit[i] = i;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int j = 0; j < v[cur].size(); j++) {
				int next = v[cur][j];
				if (visit[next] != i) {
					visit[next] = i;
					upcnt[next]++;
					downcnt[i]++;
					q.push(next);
				}
			}
		}
	}
	for(int i=1;i<=N;i++)
		if (downcnt[i] > (N / 2) || upcnt[i] > (N / 2)) ans++;

	cout << ans << '\n';

	return 0;
}