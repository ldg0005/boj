#include <iostream>
using namespace std;

int N, A[1000001], B, C;
long long ans;

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> B >> C;
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		ans++;
		if(A[i] > 0) {
			if (A[i] % C == 0) ans += A[i] / C;
			else ans += A[i] / C + 1;
		}
	}
	cout << ans << '\n';

	return 0;
}