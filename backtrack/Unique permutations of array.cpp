/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

Link : https://leetcode.com/problems/permutations-ii/
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

void unique_permutations(vector<int>& nums, vector<bool>& visited, vector<int>& permutation, vector<vector<int> >& ans)
{

	if (permutation.size() == nums.size())
	{
		ans.push_back(permutation);
		return;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		if (visited[i]) continue;
		if (i > 0 and nums[i] == nums[i - 1] and visited[i - 1]) continue;

		permutation.push_back(nums[i]);
		visited[i] = true;
		unique_permutations(nums, visited, permutation, ans);
		visited[i] = false;
		permutation.pop_back();

	}

}



void solve(int t)
{


	int n;
	cin >> n;
	vector<int> nums(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());
	vector<vector<int> > ans;
	vector<int> permutation;
	vector<bool> visited(nums.size(), 0);

	unique_permutations(nums, visited, permutation, ans);

	for (auto i : ans)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
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
