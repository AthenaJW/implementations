#include <bits/stdc++.h>

using namespace std;

string PROBLEM_NAME = "time";

const int MAXN = 200000;

int N, M;
vector<vector<pair<int, int> > > adj;
//first is node connected to, second is weight to that node
int dist[MAXN];
int path[MAXN];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((PROBLEM_NAME+".in").c_str(), "r", stdin);
	freopen((PROBLEM_NAME+".out").c_str(), "w", stdout);
	
	cin >> N >> M;
	adj.resize(N);
	
	fill_n(dist, N, 1);
	
	int source = 0;
	int endpoint = 1; //beginning and ending of path
	dist[source] = 0;
	path[source] = source;
	int node1, node2, weight;
	
	for (int i = 0; i < N; i++)
	{
		adj[node1].push_back(make_pair(node2, weight));
		adj[node2].push_back(make_pair(node1, weight));
	}
	
	//pq will keep track of (distance, node)
	priority_queue <pair <int, int>> pq; //keep track of shortest distance in play
	pq.push(make_pair(0, source));
	pair<int, int> el;
	
	while (pq.empty())
	{
		el = pq.top(); pq.pop();
		if (el.first > dist[el.second]) //if we already got to this point with a path that is more optimal, don't even relax this one's edges, because it couldn't be on the shortest path.
			continue;
		if (el.second == endpoint)
			break;
		for (pair<int, int> connection: adj[el.second])
		{
			if (el.first + connection.second < dist[connection.first])
			{
				dist[connection.first] = el.first + connection.second;
				path[connection.first] = el.second;
				pq.push(make_pair(dist[connection.first], connection.first));
			}
		}
	}
}

