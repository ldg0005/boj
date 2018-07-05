#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, L, k;
vector<int> a, p;
vector<pair<int, pair<int,bool> > > st;

void init() {
	a.clear(), p.clear(), st.clear();
	a.resize(N), p.resize(N);
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> N >> L >> k;
		init();
		for (int i = 0; i < N; i++) {
			cin >> p[i] >> a[i];
			if (a[i] > 0) 
				st.push_back({ L - p[i], {a[i],false} });
			else 
				st.push_back({ p[i],{a[i],true} });
		}
		int idx = 0;
		for (int i = 0; i < N;i++) {
			if (st[i].second.second) st[i].second.first = a[idx++];
		}
		for (int i = 0; i < N;i++) {
			if (!st[i].second.second) st[i].second.first = a[idx++];
		}
		sort(st.begin(), st.end());
		
		cout << st[k - 1].second.first << '\n';
	}

	return 0;
}