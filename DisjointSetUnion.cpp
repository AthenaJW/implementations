#include <bits/stdc++.h>

using namespace std;

string PROBLEM_NAME = "time";

const int MAXN = 1000;

int N, M, C;
int parent[MAXN];
int height[MAXN]; //as another heuristic, we keep track of height of each graph and only add the shorter graph to the longer graph.
//this way we are only ever adding half or less of the whole in one operation -> O(logn)
int find(int node) //find the group this node belongs to
{
	if (parent[node] == node)
		parent[node] = find(parent[node]) //recursively search for parent until reaches root
	return root;//and update the node's parent to prevent having to travel that path again
}

void unit(int A, int B)
{
	int rootA = find(A);
	int rootB = find(B);
	if (height[rootA] > height[rootB])
	{
		father[rootB] = rootA;//add the smaller graph to the larger one
		height[rootA] = max(height[rootA], height[rootB]+1); //set the height to be either
	} //the height of the bigger tree or the height of the smaller tree +1 now that it gained a parent of rootA
	if (height[rootA] < height[rootB])
	{
		father[rootA] = rootB;
		height[rootB] = max(height[rootB], height[rootA]+1);
	}
}
// research says randomized linking gets the same complexity
// you can view the result here: https://www.cis.upenn.edu/~sanjeev/papers/soda14_disjoint_set_union.pdf
int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	/*freopen((PROBLEM_NAME+".in").c_str(), "r", stdin);
	freopen((PROBLEM_NAME+".out").c_str(), "w", stdout);
	*/
	cin >> N;
	for (int i = 0; i < N; i++) {
		parent[i] = i; //each node is initially it's own parent
		height[i] = 0; //the height of each group is initially 0
  }
}

