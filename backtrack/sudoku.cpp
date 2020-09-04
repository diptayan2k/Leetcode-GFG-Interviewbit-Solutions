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



void sudoku(int r, int c, int row[], int col[], int reg[], int &ok, vector<vector<char>>& board)
{
	if (ok == 1) return;

	if (r == 9)
	{
		ok = 1;
		return;
	}



	int region = (r / 3) * 3 + (c / 3);
	if (board[r][c] == '.')
	{
		for (int i = 1; i <= 9; i++)
		{
			int d = (1 << i);
			if ((row[r]&d) == 0 and (col[c]&d) == 0 and (reg[region]&d) == 0)
			{
				board[r][c] = (char)('0' + i);
				row[r] |= d;
				col[c] |= d;
				reg[region] |= d;

				if (c < 8)
				{
					sudoku(r, c + 1, row, col, reg, ok, board);
				}
				else
				{
					sudoku(r + 1, 0, row, col, reg, ok, board);
				}

				if (ok == 0)
				{
					board[r][c] = '.';
					row[r] ^= d;
					col[c] ^= d;
					reg[region] ^= d;
				}
			}
		}
	}

	else
	{
		if (c < 8)
		{
			sudoku(r, c + 1, row, col, reg, ok, board);
		}
		else
		{
			sudoku(r + 1, 0, row, col, reg, ok, board);
		}

	}


}

void solve(int t)
{

	vector<vector<char>> board(9, vector<char>(9, '.'));

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
		}
	}

	int row[9] = {0}, col[9] = {0}, reg[9] = {0};

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == '.')
			{
				int region = (i / 3) * 3 + (j / 3);
				int num = board[i][j] - '0';
				int d = (1 << num);
				row[i] |= d;
				col[j] |= d;
				reg[region] |= d;
			}
		}

	}

	int ok = 0;
	sudoku(0, 0, row, col, reg, ok, board);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << board[i][j] << " ";
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
