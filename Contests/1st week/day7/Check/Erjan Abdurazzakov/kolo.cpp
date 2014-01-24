
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
#define taskname "koki"
#define ll long long
#define mp make_pair
#define F first
#define S second


using namespace std;

int n, m, l, x;
char a, b[1000];

int main() {
       #ifndef ONLINE_JUDGE
		freopen (taskname ".in", "r", stdin);
		freopen (taskname ".out", "w", stdout);
       #endif

       cin >> n >> m;
       for (int i = 1; i <= n; i ++) b[i] = ' ';
       for (int i = 1; i <= m; i ++)
       {
       	cin >> x >> a;
       	l += x;
       	if (l > n) l %= (n);
       	if (!l) l ++;
       	if (b[l] == ' ') b[l] = a;
       	else if (b[l] != ' ' && b[l] != a) 
       	{
       		cout << "!";
       		return 0;
       	}
       }
       for (int i = l; i >= 1; i --) 
       {
       	if (b[i] != ' ') cout << b[i];
       	else cout << "?";
       }
       for (int i = n; i > l; i --) 
       {
       	if (b[i] != ' ') cout << b[i];
       	else cout << "?";
       }


 return 0;
}

