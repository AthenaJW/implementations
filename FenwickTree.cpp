#include <bits/stdc++.h>

using namespace std;

string PROBLEM_NAME = "time";

const int MAXN = 100000;
int ft[MAXN];
int N;

int LSOne(int pos)
{
	return (pos&(-pos));
}

int rsq(int pos)
{
	int sum = 0;
	for (; pos > 0; pos -= LSOne(pos))
		sum += ft[pos];
}
void update(int pos, int v)
{
	for (; pos < N; pos += LSOne(pos))
		ft[pos] += v;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((PROBLEM_NAME+".in").c_str(), "r", stdin);
	freopen((PROBLEM_NAME+".out").c_str(), "w", stdout);
	
	cin >> N;
	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		update(i, n);
	}
}

