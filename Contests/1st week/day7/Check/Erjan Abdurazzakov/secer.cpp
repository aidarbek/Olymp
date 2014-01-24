
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

int n, col = 0;

int main() {
       #ifndef ONLINE_JUDGE
		freopen (taskname ".in", "r", stdin);
		freopen (taskname ".out", "w", stdout);
       #endif

       cin >> n;
       while (n >= 5)
       {
       	if (n - 5 >= 0) n -= 5;
       	col ++;
       }
       if (n % 3 != 0) cout << -1;
       else {
       	col ++;
       	cout << col;
       }

 return 0;
}

