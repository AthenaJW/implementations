#include <bits/stdc++.h>

using namespace std;

string PROBLEM_NAME = "time";

const int MAXN = 100000;
int N, M;
vector<vector<pair<int, int> > > adj;
vector<int> dist;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((PROBLEM_NAME+".in").c_str(), "r", stdin);
	freopen((PROBLEM_NAME+".out").c_str(), "w", stdout);
	
	cin >> N >> M;
	int node, weight;
	vector<int> v;
	adj.push_back(v);
	for (int i = 0; i < N; i++)
	{
		cin >> node >> weight;
		
	}
	//pq will keep track of (distance, node)
	priority_queue<pair<int, int>> pq; //priority queue prioritizes first value of pair, then second
}

