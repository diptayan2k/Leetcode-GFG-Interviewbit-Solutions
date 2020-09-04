/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "snakesandladder",
dict = ["snake", "snakes", "and", "sand", "ladder"].

A solution is ["snakes and ladder",
           "snake sand ladder"].

Input:
The first line contains an integer T, denoting the number of test cases.
Every test case has 3 lines.
The first line contains an integer N, number of words in the dictionary.
The second line contains N strings denoting the words of the dictionary.
The third line contains a string s.

Output:
For each test case, print all possible strings in one line. Each string is enclosed in (). See Example.
If no string possible print "Empty" (without quotes).

Constraints:
1<=T<=100
1<=N<=20
1<=Length of each word in dictionary <=15
1<=Length of s<=1000
 

Note: Make sure the strings are sorted in your result.

Exapmle:
Input:
1
5
lr m lrm hcdar wk
hcdarlrm

Output:
(hcdar lr m)(hcdar lrm)

Link : https://practice.geeksforgeeks.org/problems/word-break-part-2/0
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



void word_break(int idx, int prev, string &s, unordered_map<string, int>& exist, vector<vector<string> > & ans, vector<string> & way, int &ok)
{
	if (idx == s.size())
	{
		if (exist[s.substr(prev, s.size() - prev)])
		{
			way.push_back(s.substr(prev, s.size() - prev));
			ans.push_back(way);
			way.pop_back();
		}
		return;
	}


	int res = 0;

	string current = s.substr(prev, idx - prev);
	if (exist[current])
	{
		way.push_back(current);
		word_break(idx + 1, idx, s, exist, ans, way, ok);
		way.pop_back();
	}

	word_break(idx + 1, prev, s, exist, ans, way, ok);

}

void solve(int t)
{


	vector<string>  wordDict;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string d;
		cin >> d;
		wordDict.push_back(d);
	}

	string s;
	cin >> s;

	unordered_map<string, int> exist;

	for (auto i : wordDict)
	{
		exist[i] = 1;
	}

	int sz = s.size();
	int ok = 0;
	vector<string> way;
	vector<vector<string> > ans;

	word_break(0, 0, s, exist, ans, way, ok);
	if (ans.empty())
	{
		cout << "Empty" << endl;
		return;
	}


	for (auto i : ans)
	{
		cout << "(";

		int k = 0;
		for (auto j : i)
		{
			k++;
			cout << j;
			if (k < i.size()) cout << " ";

		}
		cout << ")";
	}
	cout << endl;


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
