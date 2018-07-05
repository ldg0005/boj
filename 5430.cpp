#include <iostream> 
#include <deque> 
#include <string>
using namespace std; 

bool chk, ok;
int n;

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T; 
	cin >> T; 
	while (T--) { 
		string cmd = ""; 
		string input = ""; 
		deque<int> dq; 
		ok = chk = true; 
		cin >> cmd; 
		cin >> n; 
		cin >> input;
		string num = "";
		for (int i = 0; i < input.size(); ++i) {
			if (input[i] == ',' || input[i] == ']') {
				if (input[i - 1] == '[') 
					break; 
				dq.push_back(atoi(num.c_str())); 
				num = ""; 
			} 
			else if (input[i] != '[' && input[i] != ']') 
				num += input[i];	
		} 
		for (int i = 0; i < cmd.size(); ++i) { 
			if (cmd[i] == 'R') 
				chk ^= 1; 
			else { 
				if (dq.size() <= 0) { 
					ok = false;
					break;
				} 
				if (chk) dq.pop_front();	
				else dq.pop_back();
			}
		}
		if (ok) { 
			int size = dq.size(); 
			cout << "["; 
			for (int i = 0; i < size; ++i) {
				if (chk) {
					cout << dq.front();
					dq.pop_front();
				}
				else { 
					cout << dq.back();
					dq.pop_back(); 
				}
				if (!dq.empty()) cout << ","; 
			}
			cout << "]" << endl; 
		}
		else{
			cout << "error" << endl;
		}
	}
	return 0;
}
