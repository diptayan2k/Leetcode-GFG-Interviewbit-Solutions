// The rat can only move in Right and Down directions
// m[i][j] = 0 means the rat can't traverse these cells
// m[i][j] = 1 measn the rat can traverse these cells
// Print all possible paths to reach (n-1,n-1) from (0,0)

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
#define MAX 5


void rat_in_maze(int i, int j, string & path, vector<string>& ans, int m[MAX][MAX], int n)
{


	if (i == n - 1 and j == n - 1)
	{
		ans.push_back(path);
		return;
	}

	if (i < n - 1 and m[i + 1][j] == 1)
	{
		//cout << "HELLO" << endl;
		path[i + j] = 'D';
		rat_in_maze(i + 1, j, path, ans, m, n);
	}
	if (j < n - 1 and m[i][j + 1] == 1)
	{
		path[i + j] = 'R';
		rat_in_maze(i, j + 1, path, ans, m, n);
	}

	path[i + j] = '.';

}


void solve(int t)
{

	int n;
	cin >> n;
	int m[MAX][MAX];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> m[i][j];
		}
	}

	string path;
	for (int i = 0; i < 2 * (n - 1); i++) path += '.';
	vector<string> ans;
	if (m[0][0] == 1)
		rat_in_maze(0, 0, path, ans, m, n);

	if (ans.empty())
	{
		cout << -1 << endl;
		return;
	}

	for (auto i : ans)
	{
		cout << i << endl;
	}




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
	//cin >> t;



	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}
