#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string a[1005],b[1005];

string big_add(string aa, string bb){
	if(aa.size() < bb.size()) swap(aa, bb);
	string ret = "";
	bool flag = false;
	int i;
	for(i=0; i<aa.size();i++){
		int anum=0, bnum=0, sum=0;
		anum = aa[i] - '0';
		if(i<bb.size()) bnum = bb[i] - '0';
		if(i > bb.size() && !flag)
		{
			ret += &aa[i];
			break;
		}
		sum = anum + bnum;
		if(flag) sum++;
		if(sum < 10){
			ret += sum + '0';
			flag = false;
		}
		else{
			ret += (sum % 10) + '0';
			flag = true;
		}
	}
	if(flag) ret += "1";
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	a[1] = "0";
	a[2] = "1", b[2] = "0";
	for(int i = 3; i <= 1000; i++)
	{
		a[i] = big_add(a[i - 1], b[i - 1]);
		b[i] = a[i];
		if(i % 2 == 0) a[i] = big_add(a[i], "1");
	}
	for(int i = 3; i <= 1000; i++)
		reverse(a[i].begin(), a[i].end());
	while(1){
		cin >> n;
		if(cin.eof()) break;
		cout << a[n] << '\n';
	}
	
	return 0;
}
