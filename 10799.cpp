#include <iostream>
#include <vector>
using namespace std;

char str[100001];
vector<char> st;

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	int ans = 0;
	for (int i = 0; str[i]; i++) {
		if (str[i] == '(') st.push_back(str[i]);
		else {
			st.pop_back();
			if (str[i - 1] == '(')
				ans += st.size();
			else ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}