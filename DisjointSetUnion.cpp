#include <bits/stdc++.h>

using namespace std;

string PROBLEM_NAME = "time";

const int MAXN = 200000;

int N, Q;
int parent[MAXN];
int height[MAXN];

int find(int node)
{
	if (parent[node] == node)
		parent[node] = find(parent[node]);
	return parent[node];
}

void join(int A, int B)
{
	int rootA = find(A);
	int rootB = find(B);
	if (height[rootA] > height[rootB])
	{
		parent[rootB] = rootA;
		height[rootA] = max(height[rootA], height[rootB]+1);
	}
	else
	{
		parent[rootA] = rootB;
		height[rootB] = max(height[rootB], height[rootA]+1);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	/*freopen((PROBLEM_NAME+".in").c_str(), "r", stdin);
	freopen((PROBLEM_NAME+".out").c_str(), "w", stdout);
	*/
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		parent[i] = i;
		height[i] = 0;
	}
}

