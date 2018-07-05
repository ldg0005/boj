#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
using namespace std;

vector<char> st;
vector<int> ans;

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);

	string input;
	cin >> input;
	int n = input.size();
	int answer = 0, cntCost = 1;
	for (int i = 0; i < n; i++){
		if (input[i] == '(') {
			st.push_back(input[i]);
			cntCost *= 2;
			if (i + 1 < n && input[i + 1] == ')') answer += cntCost;
		}
		else if (input[i] == '[') {
			st.push_back(input[i]);
			cntCost *= 3;
			if (i + 1 < n && input[i + 1] == ']') answer += cntCost;
		}
		else if (input[i] == ')' && !st.empty() && st.back() == '(') {
			cntCost /= 2;
			st.pop_back();
		}
		else if (input[i] == ']' && !st.empty() && st.back() == '[') {
			cntCost /= 3;
			st.pop_back();
		}
		else {
			cout << "0" << '\n';
			return 0;
		}
		if (st.size() == 0) cntCost = 1;
	}
	if (st.size() == 0) cout << answer << '\n';
	else cout << "0" << '\n';

	return 0;
}