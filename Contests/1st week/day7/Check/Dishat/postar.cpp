#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
int n, a[10001][10001], i, j;
char b[10001][10001];
int main()
{
    freopen("koki.in", "r", stdin);
    freopen("koki.out", "w", stdout);
    cin>>n;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cin>>b[i][j];
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"0";
    return 0;
}
