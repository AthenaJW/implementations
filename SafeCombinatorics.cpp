#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using ll = long long;

string PROBLEM_NAME = "time";

const int MAXN = 10000;
const ll mod = 998244353;
ll factorials[MAXN];

void fact()
{
	factorials[0] = 1;
	for (int i = 1; i < sizeof(factorials)/sizeof(factorials); i++)
		factorials[i] = (factorials[i-1] * i) % mod;
}

ll binpow(ll b, ll p) //binary exponentiation
{
	ll res = 1;
	while (p > 0)
	{
		if ((p & 1) == 1)
			res *= b;
		res %= mod;
		p >>= 1;
		b = (b * b) % mod;
	}
	return res;
}

ll invMod(ll a) //fermat's little theorem
{
	return binpow(a, mod-2);
}

ll divMod(ll a, ll b) // modular division
{
	return (a * invMod(b))%mod;
}

ll multMod(ll a, ll b) // modular multiplication
{
	return (a*b) % mod;
}

ll powMod(ll b, ll p)
{
	ll ans = 1;
	for (; p > 0; p--)
	{
		ans *= b;
		ans %= mod;
	}
	return ans;
}

ll choose(ll n, ll k) //combinations
{
	return ((factorials[n]%mod)*invMod((factorials[n-k]*factorials[k])%mod))%mod;
}

int main () {
	
	ios_base::sync_with_stdio(0); cin.tie(0);
	/*freopen((PROBLEM_NAME+".in").c_str(), "r", stdin);
	freopen((PROBLEM_NAME+".out").c_str(), "w", stdout);
	*/
}
