#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int N, M;
vector<pair<ll, ll> > edge;
vector<ll> tree;

void update(int i, int diff){
	while(i < N + 1)
	{
		tree[i] += diff;
		i += (i & -i);
	}
}
ll sum(int i){
	ll ret = 0;
	while(i>0){
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}
char buf[1 << 17];

char read()
{
	static int idx = 1 << 17;
	if(idx == 1 << 17)
	{
		fread(buf, 1, 1 << 17, stdin);
		idx = 0;
	}
	return buf[idx++];
}
int readInt()
{
	int ret = 0, flg = 1;
	char now = read();


	while(now == 10 || now == 32) now = read();
	if(now == '-') flg = -1, now = read();
	while(now >= 48 && now <= 57)
	{
		ret = ret * 10 + now - 48;
		now = read();
	}
	return ret * flg;
}
int main()
{
	freopen("input.txt", "r", stdin);
	
	ll ans = 0;
	cin >> N >> M;
	edge.resize(M);
	tree.resize(N + 1);
	for(int i = 0; i < M; i++)
	{
		edge[i].first = readInt();
		edge[i].second = readInt();
	}
	sort(edge.begin(), edge.end());
	
	for(int i=0;i<M;i++){
		ll ri = edge[i].second;
		update(ri, 1);
		ans += sum(N) - sum(ri);
		//cout << sum(N) << "       " << sum(ri) << endl;
	}
	cout << ans << '\n';
	
	return 0;
}
