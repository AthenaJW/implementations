//wonderful resource: https://csacademy.com/lesson/fenwick_trees/
//bruh I love fenwick trees
#include <bits/stdc++.h>

using namespace std;

string PROBLEM_NAME = "time";

const int MAXN = 100000;
int ft[MAXN]; //a fenwick tree is simply the length of the array
int N;

int LSOne(int pos)
{
	return (pos&(-pos));
}//example: 00001010 & 11110110 = 00000010
//the added 1 from 2's complement will propagate over 1's in !i (which were originally zeroes in i)
//until it finds a 0 in !i (which would've been the least significant one in i)
//the LSOne gives the largest multiple of two the i is divisible by. (Every one after that represents 2^n times that multiple of 2)
//this is also the length of the interval as defined by the Fenwick Tree
int rsq(int pos)
{
	int sum = 0;
	for (; pos > 0; pos -= LSOne(pos))
		sum += ft[pos]; // we keep stripping off the LSOne to find the next interval down and add them
}
void update(int pos, int v)
{
	for (; pos < N; pos += LSOne(pos))
		ft[pos] += v;
}//This updates the current range, then moves to the next
//node that contains this range, the parent range
//why pos += LSOne(pos) moves us to the next range that contains this range?
//it goes to the node that has double our range, and we are contained within that range
int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	/*freopen((PROBLEM_NAME+".in").c_str(), "r", stdin);
	freopen((PROBLEM_NAME+".out").c_str(), "w", stdout);
	*/
	cin >> N;
	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		update(i, n);
	}//perhaps there is a more efficient way?
}

