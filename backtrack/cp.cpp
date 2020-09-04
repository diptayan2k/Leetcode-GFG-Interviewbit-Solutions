#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define lld long double
#define F first
#define S second
#define f(i,a,b) for(int i=a;i<=b;i++)
#define g(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue
#define bits(x) __builtin_popcountll(x)
#define op(x) cout<<"Case #"<<x<<": "
#define op1(x) cout<<"Scenario #"<<x<<": "
#define endl "\n"
using namespace std;
const ll mod = 1000000007;
const ll INF = LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;


bool m_coloring_problem(int node, vector<int> v[], vector<int>& color, int n, int m)
{
	if (node == n + 1)
	{
		return true;
	}


	bool res = false;
	map<int, int> fr;

	for (auto j : v[node])
	{
		fr[color[j]]++;
	}

	for (int i = 1; i <= m; i++)
	{
		if (fr[i] == 0)
		{
			color[node] = i;
			res |= m_coloring_problem(node + 1, v, color, n, m);
			color[node] = 0;
		}
	}


	return res;
}

void solve(int t)
{

	int n, m, e;
	cin >> n >> m >> e;
	vector<int> v[n + 1];

	for (int i = 0; i < e; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}

	vector<int> color(n + 1, 0);

	cout << m_coloring_problem(1, v, color, n, m) << endl;


}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int t = 1;
	cin >> t;



	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}