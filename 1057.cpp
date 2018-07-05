#include <iostream>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, A, B;
	cin >> N >> A >> B;
	int ans = 0;
	while (A != B) {
		if (A % 2 != 0) A++;
		if (B % 2 != 0) B++;
		A >>= 1;
		B >>= 1;
		ans++;
	}
	cout << ans << '\n';

	return 0;
}