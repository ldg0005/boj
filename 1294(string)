#include <iostream>
#include <vector>
using namespace std;

string ans;
int N;
vector<string> arr;

int main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	ans = "";
	cin >> N;
	arr.resize(N);
	string _input;
	int maxn = 1;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if(arr[i].size() > maxn) maxn = arr[i].size();
	}
	maxn++;
	for(int i = 0; i < N; i++)
		arr[i].resize(maxn, 'c');
	while(1)
	{
		string mins;
		int minidx = 0;
		mins.resize(maxn, 99);
		for(int i = 0; i < N; i++)
			if(arr[i] < mins)
			{
				mins = arr[i];
				minidx = i;
			}
		if(arr[minidx][0] != 99)
		{
			ans += arr[minidx][0];
			arr[minidx] = &arr[minidx][1];
			arr[minidx].push_back(99);
		}
		else break;
	}
	cout << ans;

	return 0;
}
