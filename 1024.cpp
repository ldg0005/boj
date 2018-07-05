#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, L;
	cin >> N >> L;
	int n = N > 100 ? 100 : N + 1;
	for (int i = L; i <= n; i++) {
		int seed = N / i;
		if (i % 2 == 0) {
			int ii = i - 1;
			int sum = 0;
			if (seed - (ii / 2) < 0 || seed + (ii/2) > 1000000000) continue;
			for (int j = seed - (ii / 2); j <= seed + (ii / 2); j++) 
				sum += j;
			if (seed + (ii / 2) + 1 <= 1000000000 && sum + (seed + (ii / 2) + 1) == N) {
				for (int j = seed - (ii / 2); j <= seed + (ii / 2) + 1; j++) 
					cout << j << " ";
				return 0;
			}
			if(seed - (ii/2) -1 >= 0 && sum + (seed - (ii / 2) - 1) == N){
				for (int j = seed - (ii / 2) - 1; j <= seed + (ii / 2); j++)
					cout << j << " ";
				return 0;
			}
		}
		else {
			int sum = 0;
			if (seed - (i / 2) < 0 || seed + (i/2) > 1000000000) continue;
			for (int j = seed - (i/2); j <= seed+(i/2); j++) 
				sum += j;
			if (sum == N) {
				for (int j = seed - (i / 2); j <= seed + (i / 2); j++)
					cout << j << " ";
				return 0;
			}
		}
	}
	cout << "-1";

	return 0;
}