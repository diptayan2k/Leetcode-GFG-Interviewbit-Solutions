/*
Consider a rat placed at (0, 0) in a square matrix of order N*N. It has to reach the destination at (N-1, N-1). 
Find all possible paths that the rat can take to reach from source to destination. The directions in which the 
rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it
 is blocked and cannot be crossed while value 1 at a cell in the matrix represents that it can be traveled through.

Link : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
*/

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


void rat_in_maze(int i, int j, vector<char>& path, vector<string>& ans, int m[MAX][MAX], int n, bool vis[MAX][MAX])
{


	if (i == n - 1 and j == n - 1)
	{
		string s;

		for (auto i : path) s += i;
		ans.push_back(s);
		return;
	}

	if (vis[i][j] == true)
	{
		return;
	}

	vis[i][j] = true;

	if (i < n - 1 and m[i + 1][j] == 1)
	{
		path.push_back('D');
		rat_in_maze(i + 1, j, path, ans, m, n, vis);
		path.pop_back();
	}
	if (j > 0 and m[i][j - 1] == 1)
	{
		path.push_back('L');
		rat_in_maze(i, j - 1, path, ans, m, n, vis);
		path.pop_back();
	}
	if (j < n - 1 and m[i][j + 1] == 1)
	{
		path.push_back('R');
		rat_in_maze(i, j + 1, path, ans, m, n, vis);
		path.pop_back();
	}
	if (i > 0 and m[i - 1][j] == 1)
	{
		path.push_back('U');
		rat_in_maze(i - 1, j, path, ans, m, n, vis);
		path.pop_back();
	}


	vis[i][j] = false;


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

	vector<char> path;
	bool vis[MAX][MAX];
	memset(vis, false, sizeof(vis));
	vector<string> ans;

	if (m[0][0] == 1)
		rat_in_maze(0, 0, path, ans, m, n, vis);

	
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
