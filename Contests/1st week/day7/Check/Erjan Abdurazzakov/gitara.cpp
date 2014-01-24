
/*
ID: erjan193
LANG: C++
TASK:
*/

// In the name of God
// Abdurazzaq Yerzhan
#include <iostream>
#include <algorithm>
#include <cassert>
#include <string.h>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#define taskname "koki"
#define ll long long
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>


using namespace std;

int n, m, x, y, col;
set<int> b, e, u, t, be, a;

int main() {
       #ifndef ONLINE_JUDGE
		freopen (taskname ".in", "r", stdin);
		freopen (taskname ".out", "w", stdout);
       #endif

       scanf ("%d%d", &n, &m);
       for (int i = 1; i <= n; i ++)
       {
       	scanf ("%d%d", &x, &y);
       	if (x == 1)
       	{
       		if (b.empty()) b.insert(-y), col ++;
       		else
       		{
       			for (set<int> :: iterator it = b.begin(); it != b.end(); it ++)
       			{
       				int r = *it * (-1);
       				if (r > y) b.erase(it ++), col ++;
       				else break;
       			}
       			if (*b.begin() != -y)
       			b.insert(-y), col ++;
       		}
       }
       if (x == 2)
       	{
       		if (e.empty()) e.insert(-y), col ++;
       		else
       		{
       			for (set<int> :: iterator it = e.begin(); it != e.end(); it ++)
       			{
       				int r = *it * (-1);
       				if (r > y) e.erase(it ++), col ++;
       				else break;
       			}
       			e.insert(-y);
       		}
		}
		if (x == 3)
       	{
       		if (u.empty()) u.insert(-y), col ++;
       		else
       		{
       			for (set<int> :: iterator it = u.begin(); it != u.end(); it ++)
       			{
       				int r = *it * (-1);
       				if (r > y) u.erase(it ++), col ++;
       				else break;
       			}
       			u.insert(-y);
       		}
       }

		if (x == 4)
       	{
       		if (t.empty()) t.insert(-y), col ++;
       		else
       		{
       			for (set<int> :: iterator it = t.begin(); it != t.end(); it ++)
       			{
       				int r = *it * (-1);
       				if (r > y) t.erase(it ++), col ++;
       				else break;
       			}
       			t.insert(-y);
       		}
       }

		if (x == 5)
       	{
       		if (be.empty()) be.insert(-y), col ++;
       		else
       		{
       			for (set<int> :: iterator it = be.begin(); it != be.end(); it ++)
       			{
       				int r = *it * (-1);
       				if (r > y) be.erase(it ++), col ++;
       				else break;
       			}
       			be.insert(-y);
       		}
       }
       if (x == 6)
       	{
       		if (a.empty()) a.insert(-y), col ++;
       		else
       		{
       			for (set<int> :: iterator it = a.begin(); it != a.end(); it ++)
       			{
       				int r = *it * (-1);
       				if (r > y) a.erase(it ++), col ++;
       				else break;
       			}
       			a.insert(-y);
       		}
       }
       }
       cout << col << endl;


 return 0;
}

