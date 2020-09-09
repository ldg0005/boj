#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <deque>
using namespace std;

vector<vector<int> > map;
vector<long long> input;
long long K, N, answer;

int main() {
	//freopen("sample_input.txt", "r", stdin);
	answer = 0;
	cin >> K >> N;
	input.resize(K);
	for (int i = 0; i < K; i++)
		cin >> input[i];
	sort(input.begin(), input.end());

	long long left = 1, right = input[K - 1];
	while (left <= right) {
		long long cost = 0;
		long long temp = left + right;
		long long mid = temp / 2;
		for (int i = K - 1; i >= 0; i--) {
			cost += input[i] / mid;
		}
		
		if (cost >= N) {
			if (mid > answer) answer = mid;
			left = mid + 1;
		}
		else if (cost < N) right = mid - 1;
	}

	cout << answer << endl;

	return 0;
}
