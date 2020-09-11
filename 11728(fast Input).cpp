#include<iostream>
using namespace std;

int a[1000005], b[1000005];
int N, M;

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
	//freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for(register int i = 0; i < N; i++)
		a[i] = readInt();
	for(register int i = 0; i < M; i++)
		b[i] = readInt();
	register int i = 0, j = 0, k = 0;
	for(; i < N + M; i++)
	{
		if(j >= N || k >= M) break;
		if(a[j] < b[k]) printf("%d ", a[j++]);
		else printf("%d ", b[k++]);
	}
	if(j < N)
	{
		for(; j < N; j++)
			printf("%d ", a[j]);
	}
	if(k < M)
	{
		for(; k < M; k++)
			printf("%d ", b[k]);
	}

	return 0;
}
