#include <bits/stdc++.h>

using namespace std;

string PROBLEM_NAME = "milkvisits";

const int MAXN = 1000;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
typedef vector<vector <int> > vi;

#define mp make_pair
#define pb push_back
#define f first
#define s second

int N, M;

vpii traversal; //dfs preorder traversal and subtree size to do an ancestor lookup
vi adj[MAXN];  //a list of vectors
int type[MAXN]; //types of each farm
int anc_lookup[MAXN]; //node value -> order in dfs traversal
int depth[MAXN];
vi path; //stores the current path to the node
vpii path_type[MAXN]; //stores the types along the path to the node -> (node, type)
bool visited[MAXN]; //whether the nodes have been visited for the dfs
int queries[MAXN][2]; //stores node1 and node2 in the path
int C[MAXN]; //type for each query
vi todo[MAXN]; //for each node, stores the query ids of querys that involve that node
bool answer[MAXN];

//generates postprocess tree traversal array with sizes, array of depths
int preorder(int node, int d)
{
	int size = 1;
	visited[node] = true;
	traversal.pb(mp(node, 0));
	anc_lookup[node] = traversal.size()-1;
	for (int children: adj[node])
	{
		if (visited[children])
			continue;
		size += preorder(children, d + 1);
	}
	traversal[anc_lookup[node]].second = size;
	
	depth[node] = d;
	return size;
}

bool ancestor(int cand, int node)
{
	int pos1 = anc_lookup[cand];
	int pos2 = anc_lookup[node];
	return (pos1 + traversal[pos1].s > pos2) && pos2 >= pos1; //a node will be considered a ancestor of itself
}

int main () {
	/*ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((PROBLEM_NAME+".in").c_str(), "r", stdin);
	freopen((PROBLEM_NAME+".out").c_str(), "w", stdout);
	*/
	
}

