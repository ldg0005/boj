#include <iostream>
#include <queue>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int tmp;
	priority_queue<int> pq;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		pq.push(-tmp);
	}
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			pq.push(-tmp);
			pq.pop();
		}
	}
	cout << -pq.top() << '\n';

	return 0;
}